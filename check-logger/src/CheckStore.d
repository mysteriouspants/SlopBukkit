module CheckStore;

import tango.io.Stdout;

import tango.io.stream.LineStream,
	   tango.io.FileConduit,
	   tango.io.DeviceConduit;

import Check;

class CheckStore { // singleton pattern
	static CheckStore store;
	
	static CheckStore getStore() {
		return store;
	}
	
	static void initStore(char[] CSVFile) {
		store=new CheckStore(CSVFile);
	}
	
	Check[] allChecks;
	
	FileConduit file;
	
	this(char[] CSVFile) {
		allChecks=[];
		file=new FileConduit(CSVFile, FileConduit.ReadWriteOpen);
		//scope(exit)file.close();
		// ensure that there is a newline at the end of the file
		file.seek(-2, FileConduit.Anchor.End);
		auto stuff=new char[2];file.input.read(stuff);
		if(stuff[0]!=13) {
			file.seek(-1, FileConduit.Anchor.End);
			file.output.write("\n");
		} // fixes one of the weirdest errors where it dies if there isn't a
		// newline at the end of the file.
		file.seek(0, FileConduit.Anchor.Begin);
		//Stdout(stuff).newline;
		LineInput lines=new LineInput(file.input);
		foreach(char[] line; lines) {
			if(isValidLine(line))
				allChecks~=Check.Check.parse(line);
		}
		
	}
	
	void writeToFile() {
		if(file) {
			file.seek(0);
			foreach(Check ch; allChecks) {
				file.output().write(ch.toCsvString()~"\n");
			}
			//file.output().write("\0");
		}
	}

	bool isValidLine(char[] line) {
		return count(line, ',')==6;
	}
	
	int count(char[] text, char character) {
		int num;
		foreach(char ch; text)
			if(ch==character)
				num++;
		return num;
	}
	
	float getRunningBalance() {
		float balance=0.00;
		foreach(Check ch; allChecks) {
			balance+=ch.credit;
			balance-=ch.debit;
		}
		return balance;
	}
	
}