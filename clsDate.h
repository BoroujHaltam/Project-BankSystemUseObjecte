#pragma warning(disable:4996)
#pragma once

#include<iostream>
#include<string>
#include"clsString.h";
using namespace std;

enum enDate { Before = -1, Equal = 0, After = 1 };

class clsDate {
private:
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}
	clsDate(string sDate)
	{
		vector<string>vDate;
		vDate = clString::Split(sDate, "/");
		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}
	clsDate(short day,short month,short year) {
		_Day = day;
		_Month = month;
		_Year = year;
	}
	clsDate(short DateOrderINYear,short year)
	{
		clsDate _date = DateFromDayOrderInYear(DateOrderINYear,year);
		_Day = _date._Day;
		_Month = _date._Month;
		_Year = _date._Year;
	}

	void SetDay(short day)
	{
		_Day = day;
	}
	short GetDay()
	{
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short _Day;

	void SetMonth(short month)
	{
		_Month = month;
	}
	short GetMonth(short month)
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short _Month;

	void SetYear(short year)
	{
		_Year = year;
	}
	short GetYear(short year)
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short _Year;

	void Print()
	{
		cout << DateToString() << endl;
	}
	
	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		short Day, Month, Year;

		Day = now->tm_mday;
		Month = now->tm_mon + 1;
		Year = now->tm_year + 1900;

		return clsDate(Day,Month, Year);

	}

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		short Day, Month, Year;
		short Hour, Minute, Second;

		Day = now->tm_mday;
		Month = now->tm_mon + 1;
		Year = now->tm_year + 1900;

		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year)+"-"
			+ to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second);
		
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}
	string DateToString()
	{
		return DateToString(*this);
	}

	static bool IsValidDate(clsDate validDate)
	{
		return NumberOfDaysInMonth(validDate._Month, validDate._Year) == validDate._Day
			&& (validDate._Month <= 12 && validDate._Month >= 1);
	}
	bool IsValid() {
		return  IsValidDate(*this);
	}

	static bool IsLeapYear(int year)
	{
		return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
	}
	bool IsLeapYear()
	{
		return  IsLeapYear(_Year);
	}

	static int NumberOfDaysInYear(int month, int year)
	{
		if (month < 1 && month>12)
			return 0;
		else if (month == 2)
			return IsLeapYear(year) ? 29 : 28;

		int arr30Days[4] = { 4,6,9,11 };

		for (int i = 0; i < 4; i++)
		{
			if (month == arr30Days[i]) return 30;
		}

		return 31;
	}
	int NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Month,_Year);
	}

	static int NumberOfHoursInYear(int month, int year)
	{
		return NumberOfDaysInYear(month, year) * 24;
	}
	int NumberOfHoursInYear()
	{
		return  NumberOfHoursInYear(_Month,_Year);
	}

	static int NumberOfMinutesInYear(int month, int year)
	{
		return NumberOfHoursInYear(month, year) * 60;
	}
	int NumberOfMinutesInYear()
	{
		 return NumberOfMinutesInYear(_Month,_Year);
	}

	static int NumberOfSecondsInYear(int month, int year)
	{
		return NumberOfMinutesInYear(month, year) * 60;
	}
	int NumberOfSecondsInYear()
	{
		return  NumberOfSecondsInYear(_Month,_Year);
	}

	static int NumberOfDaysInMonth(int month, int year)
	{
		if (month <= 1 || month >= 12) return 0;

		int ArrNumberOfDays[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };

		return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : ArrNumberOfDays[month];
	}
	int NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month,_Year);
	}

	static int NumberOfHoursInMonth(int month, int year)
	{
		return NumberOfDaysInMonth(month, year) * 24;
	}
	int NumberOfHoursInMonth(){
		return NumberOfHoursInMonth(_Month, _Year);
	}

	static int NumberOfMinutesInMonth(int month, int year)
	{
		return NumberOfHoursInMonth(month, year) * 60;
	}
	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Month, _Year);
	}

	static void  SwapDates(clsDate& Date1, clsDate& Date2)
	{

		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}

	static int NumberOfSecondsInMonth(int month, int year)
	{
		return NumberOfMinutesInMonth(month, year) * 60;
	}
	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Month, _Year);
	}

	static int DayOrder(int day, int month, int year)
	{
		int a = (14 - month) / 12;

		int y = year - a;
		int m = month + 12 * a - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	static int DayOrder(clsDate date)
	{
		return DayOrder(date._Day, date._Month, date._Year);
	}
	int DayOrder()
	{
		return DayOrder(_Day,_Month, _Year);
	}

	static string DayName(int DayOrder)
	{
		string ArrDayName[7] = { "Sun", "Mon", "Tue" , "Wed", "Thu", "Fri", "Sat" };

		return ArrDayName[DayOrder];
	}
	static string DayName(int day,int month,int year)
	{
		string ArrDayName[7] = { "Sun", "Mon", "Tue" , "Wed", "Thu", "Fri", "Sat" };

		return ArrDayName[DayOrder(day,month,year)];
	}
	string DayName()
	{
		return DayName();
	}

	static string MonthName(int MonthNumber)
	{
		string ArrMonthName[13] = { "","Jan", "Feb", "Mar" , "Apr", "May", "Jun", "Jul" ,"Aug","Sep","Oct","Nov","Dec" };

		return ArrMonthName[MonthNumber];
	}
	string MonthName()
	{
		return MonthName(_Month);
	}

	static void PrintCalendarMonth(int month, int year)
	{
		int order = DayOrder(1, month, year);
		int numberOfday = NumberOfDaysInMonth(month, year);

		cout<<"________________"<< MonthName(month).c_str() <<"________________\n";

		printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat \n");

		int i;
		for (i = 0; i < order; i++)
			printf("     ");

		for (int j = 1; j <= numberOfday; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n____________________________________\n");
	}
	void PrintCalendarMonth()
	{
		 PrintCalendarMonth(_Month, _Year); 
	}

	static void PrintCalendarYear(int year)
	{
		printf("\n___________________________________________");
		printf("\n\n               Calendar - %d", year);
		printf("\n___________________________________________\n\n");


		for (int i = 1; i < 13; i++)
		{
			PrintCalendarMonth(i, year);
			printf("\n");
		}

	}
	void PrintCalendarYear()
	{
		printf("\n___________________________________________");
		printf("\n\n               Calendar - %d", _Year);
		printf("\n___________________________________________\n\n");


		for (int i = 1; i < 13; i++)
		{
			PrintCalendarMonth(i, _Year);
			printf("\n");
		}

	}

	static short DaysFromTheBeginningOfYear(short day, short month, short year)
	{
		short sum = 0;

		for (short i = 1; i < month; i++)
		{
			sum += NumberOfDaysInMonth(i, year);
		}
		sum += day;

		return sum;
	}
	short DaysFromTheBeginningOfYear()
	{
		return DaysFromTheBeginningOfYear(_Day,_Month,_Year);
	}

	static clsDate DateFromDayOrderInYear(short NumOfDays, short year)
	{
		short Ramind = NumOfDays;
		short numMonth;

		clsDate date;
		date._Month = 1;
		date._Year = year;

		while (true)
		{
			numMonth = NumberOfDaysInMonth(date._Month, date._Year);

			if (Ramind > numMonth)
			{
				Ramind -= numMonth;
				date._Month++;
			}
			else
			{
				date._Day = Ramind;
				break;
			}
		}

		return date;
	}
	
	void AddDays(short Days)
	{
		short RemainDays = Days + DaysFromTheBeginningOfYear(_Day, _Month, _Year);
		short MonthDays = 0;

		_Month = 1;
		while (true)
		{
			MonthDays= NumberOfDaysInMonth(_Month, _Year);

			if (RemainDays > MonthDays)
			{
				RemainDays -= MonthDays;
				_Month++;

				if (_Month > 12)
				{
					_Month > 1;
					_Year++;
				}
			}
			else
			{
				_Day = RemainDays;
				break;
			}
		}
	}
	void AddDays()
	{
		AddDays(_Day);
	}

	static short DaysAfterAdd(short numAdd, clsDate date)
	{
		short sumDay = DaysFromTheBeginningOfYear(date._Day, date._Month, date._Year);
		sumDay += numAdd;
		return sumDay;
	}
	
	static bool IsDate1LessDate2(clsDate date1, clsDate date2)
	{
		return (date1._Year < date2._Year) ? true : (date1._Month < date2._Month) ? true : (date1._Day < date2._Day);

	}
	bool IsDate1LessDate2(clsDate date2)
	{
		return IsDate1LessDate2(*this, date2);
	}

	static bool IsDate1EqualsDate2(clsDate date1, clsDate date2)
	{
		return (date1._Year == date2._Year) ? ((date1._Month == date2._Month) ? (date1._Day == date2._Day) : false) : false;

	}
	bool IsDate1EqualsDate2(clsDate date2)
	{
		return IsDate1EqualsDate2(*this, date2);
	}

	static bool IsLastMonthInYear(clsDate date)
	{
		return  (date._Month == 12);
	}
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(*this);
	}

	static bool IsLastDayInMonth(clsDate date1)
	{
		return  (NumberOfDaysInMonth(date1._Month, date1._Year) == date1._Day);

	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year
			==
			Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month ==
				Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}
	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool Date1IsAfterDate2(clsDate date1, clsDate date2)
	{
		return (!IsDate1BeforeDate2(date1, date2) && IsDate1EqualsDate2(date1, date2));
	}
	bool Date1IsAfterDate2(clsDate date2)
	{
		return Date1IsAfterDate2(*this, date2);
	}

	static clsDate AddOneDay(clsDate date)
	{
		if (IsLastDayInMonth(date))
		{
			date._Day = 1;
			if (IsLastDayInMonth(date))
			{
				date._Month = 1;
				date._Year++;
			}
			else
				date._Month++;
		}
		else
			date._Day++;

		return date;
	}
	clsDate AddOneDay()
	{
		return AddOneDay(*this);
	}

	static int GetDiffInDays(clsDate date1, clsDate date2, bool IncludingEndDay = false)
	{
		int day = 0;

		while (IsDate1LessDate2(date1, date2))
		{
			date1 = AddOneDay(date1);
			day++;
		}

		return IncludingEndDay ? ++day : day;
	}
	int GetDiffInDays(clsDate date2, bool IncludingEndDay = false)
	{
		return GetDiffInDays(*this, date2, IncludingEndDay);
	}

	static void  SwapDate(clsDate& date1, clsDate& date2)
	{
		clsDate TempleDate;

		TempleDate= date1;
		date1 = date2;
		date2= TempleDate;

	}
	
	/*static int CalculateMyAgeInDays(clDate DateOfBirth)
	{
		return GetDiffInDays(DateOfBirth, clDate::GetSystemDate, true);
	}*/


	static int DiffInDaysNegative(clsDate date1, clsDate date2, bool IncludingEndDay = false)
	{
		int day = 0;
		int flage = 1;

		if (!IsDate1LessDate2(date1, date2))
		{
			SwapDate(date1, date2);
			flage = -1;
		}

		while (IsDate1LessDate2(date1, date2))
		{
			date1 = AddOneDay(date1);
			day++;
		}

		return IncludingEndDay ? ++day * -1 : day * -1;
	}
	int DiffInDaysNegative(clsDate date2, bool IncludingEndDay = false)
	{
		return DiffInDaysNegative(*this, date2, IncludingEndDay);
	}

	static clsDate IncreaseDateByXDays(clsDate date, short numDay)
	{
		for (int i = 0; i < numDay; i++)
		{
			date = AddOneDay(date);
		}

		return date;
	}
	clsDate IncreaseDateByXDays(short numDay)
	{
		return IncreaseDateByXDays(*this, numDay);
	}

	static clsDate IncreaseDateByOneWeek(clsDate date)
	{
		date = IncreaseDateByXDays(date, 7);
		return date;
	}
	clsDate IncreaseDateByOneWeek()
	{
		return IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate date, short numWeek)
	{
		for (int i = 0; i < numWeek; i++)
		{
			date = IncreaseDateByOneWeek(date);
		}

		return date;
	}
	clsDate IncreaseDateByXWeeks(short numWeek)
	{
		return IncreaseDateByXWeeks(*this, numWeek);
	}

	static clsDate IncreaseDateByOneMonth(clsDate date)
	{
		if (IsLastDayInMonth(date))
		{
			date._Month = 1;
			date._Year++;
		}
		else
			date._Month++;

		short numOfDays = NumberOfDaysInMonth(date._Month, date._Year);

		if (date._Day > numOfDays)
		{
			date._Day = numOfDays;
		}


		return date;
	}
	clsDate IncreaseDateByOneMonth()
	{
		return IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate date, short numMonth)
	{
		for (int i = 0; i < numMonth; i++)
		{
			date = IncreaseDateByOneMonth(date);
		}
		return date;
	}
	clsDate IncreaseDateByXMonths(short numMonth)
	{
		return IncreaseDateByXMonths(*this,numMonth);
	}

	static clsDate IncreaseDateByOneYear(clsDate date)
	{
		date._Year++;
		return date;
	}
	clsDate IncreaseDateByOneYear()
	{
		return IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(clsDate date, short numYear)
	{
		for (int i = 0; i < numYear; i++)
		{
			date = IncreaseDateByOneYear(date);
		}
		return date;
	}
	clsDate IncreaseDateByXYears(short numMonth)
	{
		return IncreaseDateByXYears(*this, numMonth);
	}

	static clsDate IncreaseDateByYearsFaster(clsDate date, short numYear)
	{
		date._Year += numYear;
		return date;
	}
	clsDate IncreaseDateByYearsFaster(short numYear)
	{
		return IncreaseDateByYearsFaster(*this, numYear);
	}

	static clsDate IncreaseDateByOneDecade(clsDate date)
	{
		date._Year += 10;
		return date;
	}
	clsDate IncreaseDateByOneDecade()
	{
		return IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(clsDate date, short numDecad)
	{
		for (int i = 0; i < numDecad; i++)
		{
			date = IncreaseDateByOneDecade(date);
		}
		return date;
	}
	clsDate IncreaseDateByXDecades(short numDecad)
	{
		return IncreaseDateByXDecades(*this, numDecad);
	}

	static clsDate IncreaseDateByDecadesFaster(clsDate date, short numDecad)
	{
		date._Year += numDecad * 10;
		return date;
	}
	clsDate IncreaseDateByDecadesFaster(short numDecad)
	{
		return IncreaseDateByDecadesFaster(*this, numDecad);
	}

	static clsDate IncreaseDateByOneCentury(clsDate date)
	{
		date._Year += 100;
		return date;
	}
	clsDate IncreaseDateByOneCentury()
	{
		return IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate date)
	{
		date._Year += 1000;
		return date;
	}
	clsDate IncreaseDateByOneMillennium()
	{
		return IncreaseDateByOneMillennium(*this);
	}

	static bool IsFirstMonthInYear(clsDate date)
	{
		return  (date._Month == 1);
	}
	bool IsFirstMonthInYear()
	{
		return IsFirstMonthInYear(*this);
	}

	static bool IsFirstDayInMonth(clsDate date1)
	{
		return  (1 == date1._Day);

	}
	bool IsFirstDayInMonth()
	{
		return IsFirstDayInMonth(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate date)
	{
		if (IsFirstDayInMonth(date))
		{
			date._Day = NumberOfDaysInMonth(date._Month, date._Year);
			if (IsFirstMonthInYear(date))
			{
				date._Month = 12;
				date._Year--;
			}
			else
				date._Month--;
		}
		else
			date._Day--;

		return date;
	}
	clsDate DecreaseDateByOneDay()
	{
		return DecreaseDateByOneDay(*this);
	} 

	static clsDate DecreaseDateByXDays(clsDate date, short numDay)
	{
		for (int i = 1; i <= numDay; i++)
		{
			date = DecreaseDateByOneDay(date);
		}

		return date;
	}
	clsDate DecreaseDateByXDays(short numDay)
	{
		return DecreaseDateByXDays(*this ,numDay);
	}

	static clsDate DecreaseDateByOneWeek(clsDate date)
	{
		date = DecreaseDateByXDays(date, 7);
		return date;
	}
	clsDate DecreaseDateByOneWeek()
	{
		return DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate date, short numWeek)
	{
		for (int i = 1; i <= numWeek; i++)
		{
			date = DecreaseDateByOneWeek(date);
		}

		return date;
	}
	clsDate DecreaseDateByXWeeks(short numWeek)
	{
		return DecreaseDateByXWeeks(*this, numWeek);
	}

	static clsDate DecreaseDateByOneMonth(clsDate date)
	{
		if (IsFirstMonthInYear(date))
		{
			date._Month = 12;
			date._Year--;
		}
		else
			date._Month--;

		short numOfDays = NumberOfDaysInMonth(date._Month, date._Year);

		if (date._Day > numOfDays)
		{
			date._Day = numOfDays;
		}


		return date;
	}
	clsDate DecreaseDateByOneMonth()
	{
		return DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate date, short numMonth)
	{
		for (int i = 0; i < numMonth; i++)
		{
			date = DecreaseDateByOneMonth(date);
		}
		return date;
	}
	clsDate DecreaseDateByXMonths(short numMonth)
	{
		return DecreaseDateByXMonths(*this, numMonth);
	}

	static clsDate DecreaseDateByOneYear(clsDate date)
	{
		date._Year--;
		return date;
	}
	clsDate DecreaseDateByOneYear()
	{
		return DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate date, short numYear)
	{
		for (int i = 0; i < numYear; i++)
		{
			date = DecreaseDateByOneYear(date);
		}
		return date;
	}
	clsDate DecreaseDateByXYears(short numYear)
	{
		return DecreaseDateByXYears(*this, numYear);
	}

	static clsDate DecreaseDateByYearsFaster(clsDate date, short numYear)
	{
		date._Year -= numYear;
		return date;
	}
	clsDate DecreaseDateByYearsFaster(short numYear)
	{
		return DecreaseDateByYearsFaster(*this, numYear);
	}

	static clsDate DecreaseDateByOneDecade(clsDate date)
	{
		date._Year -= 10;
		return date;
	}
	clsDate DecreaseDateByOneDecade()
	{
		return DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate date, short numDecad)
	{
		for (int i = 0; i < numDecad; i++)
		{
			date = DecreaseDateByOneDecade(date);
		}
		return date;
	}
	clsDate DecreaseDateByXDecades(short numDecad)
	{
		return DecreaseDateByXDecades(*this, numDecad);
	}

	static clsDate DecreaseDateByDecadesFaster(clsDate date, short numDecad)
	{
		date._Year -= numDecad * 10;
		return date;
	}
	clsDate DecreaseDateByDecadesFaster(short numDecad)
	{
		return DecreaseDateByDecadesFaster(*this, numDecad);
	}

	static clsDate DecreaseDateByOneCentury(clsDate date)
	{
		date._Year -= 100;
		return date;
	}
	clsDate DecreaseDateByOneCentury()
	{
		return DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate date)
	{
		date._Year -= 1000;
		return date;
	}
	clsDate DecreaseDateByOneMillennium()
	{
		return DecreaseDateByOneMillennium(*this);
	}

	static bool IsEndOfWeek(short orderDay)
	{
		return orderDay == 6;
	}
	bool IsEndOfWeek()
	{
		return  IsEndOfWeek(_Day);
	}

	static bool IsWeekend(short orderDay)
	{
		return orderDay == 6 || orderDay == 5;
	}
	bool IsWeekend()
	{
		return  IsWeekend(_Day);
	}

	static bool IsBusinessDay(short orderDay)
	{
		return !IsWeekend(orderDay);
	}
	static bool IsBusinessDay(clsDate date1)
	{
		return !(IsWeekend(DayOrder(date1._Day, date1._Month, date1._Year)));
	}
	bool IsBusinessDay()
	{
		return  IsBusinessDay(_Day);
	}

	static short DaysUntilTheEndOfWeek(short orderDay)
	{
		return 6 - orderDay;
	}
	bool DaysUntilTheEndOfWeek()
	{
		return  DaysUntilTheEndOfWeek(_Day);
	}

	static short DaysUntilTheEndOfMonth(clsDate date)
	{
		clsDate EndMonth;
		EndMonth._Day = NumberOfDaysInMonth(date._Month, date._Year);
		EndMonth._Month = date._Month;
		EndMonth._Year = date._Year;

		return GetDiffInDays(date, EndMonth, true);
	}
	bool DaysUntilTheEndOfMonth()
	{
		return  DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate date)
	{
		clsDate EndYear;
		EndYear._Day = 31;
		EndYear._Month = 12;
		EndYear._Year = date._Year;

		return GetDiffInDays(date, EndYear, true);
	}
	bool DaysUntilTheEndOfYear()
	{
		return  DaysUntilTheEndOfYear(*this);
	}

	static short CalculateVacation(clsDate order1, clsDate order2)
	{
		short counter = 0;

		while (!IsDate1EqualsDate2(order1, order2))
		{
			if (IsBusinessDay(order1))
				counter++;

			order1 = AddOneDay(order1);
		}

		return counter;
	}
	short CalculateVacation(clsDate Date2)
	{
		return CalculateVacation(*this, Date2);
	}

	static enDate CompareDate(clsDate date1, clsDate date2)
	{
		return IsDate1EqualsDate2(date1, date2) ? enDate::Equal : IsDate1BeforeDate2(date1, date2) ? enDate::Before : enDate::After;
	}
	enDate CompareDate(clsDate date2)
	{
		return CompareDate(*this, date2);
	}

	static clsDate CalculateVacationReturn(clsDate DateFrom, short numRet)
	{
		short weekEndCounter = 0;

		while (IsWeekend(DayOrder(DateFrom._Day, DateFrom._Month, DateFrom._Year)))
		{
			weekEndCounter++;
			DateFrom = AddOneDay(DateFrom);
		}

		for (int i = 1; i < numRet; i++)
		{
			if (IsBusinessDay(DateFrom))
				i--;

			DateFrom = AddOneDay(DateFrom);
		}

		return DateFrom;
	}
	clsDate CalculateVacationReturn(short numRet)
	{
		return CalculateVacationReturn(*this,numRet);
	}


};
