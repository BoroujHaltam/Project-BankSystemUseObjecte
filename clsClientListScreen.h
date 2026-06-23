#pragma once
#include<iostream>
#include<iomanip>
#include "clsBankClient.h";
#include "clsScreen.h";
#include "clsUsers.h";
using namespace std;

class clsClientListScreen: protected clsScreen
{
private:

	static void PrintClientRecordLine(clsBankClient Client)
	{
		cout << "\t| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(15) << left << Client.getFullName();
		cout << "| " << setw(15) << left << Client.getPhone();
		cout << "| " << setw(25) << left << Client.getEmail();
		cout << "| " << setw(15) << left << Client.PinCode;
		cout << "| " << setw(15) << left << Client.AccountBalance;
	}

public:

	static void ShowClientsList()
	{
		if (!clsScreen::CheckAccessRights(clsUsers::enPermissions::pListClients))
		{
			return;
		}

		vector<clsBankClient> vDataFile = clsBankClient::GetClientsList();
		string Title = "Client List Screen";
		string SubTitle = "(" + to_string(vDataFile.size()) + ") Client(s).";
		
		clsScreen::_DrawScreenHeader(Title,SubTitle);

		
		
		cout << "\n\n\t--------------------------------------------------------------------------------------------------------- " << endl;

		cout << "\t| " << setw(15) << left << "Account Number";
		cout << "| " << setw(15) << left << "Client Name";
		cout << "| " << setw(15) << left << "Phone";
		cout << "| " << setw(25) << left << "Email";
		cout << "| " << setw(15) << left << "Pin Code";
		cout << "| " << setw(15) << left << "Balance" << endl;

		cout << "\t---------------------------------------------------------------------------------------------------------" << endl;

		if (vDataFile.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
			for (clsBankClient Client : vDataFile)
			{
				PrintClientRecordLine(Client);
				cout << endl;
			}
		cout << "\t---------------------------------------------------------------------------------------------------------" << endl;
	}

};