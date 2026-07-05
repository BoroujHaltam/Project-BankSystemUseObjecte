#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h";
#include "Global.h";
#include "clsClientListScreen.h";
#include "clsAddNewClientScreen.h";
#include "clsDeleteClientScreen.h";
#include "clsUpdateClientScreen.h";
#include "clsFindClientScreen.h";
#include "clsTransactionsScreen.h";
#include "clsInputValidate.h";
#include "clsManageUsersScreen.h";
#include "clsLoginRegisterScreen.h";
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenue
	{
		Show = 1, Add = 2, Delete = 3, 
		Update = 4, Find = 5, Transaction =6,
		ManageUsers=7,Register=8, Exit=9
	};

	static void _GoToBackMainMenu()
	{
		cout << "\n\n\tPress any key to go back to Main Menu..." << endl;
		system("pause>0");
		ShowMainMenu();
	}

	static void _Logout()
	{
		CurrentUser = clsUsers::Find("", "");
	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowScreenAddClient()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	
	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenu()
	{
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersMenu()
	{
		clsManageUsersScreen::ShowManageUsersMenu();
	}

	static void _ShowLoginRegister()
	{
		clsLoginRegisterScreen::ShowLoginRegisterMenu();
	}

	static void _PerformMainMenuOption(enMainMenue num)
	{
		switch (num)
		{
		case Show:
			system("cls");
			_ShowAllClientsScreen();
			_GoToBackMainMenu();
			break;
		case Add:
			system("cls");
			_ShowScreenAddClient();
			_GoToBackMainMenu();
			break;
		case Delete:
			system("cls");
			_ShowDeleteClientScreen();
			_GoToBackMainMenu();
			break;
		case Update:
			system("cls");
			_ShowUpdateClientScreen();
			_GoToBackMainMenu();
			break;
		case Find:
			system("cls");
			_ShowFindClientScreen();
			_GoToBackMainMenu();
			break;
		case Transaction:
			system("cls");
			_ShowTransactionsMenu();
			_GoToBackMainMenu();
			break;
		case ManageUsers:
			system("cls");
			_ShowManageUsersMenu();
			_GoToBackMainMenu();
			break;
		case Register:
			system("cls");
			_ShowLoginRegister();
			_GoToBackMainMenu();
			break;
		case Exit:
			system("cls");
			_Logout();
			break;
		default:
			break;
		}
	}

	static short _ReadMainMenuOption()
	{
		cout <<"\t\t\t\t      Choose what do you want to do? [1 to 9]? ";
		short num = clsInputValidate::ReadIntNumberBetween(1, 9);
		return num;
	}

public:

	static void ShowMainMenu()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\n\t\t\t\t\t\t\tScreen Menu\n");

		

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenuOption(enMainMenue(_ReadMainMenuOption()));
	}

};



