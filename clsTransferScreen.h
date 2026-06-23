#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";
#include "clsUtility.h";
#include "Global.h";
using namespace std;

class clsTransferScreen :protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "Client Card:" << endl;
		cout << "_____________________________________________" << endl;
		cout << "Full  Name        :" << Client.getFullName() << endl;
		cout << "Acc. Number       :" << Client.AccountNumber() << endl;
		cout << "Balance           :" << Client.GetAccountBalance() << endl;
		cout << "_____________________________________________\n" << endl;

	}

    static string ReadAccountNumber(string massage)
    {
        cout << massage;
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::ClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] already exists,Enter Account Number?";
            AccountNumber = clsInputValidate::ReadString();
        }

        return AccountNumber;
    }

    static double ReadAmount(clsBankClient SourceClient)
    {
        cout << "Enter Transfer Amount ?";
        double Amount = clsInputValidate::ReadDblNumber();


        while (SourceClient.AccountBalance < Amount)
        {
            cout << "Amount Exceeds the available Balance, Enter another Amount? " << Amount << endl;

            cout << "Enter Transfer Amount ?";
            Amount = clsInputValidate::ReadDblNumber();
        }

        return Amount;
    }

public:

    static void ShowTransferScreen()
    {

        _DrawScreenHeader("Transfer Screen");

        string AccountNumber1 = ReadAccountNumber("\nPlease Enter Account Number to Transfer from: ");
        clsBankClient SourceClient = clsBankClient::Find(AccountNumber1);
        _PrintClient(SourceClient);

        string AccountNumber2 = ReadAccountNumber("\nPlease Enter Account Number to Transfer to: ");
        clsBankClient DestinationClient = clsBankClient::Find(AccountNumber2);
        _PrintClient(DestinationClient);

        double Amount = ReadAmount(SourceClient);

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        { 
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.NameUser))
            {
                cout << "\nTransfer done successfully.\n";
            }
            else
            {
                cout << "\nTransfer Faild\n";
            }
           
        }
        
         _PrintClient(SourceClient);
        cout << endl;
        _PrintClient(DestinationClient);
    }
};
