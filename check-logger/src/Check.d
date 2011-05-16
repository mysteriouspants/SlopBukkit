module Check;

import Float = tango.text.convert.Float,
	   Integer = tango.text.convert.Integer,
	   Util = tango.text.Util,
	   Fields;

struct Check {
	int number;			char[] date;
	int checkNo;		char[] descr;
	float debit;		float credit;
	float balance;
	
	static Check parse(char[] str) {
		Check new_check;
		char cut[][]=Util.split(str, ",");
		if(cut.length!=7)
			throw new Exception("whoops, malformed CSV file!");
		new_check.number=Integer.parse(cut[Fields.FIELDS.NUMBER]);
		new_check.date=cut[FIELDS.DATE];
		new_check.checkNo=Integer.parse(cut[FIELDS.CHECKNO]);
		new_check.descr=cut[FIELDS.DESCR];
		//new_check.code=cut[FIELDS.CODE];
		new_check.debit=Float.parse(cut[FIELDS.DEBIT]);
		new_check.credit=Float.parse(cut[FIELDS.CREDIT]);
		new_check.balance=Float.parse(cut[FIELDS.BALANCE]);
		return new_check;
	}
	
	char[] toCsvString() {
		char[] str;
		str~=Integer.toString(number)~","~date~','~Integer.toString(checkNo)
			~","~descr~","//~code~","
			~Float.toString(debit)~","~Float.toString(credit)
			~","~Float.toString(balance);
		return str;
	}
	
	int opCmp(Check c) {
		return this.number-c.number;
	}
	
}
