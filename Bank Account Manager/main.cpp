/*
* Name: Minjoo Kwon
* Bank Account Manager
* main.cpp
*/

#include <iostream>
using namespace std;

class Account
{
public:
	int accountID;
	int balance;
	char cusName[100];
	Account() : accountID(0), balance(0) {}
};

void createAccount(Account customers[]);
void ShowMenu();


int main()
{
	ShowMenu();
	int choice;
	cin >> choice;
	Account customers[100];
	
	if (choice == 1)
	{
		createAccount(customers);
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
	char name[100];
	int balance_in;

	cout << "[Create a New Account]" << endl;
	cout << "Account ID: "; cin >> accountID_in;
	cout << "Name: "; cin >> name;
	cout << "Deposit Ammount: "; cin >> balance_in;
	cout << endl;
	customers[accountID_in].accountID = accountID_in;
	strcpy_s(customers[accountID_in].cusName, name);
	customers[accountID_in].balance = balance_in;

}