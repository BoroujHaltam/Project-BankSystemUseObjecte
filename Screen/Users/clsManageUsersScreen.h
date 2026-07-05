#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsListUsersScreen.h";
#include "clsAddNewUsersScreen.h";
#include "clsDeleteUserScreen.h";
#include "clsUpdateUserScreen.h";
#include "clsFindUserScreen.h";
using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:
	enum enManageUserMenu
	{
		eListUsers = 1, eAddNewUsers = 2,
		eDeleteUsers = 3, eUpdateUsers = 4,
		eFindUsers = 5, Main = 6
	};

	static void _GoToBackTransactionMenu()
	{
		cout << "\n\n\tPress any key to go back to Transactions Menu..." << endl;
		system("pause>0");
		ShowManageUsersMenu();
	}

	static void _ShowListUsersScreen()
	{
		
		clsListUsersScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUsersScreen()
	{
		//cout << "Show Add New Users Screen here...";
		clsAddNewUsersScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteUsersScreen()
	{
		//cout << "Show Delete Users Screen here...";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUsersScreen()
	{
		//cout << "Show Update Users Screen here...";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUsersScreen()
	{
		//cout << "Show Find Users Screen here...";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformTransactionMenuOption(enManageUserMenu Option)
	{
		switch (Option)
		{
		case eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoToBackTransactionMenu();
			break;
		case eAddNewUsers:
			system("cls");
			_ShowAddNewUsersScreen();
			_GoToBackTransactionMenu();
			break;
		case eDeleteUsers:
			system("cls");
			_ShowDeleteUsersScreen();
			_GoToBackTransactionMenu();
			break;
		case eUpdateUsers:
			system("cls");
			_ShowUpdateUsersScreen();
			_GoToBackTransactionMenu();
			break;
		case eFindUsers:
			system("cls");
			_ShowFindUsersScreen();
			_GoToBackTransactionMenu();
			break;
		case Main:
			break;
		default:
			break;
		}
	}

	static short _ReadManageUsersMenuOption()
	{
		cout << "\t\t\t\t      Choose what do you want to do? [1 to 6]? ";
		short num = clsInputValidate::ReadIntNumberBetween(1, 6);
		return num;
	}

public:
	static void ShowManageUsersMenu()
	{
		if (!clsScreen::CheckAccessRights(clsUsers::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");
		clsScreen::_DrawScreenHeader("\n\t\t\t\t\t\tScreen Manage Users Menu\n");

		

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Manage Users Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users Screen.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Users Screen.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Users Screen.\n";
		cout << setw(37) << left << "" << "\t[4] Update Users Screen.\n";
		cout << setw(37) << left << "" << "\t[5] Find Users Screen.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionMenuOption(enManageUserMenu(_ReadManageUsersMenuOption()));
	}
};
