#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUsers.h";
using namespace std;

class clsUpdateUserScreen :protected clsScreen
{

private:
    static void _ReadUserInfo(clsUsers& User)
    {
        cout << "Enter PinCode? "; User.PinCode = clsInputValidate::ReadString();

        cout << "Enter First Name? "; User.setFirstName(clsInputValidate::ReadString());

        cout << "Enter Last Name? "; User.setLastName(clsInputValidate::ReadString());

        cout << "Enter Phone? "; User.setPhone(clsInputValidate::ReadString());

        cout << "Enter Email? "; User.setEmail(clsInputValidate::ReadString());

        cout << "Enter Permissions? ";
        User.Permission = _ReadPermissionsToSet();

    }

    static void _PrintUser(clsUsers User)
    {
        cout << "User Card:" << endl;
        cout << "_____________________________________________" << endl;
        cout << "First Name        :" << User.getFirstName() << endl;
        cout << "Last  Name        :" << User.getLastName() << endl;
        cout << "Full  Name        :" << User.getFullName() << endl;
        cout << "Email             :" << User.getEmail() << endl;
        cout << "Phone             :" << User.getPhone() << endl;
        cout << "NameUser          :" << User.NameUser << endl;
        cout << "Password          :" << User.GetPinCode() << endl;
        cout << "Permission           :" << User.Permission << endl;
        cout << "_____________________________________________\n" << endl;

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUsers::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pManageUsers;
        }

        cout << "\nShow Login Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUsers::enPermissions::pLoginRegister;
        }

        return Permissions;

    }

public:

	static void ShowUpdateUserScreen()
	{
		clsScreen::_DrawScreenHeader("Update User Screen");

      

        cout << "Please Enter User Name:";
        string UserName = clsInputValidate::ReadString();

        while (clsUsers::IsUserExist(UserName))
        {
            cout << "\nUser with [" << UserName << "] already exists,Enter User Name?";
            UserName = clsInputValidate::ReadString();
        }

        clsUsers User = clsUsers::GetAddNewUserObject(UserName);
        _PrintUser(User);

		cout << "Update Info:" << endl;
		cout << "------------------------------------" << endl;
        _ReadUserInfo(User);

        clsUsers::enSaveResult Result;
		Result = User.Save();

		if (Result == clsBankClient::enSaveResult::svSucceeded)
		{
            _PrintUser(User);
			cout << "\nUser Update successfully :-)" << endl;
		}
		else
		{
			cout << "\nUser Update Not successfully :-(" << endl;
		}

	}
};
