#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h";
using namespace std;

class clsCurrency
{
private:
	enum enMode { EmptyMode = 1, UpdateMode = 2 };
	enMode _Mode;

	string _Country;
	string _CurrencyCody;
	string _CurrencyName;
	float _Rate;

	static string _ConvertCurrencyObjectToLine(clsCurrency data, string seperator = "#//#")
	{
		string str = "";

		str += data.Country() + seperator;
		str += data.CurrencyCode() + seperator;
		str += data.CurrencyName() + seperator;
		str += to_string(data.Rate());

		return str;
	}

	static clsCurrency  _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vData;
		vData = clString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vData[0], vData[1], vData[2], stof(vData[3]));
	}

	static vector<clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector<clsCurrency> vCurrencies;

		fstream Currency;
		Currency.open("Currencies.txt", ios::in);

		if (Currency.is_open())
		{
			string line;
			while (getline(Currency, line))
			{
				clsCurrency data = _ConvertLineToCurrencyObject(line, "#//#");

				vCurrencies.push_back(data);
			}
			Currency.close();
		}
		return vCurrencies;
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> vData)
	{
		fstream Data;
		Data.open("Currencies.txt", ios::out);

		if (Data.is_open())
		{
			string line;

			for (clsCurrency d : vData)
			{
				line = _ConvertCurrencyObjectToLine(d, "#//#");
				Data << line << endl;
			}
			Data.close();
		}
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	void _Update()
	{
		vector<clsCurrency> vCurrencies;
		vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (CurrencyCode() == C.CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencies);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCody, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCody = CurrencyCody;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCody;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	float Rate()
	{
		return _Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C = clsCurrency::FindByCode(CurrencyCode);
		return (!C.IsEmpty());
	}

	static vector<clsCurrency> GetCurrencyList()
	{
		return _LoadCurrencyDataFromFile();
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.Rate());
	}

};
