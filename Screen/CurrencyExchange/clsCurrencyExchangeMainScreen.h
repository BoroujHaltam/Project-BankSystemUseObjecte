#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsInputValidate.h";
#include"clsCurrenciesListScreen.h";
#include"clsFindCurrencyScreen.h";
#include"clsUpdateCurrencyRateScreen.h";
#include"clsCurrencyCalculatorScreen.h";
using namespace std;

class clsCurrencyExchangeMainScreen :protected clsScreen
{
private:
	enum enOptionCurrancy
	{
		List = 1, Find = 2, Update = 3, Calculator = 4, Main = 5
	};

	static void _GoBackToCurrencyManu()
	{
		cout << "\n\n\tPress any key to go back to Main Menu..." << endl;
		system("pause>0");
		ShowCurrencyMainScreen();
	}

	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrenciesManuOptions(enOptionCurrancy option)
	{
		switch (option)
		{
		case clsCurrencyExchangeMainScreen::List:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyManu();
			break;
		case clsCurrencyExchangeMainScreen::Find:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyManu();
			break;
		case clsCurrencyExchangeMainScreen::Update:
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyManu();
			break;
		case clsCurrencyExchangeMainScreen::Calculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyManu();
			break;
		case clsCurrencyExchangeMainScreen::Main:
			break;
		default:
			break;
		}
	}

	static short _ReadCurrenciesMainMenuOptions()
	{
		cout << "\t\t\t\t" << "    Choose what do you want to do? [1 to 5]? ";
		int choice = clsInputValidate::ReadNumberBetween<int>(1, 5);
		return choice;
	}

public:

	static void ShowCurrencyMainScreen()
	{
		system("cls");
		_DrawScreenHeader("    \t\t\t\t\tCurrancy Exhange Main Screen");

		cout << setw(36) << left << "" << "===========================================\n";
		cout << setw(36) << left << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(36) << left << "" << "===========================================\n";
		cout << setw(36) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(36) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(36) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(36) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(36) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(36) << left << "" << "===========================================\n";
		_PerformCurrenciesManuOptions(enOptionCurrancy(_ReadCurrenciesMainMenuOptions()));

	}

};
