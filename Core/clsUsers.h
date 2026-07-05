#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h";
#include"clsUtility.h";
#include"clsPerson.h";
using namespace std;


class clsUsers : public clsPerson 
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _NameUser;
	string _PinCode;
	int _Permission;
	bool _MarkForDelete = false;

	static string _ConvertUserObjectToLine(clsUsers data, string seperator = "#//#")
	{
		string str = "";
		
		str += data.getFirstName() + seperator;
		str += data.getLastName() + seperator;
		str += data.getEmail() + seperator;
		str += data.getPhone() + seperator;
		str += data.NameUser + seperator;
		str += clUtility::EncryptText(data._PinCode) + seperator;
		str += to_string(data.Permission);
		
		return str;
	}

	static clsUsers  _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clString::Split(Line, Seperator);

		return clsUsers(enMode::UpdateMode,vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], clUtility::DecryptText(vUserData[5]), stoi(vUserData[6]));
	}

	static vector<clsUsers> _LoadUsersDataFromFile()
	{
		vector<clsUsers> vUsers;

		fstream Users;
		Users.open("Users.txt", ios::in);

		if (Users.is_open())
		{
			string line;
			while (getline(Users, line))
			{
				clsUsers data = _ConvertLineToUserObject(line,"#//#");

				vUsers.push_back(data);
			}
			Users.close();
		}
		return vUsers;
	}

	static void _SaveUsersDataToFile(vector<clsUsers> vData)
	{
		fstream Data;
		Data.open("Users.txt", ios::out);

		if (Data.is_open())
		{
			string line;

			for (clsUsers d : vData)
			{
				if (d._MarkForDelete == false)
				{
					line = _ConvertUserObjectToLine(d, "#//#");
					Data << line << endl;
				}
			}
			Data.close();
		}
	}

	static clsUsers _GetEmptyUserObject()
	{
		return clsUsers(enMode::EmptyMode,"", "", "", "", "", "", 0);
	}

	void _Update()
	{
		vector<clsUsers> vUsers;
		vUsers = _LoadUsersDataFromFile();

		for (clsUsers& U : vUsers)
		{
			if (_NameUser == U.NameUser)
			{
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	string _PrepareLogInRecord(string seperator = "#//#")
	{
		string str = "";

		str += clsDate::GetSystemDateTimeString() + seperator;
		str += NameUser + seperator;
		str += clUtility::EncryptText(PinCode) + seperator;
		str += to_string(Permission);

		return str;
	}

	struct stLoginRegisterRecord;
	static stLoginRegisterRecord  _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;
		vector<string> vUserData = clString::Split(Line, Seperator);

		LoginRegisterRecord.DateTime = vUserData[0];
		LoginRegisterRecord.UserName = vUserData[1];
		LoginRegisterRecord.Password = clUtility::DecryptText(vUserData[2]);
		LoginRegisterRecord.Permissions = stoi(vUserData[3]);

		return LoginRegisterRecord;
	}


public:
	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64 ,pLoginRegister=128
	};

	struct stLoginRegisterRecord {
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};

	clsUsers(enMode Mode,string FirstName,string LastName,
		string Email,string Phone,string NameUser,string PinCode,int Permission): 
	clsPerson(FirstName, LastName, Email, Phone) 
	{
		_Mode = Mode; _NameUser = NameUser;
		_PinCode = PinCode; _Permission = Permission;
	}
	

	void SetNameUser(string NameUser)
	{
		_NameUser = NameUser;
	}
	string GetNameUser()
	{
		return _NameUser;
	}
	__declspec(property(get = GetNameUser, put = SetNameUser)) string NameUser;

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetPermission(int Permission)
	{
		_Permission = Permission;
	}
	int GetPermission()
	{
		return _Permission;
	}
	__declspec(property(get = GetPermission, put = SetPermission)) int Permission;

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted()
	{
		return _MarkForDelete;
	}

	static clsUsers Find(string NameUser)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUsers Client = _ConvertLineToUserObject(Line);
				if (Client.NameUser == NameUser)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	static clsUsers Find(string NameUser, string PinCode)
	{
		vector <clsUsers> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUsers User = _ConvertLineToUserObject(Line);
				if (User.PinCode == PinCode && User.NameUser == NameUser)
				{
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string NameUser)
	{
		clsUsers User = clsUsers::Find(NameUser);
		return (!User.IsEmpty());
	}

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case clsUsers::EmptyMode:
			if (IsEmpty())
			{
				return enSaveResult::svFaildEmptyObject;
			}
			break;
		case clsUsers::UpdateMode:

			_Update();
			return enSaveResult::svSucceeded;
			break;
		case clsUsers::AddNewMode:
			if (clsUsers::IsUserExist(NameUser))
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

	static clsUsers GetAddNewUserObject(string NameUser)
	{
		return clsUsers(enMode::AddNewMode, NameUser, "", "", "", "", "", 0);
	}

	bool Delete()
	{
		vector<clsUsers> vUsers;
		vUsers = _LoadUsersDataFromFile();

		for (clsUsers& C : vUsers)
		{
			if (_NameUser == C.NameUser)
			{
				C._MarkForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);

		*this = _GetEmptyUserObject();
		return true;
	}

	static vector<clsUsers> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permission == enPermissions::eAll)return true;

		if (( Permission & this->Permission)== Permission)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void RegisterLogIn()
	{
        string stDataline= _PrepareLogInRecord();

		fstream File;
		File.open("LoginFileRegister.txt", ios::out| ios::app);

		if (File.is_open())
		{
			File << stDataline << endl;

			File.close();
		}
	}

	static vector<stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector<stLoginRegisterRecord> vData;

		fstream Users;
		Users.open("LoginFileRegister.txt", ios::in);

		if (Users.is_open())
		{
			string line;
			while (getline(Users, line))
			{
				stLoginRegisterRecord data = _ConvertLoginRegisterLineToRecord(line, "#//#");

				vData.push_back(data);
			}
			Users.close();
		}
		return vData;
	}

};


