#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsCurrency.h";
#include"clsInputValidate.h";
using namespace std;

class clsCurrencyCalculatorScreen :protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency, string massage = "CurrencyCard")
	{
		cout << massage << endl;
		cout << "----------------------------------" << endl;
		cout << "Country   :" << Currency.Country() << endl;
		cout << "Code      :" << Currency.CurrencyCode() << endl;
		cout << "Name      :" << Currency.CurrencyName() << endl;
		cout << "Rate(1$)= :" << Currency.Rate() << endl;
		cout << "----------------------------------" << endl;

	}

	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		short Amount = clsInputValidate::ReadNumber<int>();

		return Amount;
	}

	static clsCurrency _GetCurrency(string massage)
	{
		cout << massage << endl;
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one.";
			CurrencyCode = clsInputValidate::ReadString();
		}

		return clsCurrency::FindByCode(CurrencyCode);
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "\nConvert From:");

		float AmountToUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode() << " = "
			<< AmountToUSD << " " << "USD" << endl;

		if (Currency2.CurrencyCode() == "USD")
			return;

		_PrintCurrencyCard(Currency2, "\nConverting From USD to:");

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << Currency1.ConvertToOtherCurrency(Amount, Currency2)
			<< " " << Currency2.CurrencyCode() << endl;
	}


public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'y';

		while (Answer == 'y' || Answer == 'Y')
		{
			system("cls");

			clsScreen::_DrawScreenHeader("\t\t\t\t\t\tCurrency Calculator Screen");

			clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency2 Code: ");
			short Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, Currency1, Currency2);

			cout << "Do you want to perform another calculation? y/n? ";
			cin >> Answer;
		}
	}
};
