//#include <iostream> 
//#include"clsBankClient.h" 
//#include "clsInputValidate.h" 
//using namespace std;
//
//void ReadClientInfo(clsBankClient& Client) {
//    cout << "\nEnter FirstName: ";
//    Client.FirstName = clsInputValidate::ReadString();
//
//    cout << "\nEnter LastName: ";
//    Client.LastName = clsInputValidate::ReadString();
//
//    cout << "\nEnter Email: ";
//    Client.Email = clsInputValidate::ReadString();
//
//    cout << "\nEnter Phone: ";
//    Client.Phone = clsInputValidate::ReadString();
//
//    cout << "\nEnter PinCode: ";
//    Client.PinCode = clsInputValidate::ReadString();
//
//    cout << "\nEnter AccountBalance: ";
//    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
//
//}
//
//void UpdateClient() {
//    string AccountNumber = "";
//    cout << "\nPlease Enter client Account Number: ";
//    AccountNumber = clsInputValidate::ReadString();
//
//    while (!clsBankClient::IsClientExist(AccountNumber)) {
//        cout << "\nAccount number is not found, choose another one: ";
//        AccountNumber = clsInputValidate::ReadString();
//    }
//
//    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
//    Client1.Print();
//
//    cout << "\n\nUpdate Client Info:";
//    cout << "\n____________________\n";
//    ReadClientInfo(Client1);
//
//    clsBankClient::enSaveResults SaveResult;
//    SaveResult = Client1.save();
//
//    switch (SaveResult)
//    {
//    case clsBankClient::svFailedEmptyObject:
//        cout << "\nError account was not saved because it's Empty";
//        break;
//    case clsBankClient::svSucceeded:
//        cout << "\nAccount Updated Successfully :-)\n";
//        Client1.Print();
//        break;
//    default:
//        break;
//    }
//}
//
//int main()
//
//{
//    UpdateClient();
//
//    system("pause>0");
//
//    return 0;
//}