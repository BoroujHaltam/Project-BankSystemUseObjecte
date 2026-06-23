#pragma once
#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "Client Card:" << endl;
		cout << "_____________________________________________" << endl;
		cout << "First Name        :" << Client.getFirstName() << endl;
		cout << "Last  Name        :" << Client.getLastName() << endl;
		cout << "Full  Name        :" << Client.getFullName() << endl;
		cout << "Email             :" << Client.getEmail() << endl;
		cout << "Phone             :" << Client.getPhone() << endl;
		cout << "Acc. Number       :" << Client.AccountNumber() << endl;
		cout << "Password          :" << Client.GetPinCode() << endl;
		cout << "Balance           :" << Client.GetAccountBalance() << endl;
		cout << "_____________________________________________\n" << endl;

	}

public:

	static void ShowDeleteClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUsers::enPermissions::pDeleteClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("Delete Client Screen");

		

		cout << "Please Enter client Account Number:";
		string accountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::ClientExist(accountNumber))
		{
			cout << "\nAccount Number is not found, choose another one:";
			accountNumber = clsInputValidate::ReadString();
		}

		char anwser = 'n';

		clsBankClient Client = clsBankClient::Find(accountNumber);
		_PrintClient(Client);

		cout << "\nAre you sure you want deleted this client? y/n? ";
		cin >> anwser;

		if (toupper(anwser) == 'Y')
		{
			if (Client.Delete())
				cout << "\nAccount Delete successfully :-)" << endl;
			else
				cout << "\nAccount Not Delete successfully :-(" << endl;
		}
	}

};