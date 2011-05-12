/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 – 9:40	
 Student ID:             0345979
 Assignment #:           07
 Date Due:               6 November 2008
 Date Submitted:         6 November 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3,GCC 4.2.0, x86
 File Name:              main.cpp
*/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Seat {
	bool Sold;
	float Price;
};

typedef vector<Seat> Row;
	typedef vector<Seat>::iterator RowIterator;
typedef vector<Row> Auditorium;
	typedef vector<Row>::iterator AuditoriumIterator;

const int Rows=15;
const int Seats=30;/*per row*/

Auditorium Aud;

void print_auditorium();
void sell_seats();
void return_seats();

int main (int argc, char * const argv[]) {

	Aud=Auditorium(Rows);
	
	for(AuditoriumIterator ai=Aud.begin();
		ai!=Aud.end();
		ai++)
		(*ai)=Row(Seats);
	
	cout << "Auditorium has 15 rows of 30 seats." << endl;
	cout << "Please enter the price per seat for each row." << endl;
	
	float price_temp; int idx=0;
	for(AuditoriumIterator ai=Aud.begin();
		ai!=Aud.end();
		ai++, ++idx) {
		cout << "Row " << idx << " $";
		cin >> price_temp;
		
		for(RowIterator ri=(*ai).begin();
			ri!=(*ai).end();
			ri++)
			(*ri).Price=price_temp;
		
	}
	
	// loop
	// present menu (sell seats, return seats, display chart, and exit
	
	bool exit_now = false;
	
	do {
		
		cout << " Box office ready.  Please select an option:" << endl;
		int input;
		cout << " (1) Sell seats" << endl;
		cout << " (2) Return seats" << endl;
		cout << " (3) Display auditorium" << endl;
		cout << " (4) Quit" << endl;
		
		cin >> input;
		
		switch(input){
				
			case 1:
				sell_seats();
				break;
			case 2:
				return_seats();
				break;
			case 3:
				print_auditorium();
				break;
			case 4:
				exit_now = true;
				break;
			default:
				cout << " invalid input. try again." << endl;
				break;
				
		}
		
	} while ( exit_now != true ) ;
	
	char total_throwaway_stop_colliding_with_legitimate_variable_names;
    cout << "Press the any key to continue... " << endl;
	std::cin >> total_throwaway_stop_colliding_with_legitimate_variable_names;
	std::cout << "o7" << endl;
    return 0;
}

void sell_seats() {
	
	bool exit_now = false;
	
	do {
		
		char input[7];
		cout << "  Selling seats.  Please enter the seat to sell in Row,Column form." << endl;
		cout << "  You may type 'display' to display the auditorium." << endl;
		cout << "  You may also type 'quit' to return to the main menu." << endl;
		
		cin >> input;
		
		if ( strcmp(input, "display") == 0 ) {
			
			print_auditorium();
			
		} else if ( strcmp(input, "quit") == 0 ) {
			
			exit_now = true;
			
		} else {
			
			bool parses=true;
			// parse it.  two numbers, a comma, and two numbers.  anything else isn't good
			
			for(int i=0;i!=2;++i) {
				
				if(input[i]>'9'||input[i]<'0') {
					
					parses = false;
					
				}
				
			}
			
			if(input[2]!=',') {
				
				parses = false;
				
			}
			
			for(int i=3;i!=5;++i) {
				
				if(input[i]>'9'||input[i]<'0') {
					
					parses = false;
					
				}
				
			}
			
			if(parses!=true)
				
				continue;
			
			int row, aisle;
			
			row=(input[0]-'0')*10+(input[1]-'0');
			
			aisle=(input[3]-'0')*10+(input[4]-'0');
			
			Aud[aisle][row].Sold=true;
			
		}
		
		
		
	} while ( exit_now != true ) ;
	
}

void return_seats() {
	bool exit_now = false;
	
	do {
		
		char input[7];
		cout << "  Returning seats.  Please enter the seat to return in Row,Column form." << endl;
		cout << "  You may type 'display' to display the auditorium." << endl;
		cout << "  You may also type 'quit' to return to the main menu." << endl;
		
		cin >> input;
		
		if ( strcmp(input, "display") == 0 ) {
			
			print_auditorium();
			
		} else if ( strcmp(input, "quit") == 0 ) {
			
			exit_now = true;
			
		} else {
			
			bool parses=true;
			// parse it.  two numbers, a comma, and two numbers.  anything else isn't good
			
			for(int i=0;i!=2;++i) {
				
				if(input[i]>'9'||input[i]<'0') {
					
					parses = false;
					
				}
				
			}
			
			if(input[2]!=',') {
				
				parses = false;
				
			}
			
			for(int i=3;i!=5;++i) {
				
				if(input[i]>'9'||input[i]<'0') {
					
					parses = false;
					
				}
				
			}
			
			if(parses!=true)
				
				continue;
			
			int row, aisle;
			
			row=(input[0]-'0')*10+(input[1]-'0');
			
			aisle=(input[3]-'0')*10+(input[4]-'0');
			
			Aud[aisle][row].Sold=false;
			
		}
		
		
		
	} while ( exit_now != true ) ;
	
}

void print_auditorium() {
	/* block header_area */
	cout << "Row    Price   ";
	for(int i=0;i!=Seats;++i)
		cout << i%10;
	cout << "  Available   Sales" << endl;
	/* endblock */
	/* block information_area */
	float row_sales=0.00F;
	float total_sales=0.00F;
	int row_avail=0;
	int total_avail=0;
	int total_sold=0;
	for(int i=0;i!=Rows;++i){
		row_sales=0.00F;
		row_avail=0.00F;
		/* row */
		cout << i;
		if(i<10) 
			cout << "      $";
			else if(i<100)
				cout <<"     $";
				else 
					cout << "    $";
		/* price */
		cout.precision(2);
		cout << fixed << Aud[i][0].Price;
		if(Aud[i][0].Price<10)
			cout << "   ";
		else cout << "  ";
		/* occupancy */
		for(RowIterator ri=Aud[i].begin();
			ri!=Aud[i].end();
			ri++){
			if((*ri).Sold){
				total_sold++;
				row_sales+=(*ri).Price;
				cout << "*";
			} else {
				row_avail++;
				cout << "#";
			}
		}
		cout << "  " << row_avail;
		if(row_avail<10)
			cout << "         $";
		else 
			cout << "          $";
		total_avail+=row_avail;
		total_sales+=row_sales;
		cout << row_sales << endl;
	}
	/* endblock */
}

/*
 
 [Session started at 2008-11-06 02:26:47 -0800.]
 Auditorium has 15 rows of 30 seats.
 Please enter the price per seat for each row.
 Row 0 $40
 Row 1 $35
 Row 2 $30
 Row 3 $25
 Row 4 $20
 Row 5 $15
 Row 6 $10
 Row 7 $9
 Row 8 $8
 Row 9 $7
 Row 10 $6
 Row 11 $5
 Row 12 $5
 Row 13 $5
 Row 14 $5
 Box office ready.  Please select an option:
 (1) Sell seats
 (2) Return seats
 (3) Display auditorium
 (4) Quit
 3
 Row    Price   012345678901234567890123456789  Available   Sales
 0      $40.00  ##############################  30          $0.00
 1      $35.00  ##############################  30          $0.00
 2      $30.00  ##############################  30          $0.00
 3      $25.00  ##############################  30          $0.00
 4      $20.00  ##############################  30          $0.00
 5      $15.00  ##############################  30          $0.00
 6      $10.00  ##############################  30          $0.00
 7      $9.00   ##############################  30          $0.00
 8      $8.00   ##############################  30          $0.00
 9      $7.00   ##############################  30          $0.00
 10     $6.00   ##############################  30          $0.00
 11     $5.00   ##############################  30          $0.00
 12     $5.00   ##############################  30          $0.00
 13     $5.00   ##############################  30          $0.00
 14     $5.00   ##############################  30          $0.00
 Box office ready.  Please select an option:
 (1) Sell seats
 (2) Return seats
 (3) Display auditorium
 (4) Quit
 1
 Selling seats.  Please enter the seat to sell in Row,Column form.
 You may type 'display' to display the auditorium.
 You may also type 'quit' to return to the main menu.
 00,00
 Selling seats.  Please enter the seat to sell in Row,Column form.
 You may type 'display' to display the auditorium.
 You may also type 'quit' to return to the main menu.
 00,01
 Selling seats.  Please enter the seat to sell in Row,Column form.
 You may type 'display' to display the auditorium.
 You may also type 'quit' to return to the main menu.
 00,02
 Selling seats.  Please enter the seat to sell in Row,Column form.
 You may type 'display' to display the auditorium.
 You may also type 'quit' to return to the main menu.
 display
 Row    Price   012345678901234567890123456789  Available   Sales
 0      $40.00  *#############################  29          $40.00
 1      $35.00  *#############################  29          $35.00
 2      $30.00  *#############################  29          $30.00
 3      $25.00  ##############################  30          $0.00
 4      $20.00  ##############################  30          $0.00
 5      $15.00  ##############################  30          $0.00
 6      $10.00  ##############################  30          $0.00
 7      $9.00   ##############################  30          $0.00
 8      $8.00   ##############################  30          $0.00
 9      $7.00   ##############################  30          $0.00
 10     $6.00   ##############################  30          $0.00
 11     $5.00   ##############################  30          $0.00
 12     $5.00   ##############################  30          $0.00
 13     $5.00   ##############################  30          $0.00
 14     $5.00   ##############################  30          $0.00
 Selling seats.  Please enter the seat to sell in Row,Column form.
 You may type 'display' to display the auditorium.
 You may also type 'quit' to return to the main menu.
 quit
 Box office ready.  Please select an option:
 (1) Sell seats
 (2) Return seats
 (3) Display auditorium
 (4) Quit
 2
 Returning seats.  Please enter the seat to return in Row,Column form.
 You may type 'display' to display the auditorium.
 You may also type 'quit' to return to the main menu.
 00,00
 Returning seats.  Please enter the seat to return in Row,Column form.
 You may type 'display' to display the auditorium.
 You may also type 'quit' to return to the main menu.
 quit
 Box office ready.  Please select an option:
 (1) Sell seats
 (2) Return seats
 (3) Display auditorium
 (4) Quit
 3
 Row    Price   012345678901234567890123456789  Available   Sales
 0      $40.00  ##############################  30          $0.00
 1      $35.00  *#############################  29          $35.00
 2      $30.00  *#############################  29          $30.00
 3      $25.00  ##############################  30          $0.00
 4      $20.00  ##############################  30          $0.00
 5      $15.00  ##############################  30          $0.00
 6      $10.00  ##############################  30          $0.00
 7      $9.00   ##############################  30          $0.00
 8      $8.00   ##############################  30          $0.00
 9      $7.00   ##############################  30          $0.00
 10     $6.00   ##############################  30          $0.00
 11     $5.00   ##############################  30          $0.00
 12     $5.00   ##############################  30          $0.00
 13     $5.00   ##############################  30          $0.00
 14     $5.00   ##############################  30          $0.00
 Box office ready.  Please select an option:
 (1) Sell seats
 (2) Return seats
 (3) Display auditorium
 (4) Quit
 4
 Press the any key to continue... 
 
 foo
 o7
 
 The Debugger has exited with status 0.
*/
