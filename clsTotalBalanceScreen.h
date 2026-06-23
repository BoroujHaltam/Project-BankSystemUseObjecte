#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";
#include "clsUtility.h";
using namespace std;

class clsTotalBalanceScreen :protected clsScreen
{
private:

    static void _PrintBalanceRecordLine(clsBankClient Client)
    {
        cout << "\t\t\t\t    | " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(15) << left << Client.getFullName();
        cout << "| " << setw(15) << left << Client.AccountBalance;
    }

public:

    static void ShowTotalBalancesScreen()
    {
        vector<clsBankClient> vDataFile = clsBankClient::GetClientsList();

        _DrawScreenHeader("Total Balances Screen", "Balances List(" +to_string(vDataFile.size()) + ") Client(s). ");

        cout << "\t\t\t\t   -----------------------------------------------" << endl;

        cout << "\n\t\t\t\t    | " << setw(15) << left << "Account Number";
        cout << "| " << setw(15) << left << "Client Name";
        cout << "| " << setw(15) << left << "Balance" << endl;

        cout << "\n\t\t\t\t   -----------------------------------------------" << endl;

        double total = clsBankClient::GetTotalBalances();

        if (vDataFile.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
            for (clsBankClient Client : vDataFile)
            {
                _PrintBalanceRecordLine(Client);
                cout << endl;
            }
        cout << "\n\t\t\t\t    -----------------------------------------------" << endl;

        cout << "\t\t\t\t    Total Balances = " << total << endl;
        cout << "\t\t\t\t\t   (" << clUtility::NumberToString((int)total) << ")" << endl;

    }
};
