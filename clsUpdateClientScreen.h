#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
using namespace std;

class clsUpdateClientScreen :protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter PinCode? "; Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter First Name? "; Client.setFirstName(clsInputValidate::ReadString());

		cout << "Enter Last Name? "; Client.setLastName(clsInputValidate::ReadString());

		cout << "Enter Phone? "; Client.setPhone(clsInputValidate::ReadString());

		cout << "Enter Email? "; Client.setEmail(clsInputValidate::ReadString());

		cout << "Enter Account Balance? "; Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

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

	static void ShowUpdateClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUsers::enPermissions::pUpdateClients))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("Update Client Screen");

		

		cout << "Please Enter client Account Number:";
		string accountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::ClientExist(accountNumber))
		{
			cout << "\nAccount Number is not found, choose another one:";
			accountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(accountNumber);
		_PrintClient(Client);

		cout << "Update Info:" << endl;
		cout << "------------------------------------" << endl;
		_ReadClientInfo(Client);

		clsBankClient::enSaveResult Result;
		Result = Client.Save();

		if (Result == clsBankClient::enSaveResult::svSucceeded)
		{
			_PrintClient(Client);
			cout << "\nAccount Update successfully :-)" << endl;
		}
		else
		{
			cout << "\nAccount Update Not successfully :-(" << endl;
		}

	}

};
