#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <iostream>
using namespace std;

class Customer{
    private:
        long id;
        string name;
        string address;
        string phone;
        string KTP_number;
    public:
        Customer();
        Customer(long id, string name, string address, string phone, string KTP_number);
        void setId(long id);
        long getId();
        void setName(string name);
        string getName();
        void setAddress(string address);
        string getAddress();
        void setPhone(string phone);
        string getPhone();
        void setKTPNumber(string KTP_number);
        string getKTPNumber();
        void print();
        bool isEquals(Customer target);
};

#endif