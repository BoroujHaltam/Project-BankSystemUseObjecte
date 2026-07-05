#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUsers.h";
using namespace std;

class clsListUsersScreen:protected clsScreen
{
private:

	static void PrintUserRecordLine(clsUsers User)
	{
		cout << "\t| " << setw(15) << left << User.NameUser;
		cout << "| " << setw(15) << left << User.getPhone();
		cout << "| " << setw(25) << left << User.getEmail();
		cout << "| " << setw(15) << left << User.PinCode;
		cout << "| " << setw(15) << left << User.Permission;
	}

public:
	
	static void ShowUsersListScreen()
	{
		vector<clsUsers> vDataFile = clsUsers::GetUsersList();
		string Title = "User List Screen";
		string SubTitle = "(" + to_string(vDataFile.size()) + ") User(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		

		cout << "\n\n\t--------------------------------------------------------------------------------------------------------- " << endl;

		cout << "\t| " << setw(15) << left << "User Name";
		cout << "| " << setw(15) << left << "Phone";
		cout << "| " << setw(25) << left << "Email";
		cout << "| " << setw(15) << left << "Pin Code";
		cout << "| " << setw(15) << left << "Permission" << endl;

		cout << "\t---------------------------------------------------------------------------------------------------------" << endl;

		if (vDataFile.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else
			for (clsUsers User : vDataFile)
			{
				PrintUserRecordLine(User);
				cout << endl;
			}
		cout << "\t---------------------------------------------------------------------------------------------------------" << endl;
	}
};