/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 – 9:40	
 Student ID:             0345979
 Assignment #:           6
 Date Due:               16 October 2008
 Date Submitted:         12 October 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3,GCC 4.0.0, x86
 File Name:              main.cpp
*/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "Item.h"
#include "Cart.h"

Cart *active_cart;

void lsitems();
void itemcat(vector<Item>::iterator iter, bool prefix=false);

int main (int argc, char * const argv[]) {
	
	cout << "\t\tRetail Inventory and Checkout Terminal\r\n";
	char input[500];
    do {
		cout << ">>> "; cin.getline(input,500);// >> input;
		
		for(int i=0;i!=500;++i)
			if(input[i]>='A'&&input[i]<='Z')
				input[i]+='a'-'A';
		
		if(strcmp(input,"exit")==0) {
			cout << "bye!" << endl;
			return 0;
		} else if(strcmp(input,"help")==0) {
			cout << "Available commands:" << endl;
/*done*/	cout << "  exit:     terminates the program." << endl;
/*done*/	cout << "  newcart:  creates a new cart." << endl;
/*done*/	cout << "  killcart: maliciously murders the active cart." << endl;
/*done*/	cout << "  additem:  adds a new item to the active cart." << endl;
/*done*/	cout << "  killitem: maliciously murders an item in the active cart." << endl;
/*done*/	cout << "  lsitems:  lists all items in the active cart." << endl;
/*done*/	cout << "  itemcat:  lists the specific information about an item." << endl;
			cout << "  edititem: invasively mangles an items inner identity." << endl;
/*done*/	cout << "  checkout: shows the totals for the active cart and then calls killcart." << endl;
			
			cout << endl << "This version of apt-get is equipped with super-cow powers." << endl;
		} else if(strcmp(input,"newcart")==0) {
			active_cart = new Cart();
			cout << "created new cart just for you!" << endl;
		} else if(strcmp(input,"killcart")==0) {
			if(active_cart) {
				delete active_cart;
				cout << "I'm in your shopping mall, killing your carts!" << endl;
			}
			else
				cout << "idiot, you haven't got a cart to viciously murder!" << endl;
		} else if(strcmp(input,"additem")==0) {
			if(active_cart==NULL) {
				cout << "idiot, you haven't got a cart to malevolently add items too!" << endl;
				continue;
			}
			
			Item item;
			cout << "Enter the name of the item     ";
			item.Name=new char[50];
			cin.getline(item.Name, 50);
			
			cout << "Enter the price of the item   $";
			cin >> item.Price;
			
			cout << "Enter the quantity purchased   ";
			cin >> item.Quantity;
			
			cout << "Enter the discount in percent %";
			cin >> item.Discount;
			
			cout << "Is this item taxable? (y/n)    ";
			bool go_away=false;
			do {
				char in[5];
				cin.getline(in,4);// in;
				if(strcmp(in,"y")==0) {
					item.Taxable=true;
					go_away=true;
				} else if(strcmp(in,"n")==0) {
					item.Taxable=false;
					go_away=true;
				}
			} while ( go_away==false ) ;

			active_cart->Contents.push_back(item);
		} else if(strcmp(input,"killitem")==0) {
			cout << "Please pick an item to brutally murder!" << endl;
			lsitems();
			int todie;
			cout << "Which doest thou prick?"; cin >> todie;
			if(todie<0||todie>active_cart->Contents.size()) {
				cout << "  \aSorry chump, that item exists only in you brain." << endl;
			} else {
				active_cart->Contents.erase(active_cart->Contents.begin()+todie);
				cout << "That item has been murdered, and the body is now in the east river Don." << endl;
			}
		} else if(strcmp(input,"lsitems")==0) {
			lsitems();
		} else if(strcmp(input,"edititem")==0) {
			// write me!
			cout << "Which item do you want to edit? " << endl;
			lsitems();
			int in; cin >> in;
			if(in<0||in>active_cart->Contents.size()) {
				cout << "  \aSorry chump, that item exists only in your brain." << endl;
			} else {
				vector<Item>::iterator iter=active_cart->Contents.begin()+in;
				bool vamanos=false, endloop;
				do {
					itemcat(iter,true);
					cout << "Which attribute do you want to modify? " << endl;
					cin >> in;
					switch (in) {
						case 1: // name
							cout << "Enter new name: ";
							cin.getline((*iter).Name, sizeof((*iter).Name)/sizeof(char));
							break;
						case 2: // price
							cout << "Enter the new price: $";
							cin >> (*iter).Price;
							break;
						case 3: // quantity
							cout << "Enter new quantity: ";
							cin >> (*iter).Quantity;
							break;
						case 4: // taxable
							cout << "Is this item taxable? (y/n)    ";
							endloop=false;
							do {
								char in[5];
								cin.getline(in,4);// in;
								if(strcmp(in,"y")==0) {
									(*iter).Taxable=true;
									endloop=true;
								} else if(strcmp(in,"n")==0) {
									(*iter).Taxable=false;
									endloop=true;
								}
							} while ( endloop==false ) ;
							break;
						case 5: // discount
							cout << "Enter new discount percentage: %";
							cin >> (*iter).Discount;
							break;
						case 6: // exit
							vamanos=true;
							break;
						default:
							cout << "Unrecognized attribute.  Please try again." << endl;
					}
				} while ( vamanos==false ) ;
				continue;
			}
		} else if(strcmp(input,"checkout")==0) {
			cout.precision(2); cout << fixed;
			cout << "Your total is $" << active_cart->getTotal() << " thanks for your business and come back really soon!" << endl;
			cout.precision(0);
			delete active_cart;
		} else if(strcmp(input,"itemcat")==0) {
			cout << "Select an item to view." << endl;
			lsitems();
			cout << "Which item do you want to view? ";
			int in; cin >> in;
			if(in<0||in>active_cart->Contents.size()) {
				cout << "  \aSorry chump, that item exists only in your brain." << endl;
			} else {
				itemcat(active_cart->Contents.begin()+in);
			}
			continue;
		} else {
			cout << "\a\aEVIL CHICKENS ARE ASSAULTING MY FACE!!!\a\a" << endl;
			cout <<     "    ehrm, actually, you inputted a" << endl;
			cout <<     "  command I don't recognise. try again." << endl;
			cout <<     " if you're totally lost in space and" << endl;
			cout <<     " left to contemplate the viscicitudes" << endl;
			cout <<     "  of walrus squeezing, try the almighty" << endl;
			cout <<     "               HELP" << endl;
			cout <<     "         command OF DOOM!!!" << endl;
		}
		
	} while ( true ) ;
	
    return 0;
}

void lsitems() {
	if(active_cart->Contents.size()==0) {
		cout << "   \aNo Items in Cart!" << endl;
	}
	vector<Item>::iterator iter=active_cart->Contents.begin();
	for(int i=0;
		iter!=active_cart->Contents.end();++i,++iter) {
		cout << "   " << i << ":  " << (*iter).Quantity << "x " << (*iter).Name << endl;
	}
}

void itemcat(vector<Item>::iterator iter, bool prefix) {
	cout << ((prefix)?"  (1) Name: ":"") << (*iter).Name << endl;
	cout << "  " << ((prefix)?"(2) ":"") << "Price:    $" << (*iter).Price << endl;
	cout << "  " << ((prefix)?"(3) ":"") << "Quantity:  " << (*iter).Quantity << endl;
	cout << "  " << ((prefix)?"(4) ":"") << "Taxable:   " << (((*iter).Taxable)?"Born Free, Taxed to Death":"Unpatriotic") << endl;
	cout << "  " << ((prefix)?"(5) ":"") << "Discount: %" << (*iter).Discount << endl;
	if(prefix) cout << "  (6) exit" << endl;
}

/*
 [Session started at 2008-10-12 22:14:56 -0700.]
 Retail Inventory and Checkout Terminal
 >>> newcart
 created new cart just for you!
 >>> additem
 Enter the name of the item     Semiautomatic Picnic Ants
 Enter the price of the item   $5.00
 Enter the quantity purchased   30
 Enter the discount in percent %20
 Is this item taxable? (y/n)    n
 >>> additem
 Enter the name of the item     Substandard Bread
 Enter the price of the item   $3.00
 Enter the quantity purchased   2
 Enter the discount in percent %0
 Is this item taxable? (y/n)    y
 >>> additem
 Enter the name of the item     Bloated Cow Intestine with Synthetic Breading
 Enter the price of the item   $30.00
 Enter the quantity purchased   1
 Enter the discount in percent %10
 Is this item taxable? (y/n)    y
 >>> lsitems
 0:  30x Semiautomatic Picnic Ants
 1:  2x Substandard Bread
 2:  1x Bloated Cow Intestine with Synthetic Breading
 >>> itemcat
 Select an item to view.
 0:  30x Semiautomatic Picnic Ants
 1:  2x Substandard Bread
 2:  1x Bloated Cow Intestine with Synthetic Breading
 Which item do you want to view? 2
 Bloated Cow Intestine with Synthetic Breading
 Price:    $30
 Quantity:  1
 Taxable:   Born Free, Taxed to Death
 Discount: %10
 >>> EVIL CHICKENS ARE ASSAULTING MY FACE!!!
 ehrm, actually, you inputted a
 command I don't recognise. try again.
 if you're totally lost in space and
 left to contemplate the viscicitudes
 of walrus squeezing, try the almighty
 HELP
 command OF DOOM!!!
 >>> edititme
 EVIL CHICKENS ARE ASSAULTING MY FACE!!!
 ehrm, actually, you inputted a
 command I don't recognise. try again.
 if you're totally lost in space and
 left to contemplate the viscicitudes
 of walrus squeezing, try the almighty
 HELP
 command OF DOOM!!!
 >>> edititem
 EVIL CHICKENS ARE ASSAULTING MY FACE!!!
 ehrm, actually, you inputted a
 command I don't recognise. try again.
 if you're totally lost in space and
 left to contemplate the viscicitudes
 of walrus squeezing, try the almighty
 HELP
 command OF DOOM!!!
 >>> help
 Available commands:
 exit:     terminates the program.
 newcart:  creates a new cart.
 killcart: maliciously murders the active cart.
 additem:  adds a new item to the active cart.
 killitem: maliciously murders an item in the active cart.
 lsitems:  lists all items in the active cart.
 itemcat:  lists the specific information about an item.
 edititem: invasively mangles an items inner identity.
 checkout: shows the totals for the active cart and then calls killcart.
 
 This version of apt-get is equipped with super-cow powers.
 >>> edititem
 Which item do you want to edit? 
 0:  30x Semiautomatic Picnic Ants
 1:  2x Substandard Bread
 2:  1x Bloated Cow Intestine with Synthetic Breading
 2
 (1) Name: Bloated Cow Intestine with Synthetic Breading
 (2) Price:    $30
 (3) Quantity:  1
 (4) Taxable:   Born Free, Taxed to Death
 (5) Discount: %10
 (6) exit
 Which attribute do you want to modify? 
 2
 Enter the new price: $20.00
 (1) Name: Bloated Cow Intestine with Synthetic Breading
 (2) Price:    $20
 (3) Quantity:  1
 (4) Taxable:   Born Free, Taxed to Death
 (5) Discount: %10
 (6) exit
 Which attribute do you want to modify? 
 6
 >>> EVIL CHICKENS ARE ASSAULTING MY FACE!!!
 ehrm, actually, you inputted a
 command I don't recognise. try again.
 if you're totally lost in space and
 left to contemplate the viscicitudes
 of walrus squeezing, try the almighty
 HELP
 command OF DOOM!!!
 >>> help
 Available commands:
 exit:     terminates the program.
 newcart:  creates a new cart.
 killcart: maliciously murders the active cart.
 additem:  adds a new item to the active cart.
 killitem: maliciously murders an item in the active cart.
 lsitems:  lists all items in the active cart.
 itemcat:  lists the specific information about an item.
 edititem: invasively mangles an items inner identity.
 checkout: shows the totals for the active cart and then calls killcart.
 
 This version of apt-get is equipped with super-cow powers.
 >>> checkout
 Your total is $145.68 thanks for your business and come back really soon!
*/
