#include "Airlines.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>  
#include <fstream>  
#include <sstream>

using namespace std;

void showMenu();
void displayOrder(Airlines, Airlines, Airlines);
bool isValidStr(string);
bool isValidInt(string);
bool binarySearch(int [], int, int);
void selectionSort(int [], int);

int main()
{
	vector<Airlines*> trans;
	
	ifstream inputFile;
	string *ptrStnd, *ptrEcon, *ptrBsns;
	string s_tickets, s_temp, s_again, s_choice, s_data;
	int i_tickets;
	bool print = true, found = false;

	const char STANDARD = 'A', ECONOMY = 'B', BUSINESS = 'C', QUIT = 'D';

	Airlines standard("Standard", 250.00, 0);
	Airlines economy("Economy", 350.00, 0);
	Airlines business("Business", 450.00, 0);
	do
	{
		if (print == true)
			showMenu();
		print = true;

		cout << "please enter your choice of A, or B, or C or D: ";

		getline(cin, s_choice);
		while(!isValidStr(s_choice))
		{
			cout << "Please enter a valid input: ";
			getline(cin, s_choice); 
		}
		switch (s_choice[0])
		{
		case 'a':
		case STANDARD:
			trans.push_back(new Airlines("Standard", 250.00, 0)); 
			cout << "How many tickets would you like to purchase? ";
			getline(cin, s_tickets);

			while(!isValidInt(s_tickets))
			{
				cout << "Please enter a valid number: ";
				getline(cin, s_tickets); 
			}

			while (stoi(s_tickets) >= 10) {
				cout << "Please confirm the ticket availability with the Airlines." << endl;
				cout << "Or, just enter the number of tickets again: ";
				getline(cin, s_tickets);
				while(!isValidInt(s_tickets))
				{
					cout << "Please enter a valid number: ";
					getline(cin, s_tickets); 
				}
			}

			i_tickets = stoi(s_tickets);
			standard.setTicketQuantity(i_tickets);
			trans[trans.size()-1]->setTicketQuantity(i_tickets);

			cout << fixed << setprecision(2) << setw(24) << left << endl << trans[trans.size()-1]->getTicketType() + ":" 
				 << "Ticket: " << setw(8) << trans[trans.size()-1]->getticketQuantity() << "Charge: $" << setw(7) << right 
				 << trans[trans.size()-1]->getTicketSubTotal() << "\tTax: $"<< setw(7) << trans[trans.size()-1]->getTax();
		
			displayOrder(standard, economy, business);
			break;

		case 'b':
		case ECONOMY:
			trans.push_back(new Airlines("Economy", 350.00, 0)); 
			cout << "How many tickets would you like to purchase? ";
			getline(cin, s_tickets);

			while(!isValidInt(s_tickets))
			{
				cout << "Please enter a valid number: ";
				getline(cin, s_tickets); 
			}

			while (stoi(s_tickets) >= 10) {
				cout << "Please confirm the ticket availability with the Airlines." << endl;
				cout << "Or, just enter the number of tickets again: ";
				getline(cin, s_tickets);
				while(!isValidInt(s_tickets))
				{
					cout << "Please enter a valid number: ";
					getline(cin, s_tickets); 
				}
			}

			i_tickets = stoi(s_tickets);
			economy.setTicketQuantity(i_tickets);
			trans[trans.size()-1]->setTicketQuantity(i_tickets);
						
			cout << fixed << setprecision(2) << setw(24) << left << endl << trans[trans.size()-1]->getTicketType() + ":" 
				 << "Ticket: " << setw(8) << trans[trans.size()-1]->getticketQuantity() << "Charge: $" << setw(7) << right 
				 << trans[trans.size()-1]->getTicketSubTotal() << "\tTax: $"<< setw(7) << trans[trans.size()-1]->getTax();
		
			displayOrder(standard, economy, business);
			break;

		case 'c':
		case BUSINESS:
			trans.push_back(new Airlines("Business", 450.00, 0));
			cout << "How many tickets would you like to purchase? ";
			getline(cin, s_tickets);

			while(!isValidInt(s_tickets))
			{
				cout << "Please enter a valid number: ";
				getline(cin, s_tickets); 
			}

			while (stoi(s_tickets) >= 10) {
				cout << "Please confirm the ticket availability with the Airlines." << endl;
				cout << "Or, just enter the number of tickets again: ";
				getline(cin, s_tickets);
				while(!isValidInt(s_tickets))
				{
					cout << "Please enter a valid number: ";
					getline(cin, s_tickets); 
				}
			}

			i_tickets = stoi(s_tickets);
			business.setTicketQuantity(i_tickets);
			trans[trans.size()-1]->setTicketQuantity(i_tickets);

			cout << fixed << setprecision(2) << setw(24) << left << endl << trans[trans.size()-1]->getTicketType() + ":" 
				 << "Ticket: " << setw(8) << trans[trans.size()-1]->getticketQuantity() << "Charge: $" << setw(7) << right 
				 << trans[trans.size()-1]->getTicketSubTotal() << "\tTax: $"<< setw(7) << trans[trans.size()-1]->getTax();
		
			displayOrder(standard, economy, business);
			break;

		case 'd': //exits the menu
		case QUIT:
			cout << "you have made " << trans.size() << " transactions" <<  endl;
			cout << "Thank you for yor business.";
			displayOrder(standard, economy, business);
			cout << "Enjoy your Flight" << endl << "See you next time.\n";

			cout << "If youre a Customer you can exit this program now.\n";
			cout << "Please enter 'Y/y' for Yes to exit or 'N/n' to continue: ";
			getline(cin, s_again);
			if (toupper(s_again[0]) == 'Y')
			{
				for (int i = 0; i < trans.size(); i++)
				{	
					delete (trans[i]);
					trans[i] = 0;
				}	
				trans.clear();
				exit(0);
			}
			else 
				break;

		default: //propmts the user for a valid answer
			cout << "\nThe valid choices are A, B, C, and D\n\n";
			print = false;
		}

	} while (toupper(s_choice[0]) != QUIT);

	cout << "Please continue this program.\n";
	cout << "Please enter the password for the text program: ";
		
	for (int i = 0; i < trans.size(); i++)
	{	
		delete (trans[i]);
		trans[i] = 0;
	}	

	trans.clear();

	return 0;
}

void showMenu()
{
	cout << right << setw(39) << "Airlines Ticket Menu\n\n";
	cout << "A. Standard Ticket\t $250.00 Each\n";
	cout << "B. Economy Ticket \t $350.00 Each\n";
	cout << "C. Business Ticket\t $450.00 Each\n";
	cout << "D. Quit the Menu\n\n";

}

//prints out the current total of tickets ordered and their price
void displayOrder(Airlines standard, Airlines economy, Airlines business)
{
	cout << fixed << setprecision(2) << "\n\nTotal Standard Ticket:  Ticket: "  << left << setw(8) << standard.getticketQuantity()
		 << "Charge: $" << setw(7) << right << standard.getTicketSubTotal() << "\tTax: $"<< setw(7) << standard.getTax() << endl; 
	
	cout << "Total Economy Ticket:   Ticket: " << left << setw(8) << economy.getticketQuantity() << "Charge: $"
	     << right << setw(7) << economy.getTicketSubTotal() << "\tTax: $" << setw(7) << economy.getTax() << endl; 

	cout << "Total Business Ticket:  Ticket: " << left << setw(8) << business.getticketQuantity() << "Charge: $"
		 << right << setw(7) << business.getTicketSubTotal() << "\tTax: $" << setw(7) << business.getTax() << endl << endl; 

	cout << left << setw(24) << "Subtotal:" 
		 << standard.getTicketSubTotal()+economy.getTicketSubTotal()+business.getTicketSubTotal() << endl;
	cout << left << setw(24) << "Tax:" << standard.getTax()+economy.getTax()+business.getTax() << "\n\n";
	cout << left << setw(24) << "Total Charges:"
		 << standard.getTicketTotal()+economy.getTicketTotal()+business.getTicketTotal() << "\n\n";
}

bool isValidStr(string input)
{	
	if ( input.empty() || input.length() > 1 || !isalpha(input[0]) )
		return false;
	return true;
}

bool isValidInt(string num)
{	
	if (num.empty())
		return false;
	for (int i = 0; i < num.length(); i++ )
	{
		if (!isdigit(num[i]))
		return false;
	}
	return true;
}

void selectionSort(int ptr[], int size)
{
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = ptr[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (ptr[index] < minValue)
			{
				minValue = ptr[index];
				minIndex = index;
			}
		}
		ptr[minIndex] = ptr[startScan];
		ptr[startScan] = minValue;
	}
}

bool binarySearch(int ptr[], int numElems, int value)
{
	int first = 0,
		last = numElems - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (ptr[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (ptr[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}
	if(position >= 0)
		return true;
	else 
		return false;
}
