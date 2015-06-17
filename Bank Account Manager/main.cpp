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
	
	while (1){
		ShowMenu();
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			createAccount(customers, numPeople);
			++numPeople;
		}
		else if (choice == 2)
			deposit(customers, numPeople);

		else if (choice == 3)
			withdrawl(customers, numPeople);

		else if (choice == 4)
			viewInfo(customers, numPeople);

		else if (choice == 5)
			return 0;
		else
			cout << "Wrong choice!! " << endl;
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
	cout << "Deposit amount: $"; cin >> deposit;

	for (int i = 0; i < numPeople_in; ++i)
	{
		if (customers[i].accountID == accID_in)
		{
			customers[i].balance += deposit;
		}
	}
	cout << "Desposited successfully.";
	cout << endl;
	cout << endl;
}

void withdrawl(Account customers[], int numPeople_in)
{
	cout << "[Withdrawl]" << endl;
	int accID;
	cout << "Account ID: "; cin >> accID;
	int withdrawl;
	cout << "Withdrawl amount: $"; cin >> withdrawl;
	for (int i = 0; i < numPeople_in; ++i)
	{
		if (customers[i].accountID == accID)
			customers[i].balance -= withdrawl;
	}
	cout << "Withdrawn successfully.";

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