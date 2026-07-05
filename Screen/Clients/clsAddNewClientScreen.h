#pragma once
#include<iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter PinCode? "; Client.PinCode = clsInputValidate::ReadString();

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

	static void ShowAddNewClientScreen()
	{
		if (!clsScreen::CheckAccessRights(clsUsers::enPermissions::pAddNewClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("Add New Clients Screen");

		

		cout << "Please Enter client Account Number:";
		string accountNumber = clsInputValidate::ReadString();

		while (clsBankClient::ClientExist(accountNumber))
		{
			cout << "\nClient with [" << accountNumber << "] already exists,Enter Account Number?";
			accountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::GetAddNewClientObject(accountNumber);

		_ReadClientInfo(Client);

		clsBankClient::enSaveResult SaveResult;
		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError account was not saved because it’s Empty" << endl;
			break;
		case clsBankClient::svSucceeded:
			cout << "\nAccount Update successfully :-)" << endl;
			_PrintClient(Client);
			break;
		case clsBankClient::svFaildAccountNumberExists:
			cout << "\nAccount Number is Exists." << endl;
		default:
			break;
		}

	}

};