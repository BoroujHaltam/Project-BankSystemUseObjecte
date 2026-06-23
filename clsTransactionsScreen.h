#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsDepositScreen.h";
#include "clsWithdrawScreen.h";
#include "clsTotalBalanceScreen.h";
#include "clsTransferScreen.h";
#include "clsTransferLogScreen.h";
using namespace std;

class clsTransactionsScreen : protected clsScreen
{	
private:
	enum enTransactionMenu
	{
		Deposit = 1, Withdraw = 2, 
		TotalBalances = 3, Transfer = 4, TransferLog=5,Main = 6
	};

	static void _GoToBackTransactionMenu()
	{
		cout << "\n\n\tPress any key to go back to Transactions Menu..." << endl;
		system("pause>0");
		ShowTransactionsMenu();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::_ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalanceScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowLoginTransferScreen();
	}

	static void _PerformTransactionMenuOption(enTransactionMenu Option)
	{
		switch (Option)
		{
		case clsTransactionsScreen::Deposit:
			system("cls");
			_ShowDepositScreen();
			_GoToBackTransactionMenu();
			break;
		case clsTransactionsScreen::Withdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoToBackTransactionMenu();
			break;
		case clsTransactionsScreen::TotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoToBackTransactionMenu();
			break;
		case clsTransactionsScreen::Transfer:
			system("cls");
			_ShowTransferScreen();
			_GoToBackTransactionMenu();
			break;
		case clsTransactionsScreen::TransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoToBackTransactionMenu();
			break;
		case clsTransactionsScreen::Main:
			break;
		default:
			break;
		}
	}

	static short _ReadTransactionMenuOption()
	{
		cout << "\t\t\t\t      Choose what do you want to do? [1 to 6]? ";
		short num = clsInputValidate::ReadIntNumberBetween(1, 6);
		return num;
	}

public:
	static void ShowTransactionsMenu()
	{
		if (!clsScreen::CheckAccessRights(clsUsers::enPermissions::pTranactions))
		{
			return;
		}

		system("cls");
		clsScreen::_DrawScreenHeader("\n\t\t\t\t\t\tScreen Transactions Menu\n");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit Screen.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw Screen.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances Screen.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionMenuOption(enTransactionMenu(_ReadTransactionMenuOption()));
	}
};

