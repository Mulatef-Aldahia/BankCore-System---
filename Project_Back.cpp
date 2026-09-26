 //Project_Back.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include"clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h" 
#include "clsLoginScreen.h"
#include <iomanip>

using namespace std;

void ReadClientInfo(clsBankClient& Client) {
    cout << "\nEnter FirstName: ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter LastName: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter PinCode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter AccountBalance: ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();

}

void UpdateClient() {
    string AccountNumber = "";
    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber)) {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";
    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = Client1.save();

    switch (SaveResult)
    {
    case clsBankClient::svFailedEmptyObject:
        cout << "\nError account was not saved because it's Empty";
        break;
    case clsBankClient::svSucceeded:
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.Print();
        break;
    default:
        break;
    }
}
void AddNewClient() {
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is Already used, Choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.save();

    switch (SaveResult)
    {
    case clsBankClient::svFailedEmptyObject:
        cout << "\nError account was not saved because it's Empty";
        break;
    case clsBankClient::svSucceeded:
        cout << "\nAccount Addeded Successfully :-)\n";
        NewClient.Print();
        break;
    case clsBankClient::svFaildAccountNumberExists:
        cout << "\nError account was not saved because account number is used!\n";
        break;
    default:
        break;
    }
}
void DeleteClient() {
    string AccountNumber = "";
    cout << "\nPlease enter account number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber)) {
        cout << "\nAccount number is not found, please choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\nAre you sure you want to delete this client y/n? ";
    char Answer = 'n';
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y') {
        if (Client1.Delete()) {
            cout << "\nClient Deleted Susseccfully :-)\n";
            Client1.Print();
        }
        else {
            cout << "\nError Client Was not Deleted\n";
        }
    }
}
    void PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.get_AccountNumber();
        cout << "| " << setw(20) << left << Client.get_FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
    void ShowClientsList()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

    void PrintClientRecordBalanceLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.get_AccountNumber();
        cout << "| " << setw(40) << left << Client.get_FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }


    void ShowTotalBalances()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
        cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
    }
    

int main()

{
 
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }

    }

    /*   while (true)
    {
        clsLoginScreen::ShowLoginScreen();
    }*/
    //   clsMainScreen::ShowMainMenue();
    //clsBankClient Client1 = clsBankClient::Find("B102");
    //Client1.Print();

    //clsBankClient Client2 = clsBankClient::Find("A102", "4321");
    //Client2.Print();
    
  // UpdateClient();

 //   AddNewClient();
    //DeleteClient();
   // ShowClientsList();

    //ShowTotalBalances();
    //system("pause>0");
    //
  
    return 0;
}

