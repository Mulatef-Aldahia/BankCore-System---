#pragma once
#include<iostream> 
#include<fstream> 
#include"clsPerson.h" 
#include"clsString.h" 
#include <string> 
#include <vector>
using namespace std;

class clsUser :public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddMode = 2 };

    enMode _Mode;
    string _UserName;
    string _PassWord;
    int _Permissions;
    bool _MarkedForDelete = false;

    struct stLoginRegisterRecord;

    //static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    //{
    //    string UserRecord = "";
    //    UserRecord += User.FirstName + Seperator;
    //    UserRecord += User.LastName + Seperator;
    //    UserRecord += User.Email + Seperator;
    //    UserRecord += User.Phone + Seperator;
    //    UserRecord += User.UserName + Seperator;
    //    //here we encypt store the encrypted Password not the real one. 
    //    UserRecord += clsUtil::EncryptText(User.PassWord) + Seperator;
    //    UserRecord += to_string(User.Permissions);

    //    return UserRecord;
    //}
    ////private functions 
    //static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
    //{
    //    stLoginRegisterRecord LoginRegisterRecord;
    //    vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
    //    LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
    //    LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
    //    LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
    //    LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

    //    return LoginRegisterRecord;

    //}
    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;
        vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
        LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
        LoginRegisterRecord.Password = LoginRegisterDataLine[2];
        LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

        return LoginRegisterRecord;

    }
    //string _PrepareLogInRecord(string Seperator = "#//#")
    //{
    //    string LoginRecord = "";
    //    LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
    //    LoginRecord += UserName + Seperator;
    //    here we encypt store the encrypted Password not the real one. 
    //    LoginRecord += clsUtil::EncryptText(PassWord) + Seperator;
    //    LoginRecord += to_string(Permissions);
    //    return LoginRecord;
    //}
    string _PrepareLogInRecord(string Seperator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += UserName + Seperator;
        LoginRecord += PassWord + Seperator;
        LoginRecord += to_string(Permissions);
        return LoginRecord;
    }
  /*  static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#") {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));
    } */
    static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#") {
        vector<string>vUserData = clsString::Split(Line, Seperator);
        clsUser User(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3],
            vUserData[4], vUserData[5], stoi(vUserData[6]));
        return User;
    }

    //static string _ConvertFromUserObjectToLine(clsUser User, string Seperator = "#//#") {

    //    string UserRecord = "";
    //    UserRecord += User.FirstName + Seperator;
    //    UserRecord += User.LastName + Seperator;
    //    UserRecord += User.Email + Seperator;
    //    UserRecord += User.Phone + Seperator;
    //    UserRecord += User.UserName + Seperator;
    //    //here we encypt store the encrypted Password not the real one. 
    //    UserRecord += clsUtil::EncryptText(User.PassWord) + Seperator;
    //    UserRecord += to_string(User.Permissions);

    //    return UserRecord;

   // }
    static string _ConvertFromUserObjectToLine(clsUser User, string Seperaor = "#//#") {

        return User.FirstName + Seperaor
            + User.LastName + Seperaor
            + User.Email + Seperaor
            + User.Phone + Seperaor
            + User.UserName + Seperaor
            + User.PassWord + Seperaor
            + to_string(User.Permissions);
    }
    
 /*   static string _ConvertFromUserObjectToLine(clsUser User, string Seperaor = "#//#") {

        return User.FirstName + Seperaor
            + User.LastName + Seperaor
            + User.Email + Seperaor
            + User.Phone + Seperaor
            + User.UserName + Seperaor
            + User.PassWord + Seperaor
            + to_string(User.Permissions);
    }*/

    static vector<clsUser> _LoadUsersDataFromFile() {
        vector<clsUser>vUsers;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open()) {
            string Line = "";
            while (getline(MyFile, Line)) {
                vUsers.push_back(_ConvertLineToUserObject(Line));
            }
            MyFile.close();
        }
        return vUsers;
    }

    static void _SaveUsersDataToFile(vector<clsUser>vUsers) {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out);

        if (MyFile.is_open()) {
            for (clsUser& User : vUsers) {
                if (User._MarkedForDelete == false) {
                    MyFile << _ConvertFromUserObjectToLine(User) << endl;
                }
            }
            MyFile.close();
        }
    }
   
    
    static void _AddDataLineToFile(string stDataLine) {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open()) {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    void _Update() {
        vector<clsUser>vUsers = _LoadUsersDataFromFile();

        for (clsUser& User : vUsers) {
            if (User.UserName == UserName) {
                User = *this;
                break;
            }
        }
        _SaveUsersDataToFile(vUsers);
    }

    void _AddNew() {
        _AddDataLineToFile(_ConvertFromUserObjectToLine(*this));
    }

    static clsUser _GetEmptyUserObject() {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    //private functions 
 /*   string _PrepareLogInRecord(string Seperator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += UserName + Seperator;
        LoginRecord += PassWord + Seperator;
        LoginRecord += to_string(Permissions);
        return LoginRecord;
    }*/

public:

    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pLoginRegister = 128
    };
    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions;

    };
    //Constructor 
    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName
        , string Password, int Permissions) :clsPerson(FirstName, LastName, Email, Phone) {

        this->_Mode = Mode;
        this->_UserName = UserName;
        this->_PassWord = Password;
        this->_Permissions = Permissions;
    }

    //check Functions 
    bool IsEmpty() {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDelete() {
        return _MarkedForDelete;
    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    //setters 
    void set_UserName(string UserName) {
        this->_UserName = UserName;
    }

    void set_PassWord(string PassWord) {
        this->_PassWord = PassWord;
    }

    void set_Permissions(int Permissions) {
        this->_Permissions = Permissions;
    }

    //Getters 
    string get_UserName() { return _UserName; }
    string get_PassWord() { return _PassWord; }
    int get_Permissions() { return _Permissions; }

    //declspec 
    _declspec(property(get = get_UserName, put = set_UserName))string UserName;
    _declspec(property(get = get_PassWord, put = set_PassWord))string PassWord;
    _declspec(property(get = get_Permissions, put = set_Permissions))int Permissions;


    //public functions 
    static clsUser Find(string UserName) {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open()) {
            string Line = "";
            while (getline(MyFile, Line)) {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == UserName) {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string PassWord) {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open()) {
            string Line = "";
            while (getline(MyFile, Line)) {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == UserName && User.PassWord == PassWord) {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save() {
        switch (_Mode)
        {
        case clsUser::EmptyMode:
            if (IsEmpty()) {
                return svFaildEmptyObject;
            }
            break;
        case clsUser::UpdateMode:
            _Update();
            return svSucceeded;
            break;
        case clsUser::AddMode:
            if (clsUser::IsUserExist(this->UserName)) {
                return enSaveResults::svFaildUserExists;
            }
            else {
                _AddNew();
                this->_Mode = UpdateMode;
                return svSucceeded;
            }
            break;
        default:
            break;
        }
    }

    bool Delete() {
        vector<clsUser>vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(vUsers);

        *this = _GetEmptyUserObject();

        return true;
    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }
    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;

        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;

    }

    //public functions 
    void RegisterLogIn()
    {

        string stDataLine = _PrepareLogInRecord();

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
    static  vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector <stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode 

        if (MyFile.is_open())
        {

            string Line;

            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {

                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vLoginRegisterRecord.push_back(LoginRegisterRecord);

            }

            MyFile.close();

        }

        return vLoginRegisterRecord;

    }
};

