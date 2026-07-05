#pragma once
#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsCurrency.h";
using namespace std;

class clsCurrenciesListScreen :protected clsScreen
{
private:

	static void PrintCurrenciesListDataInFile(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}

public:

	static void ShowCurrenciesListScreen()
	{
		vector<clsCurrency> vCurrenciesList = clsCurrency::GetCurrencyList();

		string SubTitle = "\t\t\t\t\t\t(" + to_string(vCurrenciesList.size()) + ") Currency";
		clsScreen::_DrawScreenHeader("\t\t\t\t\t\tCurrencies List Screen", SubTitle);

		cout << "\t------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t| Country \t\t\t| Code \t  | Name\t\t\t\t\t"
			<< " | Rate/(1$)" << endl;
		cout << "\t------------------------------------------------------------------------------------------------------" << endl;

		if (vCurrenciesList.size() == 0)
			cout << "\t\t\t\tNo Currencies Availavle In the System!";
		else
			for (clsCurrency List : vCurrenciesList)
			{
				PrintCurrenciesListDataInFile(List);
				cout << endl;
			}

		cout << "\t------------------------------------------------------------------------------------------------------" << endl;

	}

};
