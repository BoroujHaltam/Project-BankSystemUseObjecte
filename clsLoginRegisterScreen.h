#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsString.h";
using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
private:
	static void PrintRegesterRecordLine(clsUsers::stLoginRegisterRecord Client)
	{
		cout << "\t| " <<  Client.DateTime;
		cout << "\t\t| " <<  Client.UserName;
		cout << "\t\t| " <<  Client.Password;
		cout << "\t\t| " <<  Client.Permissions;
	}

public:
	static void ShowLoginRegisterMenu()
	{

		if (!clsScreen::CheckAccessRights(clsUsers::enPermissions::pLoginRegister))
		{
			return;
		}

		system("cls");
		vector<clsUsers::stLoginRegisterRecord> vDataFile = clsUsers::GetLoginRegisterList();

		string SubTitle = "(" + to_string(vDataFile.size()) + ") Client(s).";

		clsScreen::_DrawScreenHeader("\n\t\t\t\t\t\tLogin Register List Screen\n", SubTitle);

		cout << "\n\n\t-------------------------------------------------------------------------------" << endl;

		cout << "\t| " << "Date/Time";
		cout << "\t\t\t| " <<  "User Name";
		cout << "\t| " << "Password";
		cout << "\t| " << "Permissions" << endl;

		cout << "\t-------------------------------------------------------------------------------" << endl;
		

		if (vDataFile.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
			for ( clsUsers::stLoginRegisterRecord Client:vDataFile)
			{
				PrintRegesterRecordLine(Client);
				cout << endl;
			}
		cout << "\t-------------------------------------------------------------------------------" << endl;
	}
};

