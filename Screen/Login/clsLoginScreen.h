#pragma once
#include <iostream>
#include "Global.h";
#include "clsUsers.h";
#include "clsScreen.h";
#include "clsMainScreen.h";
#include "clsInputValidate.h";
using namespace std;

class clsLoginScreen : public clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFalid = false;
		string UserName, Pin;
		short FaildLoginCount = 0;

		do {

			if (LoginFalid)
			{
				FaildLoginCount++;
				cout << "Invlaid Username/Password" << endl;
				cout << "You have "<<(3- FaildLoginCount) << " Trial(s) to login.\n\n" << endl;
			}
			if (FaildLoginCount == 3)
			{
				cout << "\nYour are Locked after 3 faild trails.\n\n" << endl;
				return false;
			}

			cout << "Enter User Name? ";
			UserName = clsInputValidate::ReadString();

			cout << "Enter Pin? "; Pin = clsInputValidate::ReadString();

			CurrentUser = clsUsers::Find(UserName, Pin);

			LoginFalid = CurrentUser.IsEmpty();

			
		} while (LoginFalid);

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenu();
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("Login Screen");
		return _Login();
	}

};