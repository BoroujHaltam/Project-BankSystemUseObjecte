#pragma once
#include<iostream>
#include<iomanip>
#include"clsUsers.h";
#include"Global.h";
#include"clsDate.h";
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title,string SubTitle="")
	{
		
		cout <<  "\t\t\t\t   ________________________________________________\n" << endl;
		cout << "                   \t\t\t\t\t"<<Title << endl;
		if (SubTitle != "")
		{
			cout << "                 \t\t\t\t\t" << SubTitle << endl;
		}
		
		cout <<  "\t\t\t\t   ________________________________________________\n" << endl;
	
		cout << "\t\t\t\t\tUser: " << CurrentUser.GetNameUser() << endl;
		cout << "\t\t\t\t\tDate: "<<clsDate::DateToString(clsDate()) << "\n";
	}

	static bool CheckAccessRights(clsUsers::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t   ________________________________________________\n" << endl;

			cout << "                   \t\t\tAccess Denied! Contact your Admin." << endl;

			cout << "\t\t\t\t   ________________________________________________\n" << endl;

			return false;
		}
		else
		{
			return true;
		}
	}

};
