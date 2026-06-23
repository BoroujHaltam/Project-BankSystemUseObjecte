#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;

class clsInputValidate {
public:
	static bool IsNumberBetween(int number, int from, int to)
	{
		return from <= number && number <= to;
	}

	static bool IsNumberBetween(double number, double from, double to)
	{
		return from <= number && number <= to;
	}

	static bool IsNumberBetween(float number, float from, float to)
	{
		return from <= number && number <= to;
	}

	static bool IsNumberBetween(short number, short from, short to)
	{
		return from <= number && number <= to;
	}

	static bool IsDateBetween(clsDate now, clsDate from, clsDate to)
	{
		//now>=from && now<=to
		if ((clsDate::Date1IsAfterDate2(now, from) || clsDate::IsDate1EqualsDate2(now, from))
			&& (clsDate::IsDate1BeforeDate2(now, to) || clsDate::IsDate1EqualsDate2(now, to)))
		{
			return true;
		}


		//now<=from && now>=to
		 if ((clsDate::IsDate1BeforeDate2(now, from) || clsDate::IsDate1EqualsDate2(now, from)) 
			&& (clsDate::Date1IsAfterDate2(now,to) || clsDate::IsDate1EqualsDate2(now, to)))
		 {
			 return true;
		 }

		
		return false;
	}

	static int ReadIntNumber(string massage="Invalid Number, Enter again\n")
	{
		int number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << massage << endl;
		}
		return number;
	}

	static double ReadDblNumber(string massage = "Invalid Number, Enter again\n")
	{
		double number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << massage << endl;
		}
		return number;
	}

	static float ReadFloatNumber(string massage = "Invalid Number, Enter again\n")
	{
		float number;
		while (!(cin >> number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << massage << endl;
		}
		return number;
	}

	static int ReadIntNumberBetween(int from, int to, string massage= "Invalid Number, Enter again\n")
	{
		int num = ReadIntNumber(massage);
		while (!IsNumberBetween(num, from, to))
		{
			cout << massage;
			num = ReadIntNumber();
		}
		return num;
	}

	static double ReadDblNumberBetween(double from, double to, string massage= "Invalid Number, Enter again\n")
	{
		double num = ReadDblNumber(massage);
		
		while (!IsNumberBetween(num, from, to))
		{
			cout << massage;
			num = ReadIntNumber();
		}
		
		return num;
	}

	static bool IsValidDate(clsDate now)
	{
		return clsDate::IsValidDate(now);
	}

	static string ReadString()
	{
		string str;
		getline(cin>>ws, str);
		return str;
	}

};






















