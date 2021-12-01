#include "../../include/model/Customer.h"

Customer::Customer(long id, string name, string address, string phone, string KTP_number){
    this->id = id;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->KTP_number = KTP_number;
}

Customer::Customer(){
    Customer(0,"default","default",0,"default");
}

void Customer::setId(long id){
    this->id = id;
}

long Customer::getId(){
    return this->id;
}

void Customer::setName(string name)
{
    this->name = name;
}

string Customer::getName()
{
    return this->name;
}

void Customer::setAddress(string address)
{
    this->address = address;
}

string Customer::getAddress()
{
    return this->address;
}

void Customer::setPhone(string phone)
{
    this->phone = phone;
}

string Customer::getPhone()
{
    return this->phone;
}

void Customer::setKTPNumber(string KTP_number)
{
    this->KTP_number = KTP_number;
}

string Customer::getKTPNumber()
{
    return this->KTP_number;
}

void Customer::print(){
    printf("Customer(id=%d, name=%s, address=%s, phone=%s, KTP_number=%s)\n",this->id, this->name.c_str(), this->address.c_str(), this->phone.c_str(), this->KTP_number.c_str());
}

bool Customer::isEquals(Customer target){
    return this->id == target.getId();
}
