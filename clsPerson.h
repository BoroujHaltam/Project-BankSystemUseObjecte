#pragma once
#include <iostream>
#include "InterfaceCommunication.h";
using namespace std;

class clsPerson:public InterfaceCommunication
{
private:

	string _FirstName, _LastName, _Email, _Phone;

public:


	clsPerson(string first, string last, string email, string phone)
	{

		_FirstName = first; _LastName = last;
		_Phone = phone; _Email = email;
	}


	void setFirstName(string first)
	{
		_FirstName = first;
	}

	void setLastName(string last)
	{
		_LastName = last;
	}

	void setPhone(string phone)
	{
		_Phone = phone;
	}

	void setEmail(string email)
	{
		_Email = email;
	}

	string getEmail()
	{
		return _Email;
	}

	string getFirstName()
	{
		return _FirstName;
	}

	string getLastName()
	{
		return _LastName;
	}

	string getFullName()
	{
		return _FirstName + " " + _LastName;
	}


	string getPhone()
	{
		return _Phone;
	}

	void SendEmail(string Title="The following message sent sucessfully to email: ",string Body="")
	{
		cout << Title << _Email << endl;
		cout << Body << endl;
	}

	void SendSMS(string Title="The following message sent sucessfully to phone: ", string Body="")
	{
		cout << Title << _Phone << endl;
		cout << Body << endl;
	}

	void SendFax(string Title="The following message sent sucessfully: ", string Body="")
	{
		cout << Title << _Phone << endl;
		cout << Body << endl;
	}

};
