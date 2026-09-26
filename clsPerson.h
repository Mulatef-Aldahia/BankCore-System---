#pragma once 
#include<iostream> 
using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	//constructors 
	clsPerson(string FirstName, string LastName, string Email, string Phone) {
		this->_FirstName = FirstName;
		this->_LastName = LastName;
		this->_Email = Email;
		this->_Phone = Phone;
	}

	//setters 
	void set_FirstName(string FirstName) { this->_FirstName = FirstName; }
	void set_LastName(string LastName) { this->_LastName = LastName; }
	void set_Email(string Email) { this->_Email = Email; }
	void set_Phone(string Phone) { this->_Phone = Phone; }

	//getters 

	string get_FirstName() { return this->_FirstName; }
	string get_LastName() { return this->_LastName; }
	string get_Email() { return this->_Email; }
	string get_Phone() { return  this->_Phone; }
	string get_FullName() { return  this->_FirstName + " " + this->_LastName; }

	//declspec 
	__declspec(property(get = get_FirstName, put = set_FirstName))string FirstName;
	__declspec(property(get = get_LastName, put = set_LastName))string LastName;
	__declspec(property(get = get_Email, put = set_Email))string Email;
	__declspec(property(get = get_Phone, put = set_Phone))string Phone;

	//person functions 
	void Print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nFirstName: " << this->_FirstName;
		cout << "\nLastName : " << this->_LastName;
		cout << "\nFull Name: " << this->get_FullName();
		cout << "\nEmail    : " << this->_Email;
		cout << "\nPhone    : " << this->_Phone;
		cout << "\n___________________\n";

	}
};