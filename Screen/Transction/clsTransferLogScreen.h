#pragma once
#include<iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";
#include "clsUtility.h";
#include "Global.h";
using namespace std;

class clsTransferLogScreen :protected clsScreen
{
private:

	static void PrintTransferRecordLine(clsBankClient::stTrnsferLogRecord Record)
	{
		cout << "\t| " << Record.DateTime;
		cout << "\t| " << Record.sAccount;
		cout << "\t | " << Record.dAccount;
		cout << "\t | " << Record.Amount;
		cout << "\t | " << Record.sBalance;
		cout << "\t | " << Record.dBalance;
		cout << "\t | " << Record.UserName;
		
	}

public:
	static void ShowLoginTransferScreen()
	{

		system("cls");
		vector<clsBankClient::stTrnsferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

		string SubTitle = "(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		clsScreen::_DrawScreenHeader("\n\t\t\t\t\t\tTransfer Log List Screen", SubTitle);

		cout << "\n\n\t-----------------------------------------------------------------------------------------------------" << endl;

		cout << "\t| " << "Date/Time";
		cout << "\t\t| " << "s.Account";
		cout << " | " << "d.Account";
		cout << " | " << "Amount";
		cout << " | " << "s.Balance";
		cout << " | " << "d.Balance";
		cout << " | " << "User Name"<<endl;

		cout << "\t----------------------------------------------------------------------------------------------------" << endl;


		if (vTransferLogRecord.size() == 0)
			cout << "\t\t\t\tTransfers Available In the System!";
		else
			for (clsBankClient::stTrnsferLogRecord Record : vTransferLogRecord)
			{
				PrintTransferRecordLine(Record);
				cout << endl;
			}
		cout << "\t----------------------------------------------------------------------------------------------------" << endl;
	}
};
