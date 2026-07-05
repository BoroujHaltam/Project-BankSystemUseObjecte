#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsCurrency.h";
#include"clsInputValidate.h";
using namespace std;

class clsFindCurrencyScreen :protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card: " << endl;
		cout << "----------------------------------" << endl;
		cout << "Country   :" << Currency.Country() << endl;
		cout << "Code      :" << Currency.CurrencyCode() << endl;
		cout << "Name      :" << Currency.CurrencyName() << endl;
		cout << "Rate(1$)= :" << Currency.Rate() << endl;
		cout << "----------------------------------" << endl;

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)" << endl;
			_PrintCurrency(Currency);

		}
		else
		{
			cout << "Currency Not Found :-(" << endl;
		}

	}

public:

	static void ShowFindCurrencyScreen()
	{
		clsScreen::_DrawScreenHeader("\t\t\t\t\t\Find Currency Screen");

		cout << "FindBy: [1] Code or [2] Country ? ";
		short choice = clsInputValidate::ReadNumber<int>();

		if (choice == 1)
		{
			cout << "\nPlease Enter CurrencyCode: ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			cout << "\nPlease Enter Country: ";
			string Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}

	}
};
