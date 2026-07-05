#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUsers.h";
using namespace std;

class clsFindUserScreen:protected clsScreen
{
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
	static void ShowFindUserScreen()
	{
		clsScreen::_DrawScreenHeader("Find User Screen");

		

		cout << "Please Enter User Name:";
		string UserName = clsInputValidate::ReadString();

		while (clsUsers::IsUserExist(UserName))
		{
			cout << "\nUser with [" << UserName << "] already exists,Enter User Name?";
			UserName = clsInputValidate::ReadString();
		}

		clsUsers User = clsUsers::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nClient Was Found :-)" << endl;

			_PrintUser(User);
		}
		else
			cout << "\nClient Was Not Found :-(" << endl;

	}
};
