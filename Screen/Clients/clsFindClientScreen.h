#pragma once
#include<iostream>
#include "clsScreen.h";
#include"clsBankClient.h";
#include "clsInputValidate.h";
using namespace std;

class clsFindClientScreen :protected clsScreen
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
	static void ShowFindClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUsers::enPermissions::pFindClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("Find Client Screen");

		

		cout << "Please Enter client Account Number:";
		string accountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::ClientExist(accountNumber))
		{
			cout << "\nAccount Number is not found, choose another one:";
			accountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client=clsBankClient::Find(accountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Was Found :-)" << endl;

			_PrintClient(Client);
		}
		else
			cout << "\nClient Was Not Found :-(" << endl;
		
	}
};

