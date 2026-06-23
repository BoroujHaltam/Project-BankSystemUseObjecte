#pragma once
#include <iostream>  
#include <string>
#include<cstdlib>
#include"clsDate.h";
#include"clsString.h";
using namespace std;

class clUtility
{
public:

	enum Random { Schar = 1, Cchar = 2, Spchar = 3, Digit = 4, MixChars = 5 };

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int from, int to)
	{
		int random = rand() % (to - from + 1) + from;
		return random;
	}

	static char GetRandomSizeLetter(Random a)
	{
		if (a == MixChars)
		{
			a = (Random)RandomNumber(1, 3);
		}

		switch (a)
		{
		case Schar:return char(RandomNumber(97, 122));
			break;
		case Cchar:return char(RandomNumber(65, 90));
			break;
		case Spchar:return char(RandomNumber(33, 47));
			break;
		case Digit:return char(RandomNumber(48, 57));
			break;
		default:
			return char(RandomNumber(65, 90));
			break;
		}
	}
	
	static string GenerateWord(Random a, short longWord)
	{
		string Word = "";
		for (int i = 0; i < longWord; i++)
		{
			Word += GetRandomSizeLetter(a);
		}
		return Word;
	}
	
	static string  GenerateKey(Random CharType = Cchar)
	{

		string Key = "";


		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);


		return Key;
	}

    static void GenerateKeys(short NumberOfKeys, Random CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, Random CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, Random CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDate(A, B);

    }

    static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string  EncryptText(string Text, short EncryptionKey=2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey=2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }
   
    static string NumberToString(int number)
	{
		if (number == 0) return " ";

		if (number >= 1 && number <= 19)
		{
			string arr[] = { "","One","Two","Three","Four","Five","Six","Seven",
				"Eight","Nine","Ten","Eleven","Twelve","Thirteen" ,"Fourteen"
				,"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[number] + " ";
		}
		else if (number >= 20 && number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty",
				"Fifty","Sixty","Seventy","Eighty","Ninety" };
			return arr[number / 10] + " " + NumberToString(number % 10);
		}
		else if (number >= 100 && number <= 199)
		{
			return " One Hundred " + NumberToString(number % 100);
		}
		else if (number >= 200 && number <= 999)
		{
			string arr[] = { "","","Two Hundreds","Three Hundreds","Four Hundreds",
				"Five Hundreds","Six Hundreds","Seven Hundreds","Eight Hundreds","Nine Hundreds" };
			return arr[number / 100] + " " + NumberToString(number % 100);
		}
		else if (number >= 1000 && number <= 1999)
		{
			return " One Thousand " + NumberToString(number % 1000);
		}
		else if (number >= 2000 && number <= 999999)
		{
			string arr[] = { "","","Two Thousands","Three Thousands","Four Thousands",
				"Five Thousands","Six Thousands","Seven Thousands","Eight Thousands","Nine Thousands" };
			return NumberToString(number / 1000) + " " + NumberToString(number % 1000);
		}
		else if (number >= 1000000 && number <= 1999999)
		{
			return " One Million " + NumberToString(number % 1000000);
		}
		else if (number >= 2000000 && number <= 999999999)
		{
			string arr[] = { "","","Two Millions","Three Millions","Four Millions",
				"Five Millions","Six Millions","Seven Millions","Eight Millions","Nine Millions" };
			return NumberToString(number / 1000000) + " " + NumberToString(number % 1000000);
		}
		else if (number >= 1000000000 && number <= 1999999999)
		{
			return " One Billion " + NumberToString(number % 1000000000);
		}
		else
		{
			return NumberToString(number / 1000000000) + "Billions " + NumberToString(number % 1000000000);
		}

	}


};

