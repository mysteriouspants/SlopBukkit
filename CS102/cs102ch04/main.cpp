/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 – 9:40	
 Student ID:             0345979
 Assignment #:           4
 Date Due:               2 October 2008
 Date Submitted:         1 October 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3, GCC 4.2.0, x86
 File Name:              main.cpp
 */
#include <iostream>
#include <cmath>

using namespace std;

int main (int argc, char * const argv[]) {
	
	int RatesLength=4;
	// note: output not tested for values in the hundreds!  may destroy table alignment!
	float Rates[4][3] = {
		//  Lower weight    price per 500 miles
		//          upper weight
		{	0.0F,	2.0F,	1.10F	},
		{	2.0F,	6.0F,	2.20F	},
		{	6.0F,	10.0F,	3.70F	},
		{	10.0F,	20.0F,	4.80F	}
	};
	const float MinShipDist=10.00F;
	const float MaxShipDist=3000.00F;
	const float MaxShipMass=20.00F;
	const float MinShipMass=0.00F;
	float givenMass, givenDistance;
	
    cout << "          Fast Freight Shipping Co. Rates" << endl;
	cout << "/------------------------+----------------------------\\" << endl
		 << "| Weight of Package (Kg) | Rate per 500 Miles Shipped |" << endl
	;
	
	cout << fixed;
	for(int i=0;i<RatesLength;++i){
		cout << "+------------------------+----------------------------+" << endl;
		
		cout << "| "; cout.width(7); cout.precision(2);
		cout << right << Rates[i][0] << " - " << Rates[i][1];
		if(Rates[i][1]>=10.00F) cout << " kg     "; else cout <<" kg      ";
		
		cout << "|          $"; cout << Rates[i][2]; cout.precision(1); cout.width(0);
		if(Rates[i][2]>=10.00F) cout << "            |"; else cout << "             |";
		cout << endl;
	}
	cout << "\\------------------------+----------------------------/" << endl;
	
	cout << endl; cout.precision(2);
	cout << "          Fast Frieght Shipping Co. Rules" << endl;
	cout << " * Minimum Shipping Distance:\t" << MinShipDist << " miles" << endl;
	cout << " * Maximum Shipping Distance:\t" << MaxShipDist << " miles" << endl;
	cout << " * Minimum Shipping Weight:  \t" << MinShipMass << " Kg" << endl;
	cout << " * Maximum Shipping Weight:  \t" << MaxShipMass << " Kg" << endl;
	
	cout << endl;
	cout << "Please enter the weight of the package\r\nyou wish to ship, in kilograms: ";
	cout << "      Kg\b\b\b\b\b\b\b\b\a"; cin >> givenMass;
	if(givenMass>MaxShipMass){
		cout << endl << endl << "\a\a\t Sorry, your package exceeds the maximum mass of "
			<< MaxShipMass << "Kg!" << endl;
		return 0;
	} else if(givenMass<=MinShipMass) {
		cout << endl << endl << "\a\a\t Sorry, your package is less than the mimimum mass of "
			<< MinShipMass << "Kg!" << endl;
		return 0;
	}
	
	cout << endl;
	cout << "Please enter the distance for your\r\npackage to be shipped, in miles: ";
	cout << "        miles\b\b\b\b\b\b\b\b\b\b\b\b\b\a"; cin >> givenDistance;
	if(givenDistance>MaxShipDist){
		cout << endl << endl << "\a\a\t Sorry, your shipping distance exceeds the maximum of "
			<< MaxShipDist << " miles!" << endl;
		return 0;
	} else if(givenDistance<=MinShipDist){
		cout << endl << endl << "\a\a\t Sorry, your shipping distance is less than the minimum"
			<< "\t distance of " << MinShipDist << " miles!" << endl;
		return 0;
	}
	
	for(int i=0;i!=RatesLength;++i){
		if(givenMass>=Rates[i][0]&&givenMass<=Rates[i][1]){
			cout << "Your shipping charge is $";
			if(givenDistance<500.0F){
				cout << Rates[i][2]*1.00F;
			} else {
				cout << Rates[i][2]*static_cast<float>(givenDistance/500.0F);
			}
			cout << endl;
			break;
		} else if(i==RatesLength-1){
			cout << "\aThis is an internal error.  Your input is valid, but does not match\r\n"
				<< "any measurement in the internal rates table.  Please check for local\r\n"
				<< "quantum anomalies." << endl;
		}
	}
	
	char foo;
	cout << "Press the any key to continue... " << endl;
	std::cin.get(foo);
    return 0;
}
/*
 Fast Freight Shipping Co. Rates
 /------------------------+----------------------------\
 | Weight of Package (Kg) | Rate per 500 Miles Shipped |
 +------------------------+----------------------------+
 |    0.00 - 2.00 kg      |          $1.10             |
 +------------------------+----------------------------+
 |    2.00 - 6.00 kg      |          $2.20             |
 +------------------------+----------------------------+
 |    6.00 - 10.00 kg     |          $3.70             |
 +------------------------+----------------------------+
 |   10.00 - 20.00 kg     |          $4.80             |
 \------------------------+----------------------------/
 
 Fast Frieght Shipping Co. Rules
 * Minimum Shipping Distance:	10.00 miles
 * Maximum Shipping Distance:	3000.00 miles
 * Minimum Shipping Weight:  	0.00 Kg
 * Maximum Shipping Weight:  	20.00 Kg
 
 Please enter the weight of the package
 you wish to ship, in kilograms: 12.38 Kg
 
 Please enter the distance for your
 package to be shipped, in miles: 10.0001 miles
 Your shipping charge is $4.80
 Press the any key to continue... 
 
 Fast Freight Shipping Co. Rates
 /------------------------+----------------------------\
 | Weight of Package (Kg) | Rate per 500 Miles Shipped |
 +------------------------+----------------------------+
 |    0.00 - 2.00 kg      |          $1.10             |
 +------------------------+----------------------------+
 |    2.00 - 6.00 kg      |          $2.20             |
 +------------------------+----------------------------+
 |    6.00 - 10.00 kg     |          $3.70             |
 +------------------------+----------------------------+
 |   10.00 - 20.00 kg     |          $4.80             |
 \------------------------+----------------------------/
 
 Fast Frieght Shipping Co. Rules
 * Minimum Shipping Distance:	10.00 miles
 * Maximum Shipping Distance:	3000.00 miles
 * Minimum Shipping Weight:  	0.00 Kg
 * Maximum Shipping Weight:  	20.00 Kg
 
 Please enter the weight of the package
 you wish to ship, in kilograms: 19.99 Kg
 
 Please enter the distance for your
 package to be shipped, in miles: 2999.99 miles
 Your shipping charge is $28.80
 Press the any key to continue... 

 Fast Freight Shipping Co. Rates
 /------------------------+----------------------------\
 | Weight of Package (Kg) | Rate per 500 Miles Shipped |
 +------------------------+----------------------------+
 |    0.00 - 2.00 kg      |          $1.10             |
 +------------------------+----------------------------+
 |    2.00 - 6.00 kg      |          $2.20             |
 +------------------------+----------------------------+
 |    6.00 - 10.00 kg     |          $3.70             |
 +------------------------+----------------------------+
 |   10.00 - 20.00 kg     |          $4.80             |
 \------------------------+----------------------------/
 
 Fast Frieght Shipping Co. Rules
 * Minimum Shipping Distance:	10.00 miles
 * Maximum Shipping Distance:	3000.00 miles
 * Minimum Shipping Weight:  	0.00 Kg
 * Maximum Shipping Weight:  	20.00 Kg
 
 Please enter the weight of the package
 you wish to ship, in kilograms: -2    Kg
 
 
 Sorry, your package is less than the mimimum mass of 0.00Kg!

 Fast Freight Shipping Co. Rates
 /------------------------+----------------------------\
 | Weight of Package (Kg) | Rate per 500 Miles Shipped |
 +------------------------+----------------------------+
 |    0.00 - 2.00 kg      |          $1.10             |
 +------------------------+----------------------------+
 |    2.00 - 6.00 kg      |          $2.20             |
 +------------------------+----------------------------+
 |    6.00 - 10.00 kg     |          $3.70             |
 +------------------------+----------------------------+
 |   10.00 - 20.00 kg     |          $4.80             |
 \------------------------+----------------------------/
 
 Fast Frieght Shipping Co. Rules
 * Minimum Shipping Distance:	10.00 miles
 * Maximum Shipping Distance:	3000.00 miles
 * Minimum Shipping Weight:  	0.00 Kg
 * Maximum Shipping Weight:  	20.00 Kg
 
 Please enter the weight of the package
 you wish to ship, in kilograms: 2     Kg
 
 Please enter the distance for your
 package to be shipped, in miles: 5       miles
 
 
 Sorry, your shipping distance is less than the minimum	 distance of 10.00 miles!
 
*/
