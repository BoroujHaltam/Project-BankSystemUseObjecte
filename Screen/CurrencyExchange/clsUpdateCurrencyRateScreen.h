#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsCurrency.h";
#include"clsInputValidate.h";
using namespace std;

class clsUpdateCurrencyRateScreen :protected clsScreen
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

	static float  _ReadRate()
	{
		cout << "Enter New Rate: ";
		float Rate = clsInputValidate::ReadNumber<float>();
		return Rate;
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		clsScreen::_DrawScreenHeader("\t\t\t\t\t\tUpdate Currency Rate Screen");

		cout << "Please Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one.";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		cout << "Are you sure you want to update the rate of this Currency? y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\nUpdate Currency Rate:" << endl;
			cout << "-------------------------" << endl;

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Successfully :-)" << endl;
			_PrintCurrency(Currency);

		}

	}
};
