#include "../../include/model/Customer.h"

/**
 * Customer implementation
 */

Customer::Customer() {
    Customer(0,"","","","");
}

/**
 * @param id
 * @param name
 * @param address
 * @param phone
 * @param KTP_number
 */
Customer::Customer(long id, string name, string address, string phone, string KTP_number) {
    this->id = id;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->KTP_number = KTP_number;
}

/**
 * Set the customer's id
 * @param id
 */
void Customer::setId(long id) {
    this->id = id;
}

/**
 * Return the customer's id
 * @return long
 */
long Customer::getId() {
    return this->id;
}

/**
 * Set the customer's name
 * @param name
 */
void Customer::setName(string name) {
    this->name = name;
}

/**
 * Return the customer's name
 * @return string
 */
string Customer::getName() {
    return this->name;
}

/**
 * Set the customer's address
 * @param address
 */
void Customer::setAddress(string address) {
    this->address = address;
}

/**
 * Return the customer's address
 * @return string
 */
string Customer::getAddress() {
    return this->address;
}

/**
 * Set the customer's phone number
 * @param long phone
 */
void Customer::setPhone(string phone) {
    this->phone = phone;
}

/**
 * Return the customer's phone number
 * @return long
 */
string Customer::getPhone() {
    return this->phone;
}

/**
 * Set the customer's KTP number
 * @param KTP_number
 */
void Customer::setKTPNumber(string KTP_number) {
    this->KTP_number = KTP_number;
}

/**
 * Return the customer's KTP number
 * @return string
 */
string Customer::getKTPNumber() {
    return this->KTP_number;
}

/**
 * Print customer information detail
 * @return void
 */
void Customer::print() {
    printf("Customer(id=%d, name=%s, address=%s, phone=%s, KTP_number=%s)\n", this->id, this->name.c_str(), this->address.c_str(), this->phone.c_str(), this->KTP_number.c_str());
}

/**
 * Comparing two customers whether the same or not.
 * @return bool
 */
bool Customer::isEquals(Customer target) {
    return this->id == target.getId();
}