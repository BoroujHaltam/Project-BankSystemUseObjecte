#pragma once
#include<iostream>
#include<vector>
using namespace std;

class clString {
private:
	string _Value;
public:
	clString()
	{
		_Value = "";
	}

	clString(string value)
	{
		_Value = value;
	}

	void SetValue(string value)
	{
		_Value = value;
	}

	string GetValue()
	{
		return _Value;
	}
	
	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string s1)
	{
		return s1.length();
	}
	short Length()
	{
		return  Length(_Value);
	}

	static short CountWords(string S1)
	{

		string delim = " ";  
		short Counter = 0;
		short pos = 0;
		string sWord; 

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); 
			if (sWord != "")
			{
				Counter++;
			}

			
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++; 
		}

		return Counter;

	}
	short CountWords()
	{
		return CountWords(_Value);
	};

	static short CounterEachWordInString(string s1)
	{
		string delet = " ";
		string word;

		short pos = 0;
		short count = 0;

		while ((pos = s1.find(" ")) != std::string::npos)
		{
			word = s1.substr(0, pos);
			if (word != " ")
				count++;

			s1.erase(0, pos + delet.length());
		}

		if (s1[0] != ' ')
		{
			count++;
		}

		return count;
	}
	short CounterEachWordInString()
	{
		return CounterEachWordInString(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{


		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;


		}

		return Counter;

	}

	static int CounterCapitalLetters(string s1)
	{
		int counter = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (isupper(s1[i])) counter++;
		}
		return counter;
	}
	int CounterCapitalLetters()
	{
		return CounterCapitalLetters(_Value);
	}

	static int CounterSmallLetters(string s1)
	{
		int counter = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (islower(s1[i])) counter++;
		}
		return counter;
	}
	int CounterSmallLetters()
	{
		return CounterSmallLetters(_Value);
	}

	static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}

		}

		return Counter;
	}
	short  CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	static bool IsVowel(char c1)
	{
		c1 = tolower(c1);

		return (c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u');
	}
	static int CounterVowels(string s1)
	{
		int counter = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (IsVowel(s1[i])) counter++;
		}
		return counter;
	}
	int CounterVowels()
	{
		return  CounterVowels(_Value);
	}

	static string ToUpper(string s1)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			s1[i] = toupper(s1[i]);
		}
		return s1;
	}
	string ToUpper()
	{
		return ToUpper(_Value);
	}

	static string ToLower(string s1)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			s1[i] = tolower(s1[i]);
		}
		return s1;
	}
	string ToLower()
	{
		return ToLower(_Value);
	}

	static string UpperFirstLetter(string s1)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < s1.length(); i++)
		{
			if (IsFirstLetter && s1[i] != ' ')
				s1[i] = toupper(s1[i]);

			IsFirstLetter = (s1[i] == ' ' ? true : false);
		}
		return s1;
	}
	string UpperFirstLetter() {
		return  UpperFirstLetter(_Value);
	}

	static string TrimLeft(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				return str.substr(i, str.length() - i);
			}
		}
	}
	string TrimLeft()
	{
		return  TrimLeft(_Value);
	}

	static string TrimRighty(string str)
	{
		for (int i = str.length(); i > 0; i--)
		{
			if (str[i] != ' ')
			{
				return str.substr(0, i + 1);
			}
		}
	}
	string TrimRighty()
	{
		return TrimRighty(_Value);
	}

	static string Trim(string str)
	{
		return (TrimLeft(str) + TrimRighty(str));
	}
	string Trim() {
		return Trim(_Value);
	}

	static char InvertCharacter(char c)
	{
		return isupper(c) ? tolower(c) : toupper(c);
	}
	static string InvertAllLetters(string s1)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			s1[i] = InvertCharacter(s1[i]);
		}
		return s1;
	}
	void InvertAllLetters() {
		_Value = InvertAllLetters(_Value);
	}

	static string LowerFirstLetter(string s1)
	{
		bool isfirstletter = true;
		for (int i = 0; i < s1.length(); i++)
		{
			if (isfirstletter && s1[i] != ' ')
				s1[i] = tolower(s1[i]);

			isfirstletter = (s1[i] == ' ' ? true : false);
		}
		return s1;
	}
	string LowerFirstLetter() {
		return  LowerFirstLetter(_Value);
	}

	void PrintAllVowelsInString(string s1)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (IsVowel(s1[i]))
				cout << s1[i] << "   ";
		}
		cout << endl;

	}
	void PrintAllVowelsInString()
	{
		PrintAllVowelsInString(_Value);
	}

	static void PrintEachWordInString(string s1)
	{
		string delet = " ";

		cout << "\nYour string words are: " << endl;
		short pos = 0;
		string word;

		while ((pos = s1.find(" ")) != std::string::npos)
		{
			word = s1.substr(0, pos);
			if (word != " ")
				cout << word << endl;

			s1.erase(0, pos + delet.length());
		}
		if (s1[0] != ' ')
		{
			cout << s1 << endl;
		}
	}
	void PrintEachWordInString()
	{
	  PrintEachWordInString(_Value);
	}

	static void PrintFirstLetter(string str)
	{
		cout << "\nFirst letters of this string: " << endl;
		bool IsFirstLetter = true;
		for (int i = 0; i < str.length(); i++)
		{
			if (IsFirstLetter && str[i] != ' ')
				cout << str.at(i) << endl;

			IsFirstLetter = (str[i] == ' ' ? true : false);

		}
	}
	void PrintFirstLetter() {
		 PrintFirstLetter(_Value);
	}

	static vector<string> Split(string s1, string delmnt)
	{
		string word = "";
		short pos = 0;
		vector<string>vstring;

		while ((pos = s1.find(delmnt)) != std::string::npos)
		{
			word = s1.substr(0, pos);
			if (word != "")
				vstring.push_back(word);

			s1.erase(0, pos + delmnt.length());
		}

		if (s1 != "")
		{
			vstring.push_back(s1);
		}

		return vstring;
	}
	vector<string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	static vector<string> SplitString(vector<string> vstr, string str, string d)
	{
		string word = " ";
		short pos = 0;

		while ((pos = str.find(d)) != std::string::npos)
		{
			word = str.substr(0, pos);

			if (word != " ")
				vstr.push_back(word);

			str.erase(0, pos + d.length());
		}

		if (str[0] != ' ')
		{
			vstr.push_back(str);
		}

		return vstr;
	}

	static string ReversingWord(string str1)
	{
		vector<string> vString;

		vString = SplitString(vString, str1, " ");

		vector<string>::iterator iter = vString.end();
		string str2 = "";

		while (iter != vString.begin())
		{
			--iter;
			str2 += *iter + " ";
		}
		str2 = str2.substr(0, str2.length() - 1);
		return str2;
	}
	string ReversingWord()
	{
		return  ReversingWord(_Value);
	}

	static string AllStringLower(string s1)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			s1[i] = tolower(s1[i]);
		}
		return s1;
	}
	string AllStringLower()
	{
		return  AllStringLower(_Value);
	}

	string RemovePauncution(string s1)
	{
		string s2 = "";

		for (int i = 0; i < s1.length() - 1; i++)
		{
			if (!ispunct(s1[i]))
				s2 += s1[i];
		}

		return s2;
	}
	string RemovePauncution()
	{
		return  RemovePauncution(_Value);
	}

	bool Guess_3letter_password(string word)
	{
		int counter = 0;	string m = "";
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int u = 65; u <= 90; u++)
				{
					counter++;
					m += char(i);
					m += char(j);
					m += char(u);
					cout << "trial[" << counter << "] = " << m << endl;
					if (word == m)
					{
						cout << "password is " << m << endl << " trial(s) " << counter << endl;
						return true;
					}
					m = "";
				}
			}
		}
		return false;
	}
	bool Guess_3letter_password()
	{
		return Guess_3letter_password(_Value);
	}

	static string  UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	void  UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string JoinString(vector<string> vString, string Delim)
	{

		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());


	}
	static string JoinString(string arrString[], short Length, string Delim)
	{

		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}

	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{

		vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (AllStringLower(s) == AllStringLower(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}

		return JoinString(vString, " ");
	}
	string ReplaceWord(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWord(_Value, StringToReplace, sRepalceTo);
	}

	int CounterLetters(string s1, char c, bool IsMatch = true)
	{
		int counter = 0;
		for (int i = 0; i < s1.length(); i++)
		{
			if (IsMatch)
			{
				if (s1[i] == c) counter++;
			}
			else
			{
				if (tolower(s1[i]) == tolower(c))
					counter++;
			}
		}
		return counter;
	}
	int CounterLetters(char c,bool IsMatch)
	{
		return  CounterLetters(_Value, c, IsMatch);
	}



};