#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h";
#include"clsPerson.h";
using namespace std;

class clsBankClient :public clsPerson
{
private:
	enum enMode{EmptyMode=0, UpdateMode=1, AddNewMode=2};
	enMode _Mode;
	
	string _NameFile = "Clients.txt";
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete =false;

	static string _ConvertClientObjectToLine(clsBankClient data, string seperator="#//#")
	{
		string str = "";
		str += data._AccountNumber + seperator;
		str +=data._PinCode + seperator;
		str += data.getFirstName() + seperator;
		str += data.getLastName() + seperator;
		str += data.getEmail() + seperator;
		str += data.getPhone() + seperator;
		str += to_string(data._AccountBalance);
		return str;
	}

	static clsBankClient  _ConvertLineToClientObject(string Line, string Seperator="#//#")
	{
		vector<string> vClientData;
		vClientData = clString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode,vClientData[0], vClientData[1], vClientData[2],
			vClientData[3],vClientData[4], vClientData[5],stod(vClientData[6]));
	}
	
	static vector<clsBankClient> _LoadClientsDataFromFile(string NameFile)
	{
		vector<clsBankClient> vClient;

		fstream Client;
		Client.open(NameFile, ios::in);

		if (Client.is_open())
		{
			string line;
			while (getline(Client, line))
			{
				clsBankClient data = _ConvertLineToClientObject(line, "#//#");

				vClient.push_back(data);
			}
			Client.close();
		}
		return vClient;
	}

	static void _SaveCleintsDataToFile(vector<clsBankClient> vData)
	{
		fstream Data;
		Data.open("Clients.txt", ios::out);

		if (Data.is_open())
		{
			string line;

			for (clsBankClient d : vData)
			{
				if (d._MarkForDelete == false)
				{
					line = _ConvertClientObjectToLine(d, "#//#");
					Data << line << endl;
				}
			}
			Data.close();
		}
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "","", "", "", "", "", 0);
	}

	void _Update()
	{
		vector<clsBankClient> vClient;
		vClient = _LoadClientsDataFromFile(_NameFile);

		for (clsBankClient& C : vClient)
		{
			if (_AccountNumber == C.AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(vClient);
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	string _PrepareTransferLogInRecord(double Amount, clsBankClient DestinationClient,string UserName,string seperator = "#//#")
	{
		string TransferLogRecord = "";

		TransferLogRecord += clsDate::GetSystemDateTimeString() + seperator;
		TransferLogRecord += AccountNumber() + seperator;
		TransferLogRecord += DestinationClient.AccountNumber() + seperator;
		TransferLogRecord += to_string(Amount) + seperator;
		TransferLogRecord += to_string(AccountBalance) + seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + seperator;
		TransferLogRecord +=UserName;

		return TransferLogRecord;
	}

	void _RegisterTransferLog(double Amount, clsBankClient DestinationClient,string UserName )
	{
		string stDataline = _PrepareTransferLogInRecord(Amount, DestinationClient,UserName);

		fstream File;
		File.open("TransferLog.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << stDataline << endl;

			File.close();
		}
	}

	struct stTrnsferLogRecord;
	static stTrnsferLogRecord  _ConvertLoginTransferLineToRecord(string Line, string Seperator = "#//#")
	{
		stTrnsferLogRecord LoginRegisterRecord;
		vector<string> vUserData = clString::Split(Line, Seperator);

		LoginRegisterRecord.DateTime = vUserData[0];
		LoginRegisterRecord.sAccount = vUserData[1];
		LoginRegisterRecord.dAccount = vUserData[2];
		LoginRegisterRecord.Amount = stod(vUserData[3]);
		LoginRegisterRecord.sBalance = stod(vUserData[4]);
		LoginRegisterRecord.dBalance = stod(vUserData[5]);
		LoginRegisterRecord.UserName = vUserData[6];

		return LoginRegisterRecord;
	}

public:
	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1 , svFaildAccountNumberExists=2};

	struct stTrnsferLogRecord
	{
		string DateTime;
		string sAccount, dAccount;
		double Amount;
		string UserName;
		double sBalance, dBalance;
		
	}; 

	clsBankClient(enMode Mode, string Accountnumber, string PinCode,
		string FirstName, string LastName,string Email,string Phone, 
		float AccountBalance) : clsPerson(FirstName,LastName,Email,Phone)
	{
		_Mode = Mode; _AccountNumber = Accountnumber;
		_PinCode = PinCode; _AccountBalance = AccountBalance;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void SetMarkedForDeleted(bool  MarkForDelete)
	{
		_MarkForDelete = MarkForDelete;
	}
	bool GetMarkedForDeleted()
	{
		return  _MarkForDelete;
	}
	__declspec(property(get = GetMarkedForDeleted, put = SetMarkedForDeleted)) bool MarkForDelete;


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.PinCode == PinCode&&Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool ClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	 enSaveResult Save()
	 {
		 switch (_Mode)
		 {
		 case clsBankClient::EmptyMode:
			 if (IsEmpty())
			 {
				 return enSaveResult::svFaildEmptyObject;
			 }
			 break;
		 case clsBankClient::UpdateMode:

			 _Update();
			 return enSaveResult::svSucceeded;
			 break;
		 case clsBankClient::AddNewMode:
			 if (clsBankClient::ClientExist(_AccountNumber))
			 {
				 return enSaveResult::svFaildAccountNumberExists;
			 }
			 else {
				 _AddNew();
				 return enSaveResult::svSucceeded;
			 }
			 break;
		
		 default:
			 break;
		 }
	 }

	 static clsBankClient GetAddNewClientObject(string AccountNumber)
	 {
		 return clsBankClient(enMode::AddNewMode, AccountNumber, "", "", "", "", "", 0);
	 }

	 bool Delete()
	 {
		 vector<clsBankClient> vClient;
		 vClient = _LoadClientsDataFromFile(_NameFile);

		 for (clsBankClient& C : vClient)
		 {
			 if (_AccountNumber == C.AccountNumber())
			 {
				 C._MarkForDelete = true;
				 break;
			 }
		 }
		 _SaveCleintsDataToFile(vClient);

		 *this = _GetEmptyClientObject();
		 return true;
	 }

	 static vector<clsBankClient> GetClientsList()
	 {
		 return _LoadClientsDataFromFile("Clients.txt");
	 }
	 
	 static float GetTotalBalances()
	 {
		 vector<clsBankClient> vdatafile = clsBankClient::GetClientsList();

		 double TotalBalances = 0;
		 for (clsBankClient Client : vdatafile)
		 {
			
			 TotalBalances += Client.AccountBalance;
		 }
		 return TotalBalances;
	 }

	 void Deposit(double Amount)
	 {
		 _AccountBalance += Amount;
		 Save();
	 }

	 bool Withdraw(double Amount)
	 {
		 if (Amount > _AccountBalance)
		 {
			 return false;
		 }
		 else {
			 _AccountBalance -= Amount;
			 Save();
		 }
	 }

	 bool Transfer(double Amount, clsBankClient& DestinationClient, string UserName)
	 {
		 if (Amount > _AccountBalance)
		 {
			 return false;
		 }
		
		 Withdraw(Amount);
		 DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient,UserName);

		 return true;
	 }

	 static vector<stTrnsferLogRecord> GetTransferLogList()
	 {
		 vector<stTrnsferLogRecord> vData;

		 fstream Users;
		 Users.open("TransferLog.txt", ios::in);

		 if (Users.is_open())
		 {
			 string line;
			 while (getline(Users, line))
			 {
				 stTrnsferLogRecord TransferRecord = _ConvertLoginTransferLineToRecord(line, "#//#");

				 vData.push_back(TransferRecord);
			 }
			 Users.close();
		 }
		 return vData;
	 }








};

