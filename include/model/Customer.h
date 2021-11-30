#include <iostream>
using namespace std;

class Customer{
    private:
        long id;
        string name;
        string address;
        long phone;
        string KTP_number;
    public:
        Customer();
        Customer(long id, string name, string address, long phone, string KTP_number);
        void setId(long id);
        long getId();
        void setName(string name);
        string getName();
        void setAddress(string address);
        string getAddress();
        void setPhone(long phone);
        long getPhone();
        void setKTPNumber(string KTP_number);
        string getKTPNumber();
        void toString();
        bool isEquals(Customer target);
};