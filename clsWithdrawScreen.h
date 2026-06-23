#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";
using namespace std;

class clsWithdrawScreen :protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.getFirstName();
        cout << "\nLastName    : " << Client.getLastName();
        cout << "\nFull Name   : " << Client.getFullName();
        cout << "\nEmail       : " << Client.getEmail();
        cout << "\nPhone       : " << Client.getPhone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:

    static void _ShowWithdrawScreen()
    {
        _DrawScreenHeader("Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::ClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Withdraw(Amount))
            {
                cout << "\nAmount withdraw Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.AccountBalance;
            }
            else
            {
                cout << "\n Cannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmount to withdraw is: " << Amount;
                cout << "\nYour Balance Is: " << Client1.AccountBalance;
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }

};