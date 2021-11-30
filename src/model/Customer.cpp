#include "../../include/model/Customer.h"

Customer::Customer(long id, string name, string address, long phone, string KTP_number){
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
