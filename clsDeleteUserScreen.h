#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUsers.h";
using namespace std;


class clsDeleteUserScreen:protected clsScreen
{

private:

	static void _PrintUser(clsUsers User)
	{
		cout << "User Card:" << endl;
		cout << "_____________________________________________" << endl;
		cout << "First Name        :" << User.getFirstName() << endl;
		cout << "Last  Name        :" << User.getLastName() << endl;
		cout << "Full  Name        :" << User.getFullName() << endl;
		cout << "Email             :" << User.getEmail() << endl;
		cout << "Phone             :" << User.getPhone() << endl;
		cout << "NameUser          :" << User.NameUser << endl;
		cout << "Password          :" << User.GetPinCode() << endl;
		cout << "Permission           :" << User.Permission << endl;
		cout << "_____________________________________________\n" << endl;

	}


public:

	static void ShowDeleteUserScreen()
	{
		clsScreen::_DrawScreenHeader("Delete User Screen");

		

		cout << "Please Enter User Name:";
		string UserName = clsInputValidate::ReadString();

		while (clsUsers::IsUserExist(UserName))
		{
			cout << "\nUser with [" << UserName << "] already exists,Enter User Name?";
			UserName = clsInputValidate::ReadString();
		}

		char anwser = 'n';

		clsUsers User = clsUsers::GetAddNewUserObject(UserName);

		_PrintUser(User);

		cout << "\nAre you sure you want deleted this User? y/n? ";
		cin >> anwser;

		if (toupper(anwser) == 'Y')
		{
			if (User.Delete())
				cout << "\nUser Delete successfully :-)" << endl;
			else
				cout << "\nUser Not Delete successfully :-(" << endl;
		}
	}

};