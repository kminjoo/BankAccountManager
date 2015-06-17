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

void createAccount(Account customers[], int numPeople_in);
void ShowMenu();
void deposit(Account customers[], int numPeople_in);
void viewInfo(Account customers[], int numPeople);
void withdrawl(Account customers[], int numPeople_in);

int main()
{
	int numPeople = 0;
	Account customers[100];
	
	enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
	while (1){
		ShowMenu();
		int choice;
		cin >> choice;

		switch (choice)
		{
		case MAKE:
		{
			createAccount(customers, numPeople);
			++numPeople;
			break;
		}
		case DEPOSIT:
			deposit(customers, numPeople); break;
		case WITHDRAW:
			withdrawl(customers, numPeople); break;
		case INQUIRE:
			viewInfo(customers, numPeople); break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection." << endl; 
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


void createAccount(Account customers[], int numPeople_in)
{
	int accountID_in;
	char name_in[100];
	int balance_in;

	cout << "[Create a New Account]" << endl;
	cin.ignore();
	cout << "Name: "; cin.getline(name_in,100);
	cout << "Account ID: "; cin >> accountID_in;
	cout << "Deposit Amount: $"; cin >> balance_in;
	cout << endl; 

	customers[numPeople_in].accountID = accountID_in;
	customers[numPeople_in].cusName = name_in;
	customers[numPeople_in].balance += balance_in;
	
}

void deposit(Account customers[], int numPeople_in)
{
	int accID_in;
	int deposit;
	cout << "[Deposit]" << endl;
	cout << "Account ID: "; cin >> accID_in;

	for (int i = 0; i < numPeople_in; ++i)
	{
		if (customers[i].accountID == accID_in)
		{	
			cout << "Deposit amount: $"; cin >> deposit;
			customers[i].balance += deposit;
			cout << "Desposited successfully." << endl;
			return;
		}
	}
	cout << "ID not found.";
	cout << endl;
	cout << endl;
}

void withdrawl(Account customers[], int numPeople_in)
{
	cout << "[Withdrawl]" << endl;
	int accID;
	cout << "Account ID: "; cin >> accID;
	int withdrawl;
	for (int i = 0; i < numPeople_in; ++i)
	{
		if (customers[i].accountID == accID)
		{
			cout << "Withdrawl amount: $"; cin >> withdrawl;
			customers[i].balance -= withdrawl;
			cout << "Withdrawn successfully." << endl;
			return;
		}
	}
	cout << "ID not found" << endl;

}
void viewInfo(Account customers[], int numPeople)
{
	for (int i = 0; i < numPeople; ++i)
	{
		cout << "Account ID: " << customers[i].accountID << endl;
		cout << "Name: " << customers[i].cusName << endl;
		cout << "Balance: $" << customers[i].balance << endl;
		cout << endl << endl;
	}

}