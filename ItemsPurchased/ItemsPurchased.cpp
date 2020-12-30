/* Programmer  : Kendra Hayden
   Date		   : Feb 24, 2020
   Assignment  : Chapters 1-4 Test
   Description : Input from user about purchases and putting it to a txt file
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <Windows.h>


using namespace std;


// constant Variables Tax, books, videos, cds
const double TAX      = .06;
const double BOOKS    = 16.50;
const double VIDEOS   = 19.99;
const double CDS      = 21.20;

int main() {

	// Variables
	string fName                 = " " ;
	string lName                 = " " ;
	char itemPurchased           = ' ';
	string itemPurchasedOut      = " ";
	int quan                     = 0;
	double subtotal              = 0.0; 
	double totalTax              = 0.0;
	double total                 = 0.0;
	double itemCost              = 0.0;

	// outfile 
	ofstream outfile;
	outfile.open("C1-4TestOutput.txt", ios::app);

	system("cls");

	// input from User 

	cout << "Input for Customer Information Screen" << endl << endl;
	cout << "Please enter your first name:                                  ";
	cin >> fName;
	cout << "Please enter your last name:                                   ";
	cin >> lName;
	cout << "Please enter the item purchased - (B)ooks, (V)ideos, or (C)Ds: ";
	cin >> itemPurchased;

	// if statement 
	if (itemPurchased == 'B' || itemPurchased == 'b') {
		itemPurchasedOut = "Books";
		itemCost = BOOKS;
	}else if (itemPurchased == 'C' || itemPurchased == 'c') {
		itemPurchasedOut = "CDs";
		itemCost = CDS;
	}else if (itemPurchased == 'V' || itemPurchased == 'v') {
		itemPurchasedOut = "Videos";
		itemCost = VIDEOS;
		
	}
	else {
		itemPurchasedOut = "Incorrect Item Purchased";
	}

	cout << "Please enter the quanitity of the " << itemPurchasedOut << " purchased:               ";
	cin >> quan;

	// math 
	subtotal = quan * itemCost; 
	totalTax = subtotal * TAX;
	total = totalTax + subtotal; 


	// output to user 
	cout << fixed << showpoint << setprecision(2);
	cout << "------------------- Book Store Sales-----------------------------" << endl << endl;
	cout << "Customer Name:        " << fName << " " << lName << endl;
	cout << "Customer Purchase:    " << itemPurchasedOut << endl;
	cout << "Quantity Purchased:   $" << quan << endl;
	cout << "Purchased Item Cost:  $" << itemCost << endl;
	cout << "Item Subtotal:        $" << subtotal << endl;
	cout << "Item Sales Tax:       $" << totalTax << endl;
	cout << "Item Total:           $" << total << endl;
	cout << "------------------- Book Store Total-----------------------------" << endl << endl;

	outfile << fixed << showpoint << setprecision(2); 
	outfile << fName << " " << lName << " " << quan << " " << itemCost << " " << subtotal << " " << totalTax << " " << total; 
	cout << endl; 


	outfile.close();
	cout << "Press any key to end the Book Store program...";
	system("pause>null");   
	return 0;
}
