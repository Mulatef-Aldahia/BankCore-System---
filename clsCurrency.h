#pragma once 
#include<iostream> 
#include<fstream> 
#include <vector> 
#include"clsString.h" 
#include <string> 

using namespace std;

class clsCurrency
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };

    //private variables 
    enMode _Mode;
    string _Country;
    string _CurrencyCode;
    string _CrruncyName;
    float _Rate;

    //private functions 
    static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#") {
        vector<string> vCurrencyData = clsString::Split(Line, Seperator);
        return
            clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));

    }

    static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#") {
        return Currency.get_Country() + Seperator
            + Currency.get_CurrencyCode() + Seperator
            + Currency.get_CurrencyName() + Seperator
            + to_string(Currency.get_Rate());
    }

    static vector<clsCurrency> _LoadCurrencysDataFromFile() {
        vector<clsCurrency> vCurrencys;

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {
                vCurrencys.push_back(_ConvertLineToCurrencyObject(Line));
            }
            MyFile.close();
        }
        return vCurrencys;
    }

    static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrencys) {
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out);

        if (MyFile.is_open()) {
            for (clsCurrency Currency : vCurrencys) {
                MyFile << _ConvertCurrencyObjectToLine(Currency) << endl;
            }
            MyFile.close();
        }
    }

    void _Update() {
        vector<clsCurrency>vCurrencys = _LoadCurrencysDataFromFile();
        for (clsCurrency& Currency : vCurrencys) {
            if (Currency.get_CurrencyCode() == this->_CurrencyCode) {
                Currency = *this;
            }
        }
        _SaveCurrencyDataToFile(vCurrencys);
    }

    static clsCurrency getEmptyCurrencyObject() {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

public:
    //constructors 
    clsCurrency(enMode Mode, string Country, string CurrencyCode, string currencyName, float Rate) {
        this->_Mode = Mode;
        this->_Country = Country;
        this->_CurrencyCode = CurrencyCode;
        this->_CrruncyName = currencyName;
        this->_Rate = Rate;
    }

    //setters 
    void UpdateRate(float Rate) {
        this->_Rate = Rate;
        _Update();
    };
    //getters 
    enMode get_Mode() { return this->_Mode; }
    string get_Country() { return this->_Country; }
    string get_CurrencyCode() { return this->_CurrencyCode; }
    string get_CurrencyName() { return this->_CrruncyName; }
    float get_Rate() { return this->_Rate; }

    //Public functions 
    bool IsEmpty() { return (this->_Mode == enMode::EmptyMode); }

    static clsCurrency FindByCode(string CurrencyCode) {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);
        fstream Myfile;
        Myfile.open("Currencies.txt", ios::in);

        if (Myfile.is_open()) {
            string Line;
            while (getline(Myfile, Line)) {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (Currency.get_CurrencyCode() == CurrencyCode) {
                    Myfile.close();
                    return Currency;
                }

            }
        }
        return getEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string Country) {
        Country = clsString::UpperAllString(Country);
        fstream Myfile;
        Myfile.open("Currencies.txt", ios::in);

        if (Myfile.is_open()) {
            string Line;
            while (getline(Myfile, Line)) {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.get_Country()) == Country) {
                    Myfile.close();
                    return Currency;
                }

            }
        }
        return getEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(string CurrencyCode) {
        clsCurrency c1 = FindByCode(CurrencyCode);
        return (!c1.IsEmpty());
    }

    static vector<clsCurrency> GetCurrenciesList() {
        return _LoadCurrencysDataFromFile();
    }
    float ConvertToUSD(float Amount)
    {
        return (float)(Amount / get_Rate());
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.get_CurrencyCode() == "USD")
        {
            return AmountInUSD;
        }

        return (float)(AmountInUSD * Currency2.get_Rate());

    }
};