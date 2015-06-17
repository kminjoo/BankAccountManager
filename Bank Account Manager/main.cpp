/*
* Name: Minjoo Kwon
* Bank Account Manager
* main.cpp
*/

#include <iostream>
#include <string>
using namespace std;

class Account
{
public:
	int accountID;
	int balance;
	string cusName;
	Account() : accountID(0), balance(0) {}
};

void createAccount(Account customers[]);
void ShowMenu();


int main()
{
	
	Account customers[100];
	
	while (1){
		ShowMenu();
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			createAccount(customers);
		}
		if (choice == 5)
		{
			return 0;
		}
	}
}

void ShowMenu()
{
	cout << "----------------- Menu --------------" << endl;
	cout << "1. Create new account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawl" << endl;
	cout << "4. View all the Account informations" << endl;
	cout << "5. Exit" << endl;
	cout << "Choose: ";
}


void createAccount(Account customers[])
{
	int accountID_in;
	string name_in;
	int balance_in;

	cout << "[Create a New Account]" << endl;
	cout << "Name: "; cin >> name_in;
	cout << "Account ID: "; cin >> accountID_in;
	cout << "Deposit Amount: $"; cin >> balance_in;
	cout << endl; 

	customers[accountID_in].accountID = accountID_in;
	customers[accountID_in].cusName =  name_in;
	customers[accountID_in].balance = balance_in;

}