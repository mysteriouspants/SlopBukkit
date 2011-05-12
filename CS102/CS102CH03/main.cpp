/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 – 9:40	
 Student ID:             0345979
 Assignment #:           03
 Date Due:               25 September 2008
 Date Submitted:         22 September 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3, GCC 4.0.1, x86
 File Name:              main.cpp
 */
#include <iostream>
#include <fstream>

#include <cstdlib>
#include <cmath>

using namespace std;

// reset output settings
void resetOutput();

int main (int argc, char * const argv[]) {
	
	/*
	 Display the floating point number 34.789 
	 In a field of 9 spaces with 3 decimal places of precision.
	 In a field of 6 spaces with 2 decimal places of precision.
	 In a field of 3 spaces with 1 decimal place of precision.
	*/
	cout<<fixed<<right;
	for(int i=9;i!=0;i-=3){
		cout.width(i);
		cout << cout.precision(
				(static_cast<int>(static_cast<float>(i)/3.0F)==0)?
				   1:static_cast<int>(static_cast<float>(i)/3)
							   ) ; cout << 34.789F << endl;
	}
	resetOutput();
	cout << endl;
	
	/*
	 Display the integer 64
	 In decimal format in a field of 8 spaces with a plus sign
	 In octal format left justified in a field of 6 spaces
	 In hexadecimal format right justified in a field of 4 spaces
	*/
	for(int i=8;i!=2;i-=2){
		cout.width(i);
		if(i==6) cout << right << oct;
		else cout << left << hex;
		if(i==8) cout << showpos << dec;
		cout << 64 << endl;
	}
	resetOutput();
	cout << endl;
	
	/*
	 Display the number 1897462.60917 in E notation. 
	 With 6 decimal places of precision.
	 With 4 decimal places of precision.
	 With 2 decimal places of precision.
	 The E should be capitalized in all displays.
	*/
	cout << uppercase << scientific;
	for(int i=6;i!=0;i-=2){
		cout.precision(i);
		cout << 1897462.60917F << endl;
	}
	resetOutput();
	cout << endl;
	 
	/*
	 Create a text file with the following numbers on separate lines: 18, 12, 6, 2
	*/ // actually works on Windows, Mac, and Linux!  A real plus!
	system("echo \"18\n12\n6\n2\n\" > textfile.txt");
	
	/*
	 Open the text file with your program and read the values into the following integer variables
	 Value1, Value2, Value3, Value4
	*/
	ifstream TextFile; int Value1, Value2, Value3, Value4;
	TextFile.open("textfile.txt", ios::in);
	TextFile >> Value1 >> Value2 >> Value3 >> Value4;
	TextFile.close();
	
	/*
	 Evaluate the following arithmetic expressions and display the results to the monitor 
	 Result = Value1 * (Value 2 + Value 3)
	 Result =		Result 		
	 Value3 –Value 4
	 Result = Result + Value1
	 Result = Result^2
	 Use a string constant to describe each display
	 (i.e. cout << Result <<" = " << Value1 
	 <<" * (" Value2 <<" + " << Value3 << ")";
	*/
	cout << Value1 << " * (" << Value2 << " + " << Value3 << ") = "
		<< Value1 * (Value2 + Value3) << endl;
	cout << Value3 << " - " << Value4 << " = " << Value3-Value4 << endl;
	cout << "(" << Value1 << " * (" << Value2 << " + " << Value3
		<< ")) + " << Value1 << " = " << (Value1 * (Value2 + Value3)) + Value1 << endl;
	cout << "{[" << Value1 << " * (" << Value2 << " + " << Value3 << ")] + "
		<< Value1 << "}^2 = " << static_cast<int>(pow(
		static_cast<long double>((Value1 * (Value2 + Value3)) + Value1),
		static_cast<long double>(2))) << endl;
	cout << endl;
	
	/*
	 Part C  - Reading character strings
	 Declare a character string variable that will hold 20 characters including the null character.
	 Using this variable:
	 Read in, and then display a string with no embedded spaces.
	 Read in, and then display a string with embedded spaces.
	*/
	char sz[20];
	cout << "Please enter some text: "; cin >> sz;
	cout << "You entered: " << sz << endl;
	cin.ignore(65535, '\n');// gets rid of all the extra text 
	cout << "Please enter some more text: "; cin.getline(sz, 20);
	cout << "You entered: " << sz << endl;

	/*
	 Read in a string that contains only the enter key.
	 Requirements:
	 Provide both the source code and the runtime output.
	 Use comments to document your code.
	 Prompt the user for the desired input.
	 Use white space and text to make your output readable.
	*/
	// amazingly enough, this is actually working to simulate the system("PAUSE")
	// functionality on my compiler.  Go figure.
	char throwaway;
	std::cout << "Press the any key to continue.";
	std::cin.get(throwaway);
    return 0;
}

void resetOutput() {
	cout.flags( ios::left | ios::dec );
	cout.precision(6);
	cout.width(0);
}

/*
 [Session started at 2008-09-22 10:48:42 -0700.]
 634.789
 334.79
 234.8
 
 +64     
 100
 40  
 
 1.897463E+06
 1.8975E+06
 1.90E+06
 
 18 * (12 + 6) = 324
 6 - 2 = 4
 (18 * (12 + 6)) + 18 = 342
 {[18 * (12 + 6)] + 18}^2 = 116964
 
 Please enter some text: foo bar
 You entered: foo
 Please enter some more text: foo bar
 You entered: foo bar
 Press the any key to continue.
 
 The Debugger has exited with status 0.
 [Session started at 2008-09-22 10:49:22 -0700.]
 634.789
 334.79
 234.8
 
 +64     
 100
 40  
 
 1.897463E+06
 1.8975E+06
 1.90E+06
 
 18 * (12 + 6) = 324
 6 - 2 = 4
 (18 * (12 + 6)) + 18 = 342
 {[18 * (12 + 6)] + 18}^2 = 116964
 
 Please enter some text: foo bar baaz trying to get more than 20 characters
 You entered: foo
 Please enter some more text: foo bar baaz trying to get more than 20 characters
 You entered: foo bar baaz trying
 Press the any key to continue.
 The Debugger has exited with status 0.
*/

