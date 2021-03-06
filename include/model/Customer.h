#pragma once
#include <iostream>
using namespace std;

class Customer {
public: 
    
Customer();
    
/**
 * @param id
 * @param name
 * @param address
 * @param phone
 * @param KTP_number
 */
Customer(long id, string name, string address, string phone, string KTP_number);
    
/**
 * Set the customer's id
 * @param id
 */
void setId(long id);
    
/**
 * Return the customer's id
 */
long getId();
    
/**
 * Set the customer's name
 * @param name
 */
void setName(string name);
    
/**
 * Return the customer's name
 */
string getName();
    
/**
 * Set the customer's address
 * @param address
 */
void setAddress(string address);
    
/**
 * Return the customer's address
 */
string getAddress();
    
/**
 * Set the customer's phone number
 * @param long phone
 */
void setPhone(string phone);
    
/**
 * Return the customer's phone number
 */
string getPhone();
    
/**
 * Set the customer's KTP number
 * @param KTP_number
 */
void setKTPNumber(string KTP_number);
    
/**
 * Return the customer's KTP number
 */
string getKTPNumber();
    
/**
 * Print customer information detail
 */
void print();
    
/**
 * Comparing two customers whether the same or not.
 */
bool isEquals(Customer target);
private: 
    /**
 * Id will generated automatically
 */
long id;
    /**
 * Fullname of the customer
 */
string name;
    /**
 * Customer address with the format : City, Province
 */
string address;
    /**
 * Phone number's customer with the format : 08xxxxxxxxxx
 */
string phone;
    /**
 * 16 digit of number in KTP
 */
string KTP_number;
};