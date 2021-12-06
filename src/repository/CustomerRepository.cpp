#include <fstream>
#include <sstream>
#include <string>
#include "../../include/repository/CustomerRepository.h"
using namespace std;

/**
 * CustomerRepository implementation
 */

#define CUSTOMER_FILE_PATH "src//repository//customer.txt"
// #define CUSTOMER_FILE_PATH "../src/repository/customer.txt"


CustomerRepository::CustomerRepository() : Repository<Customer>(CUSTOMER_FILE_PATH) {}

/**
 * @param line
 * @return Customer
 */
template <>
Customer Repository<Customer>::stringToData(string line)
{
    string arr[5];
    stringstream temp(line);
    string str;
    int i = 0;
    while (getline(temp, str, '_'))
    {
        arr[i] = str;
        i++;
    }
    return Customer(std::stol(arr[0]), arr[1], arr[2], arr[3], arr[4]);
}

/**
 * @param customer
 * @return string
 */
template <>
string Repository<Customer>::dataToString(Customer customer)
{
    return to_string(customer.getId()) + "_" + customer.getName() + "_" + customer.getAddress() + "_" + customer.getPhone() + "_" + customer.getKTPNumber();
}

/**
 * @param name
 * @return Customer
 */
vector<Customer> CustomerRepository::searchByName(string name)
{
    vector<Customer> list;
    for(Customer c : readAllData()){
        if(c.getName() == name){
            list.push_back(c);
        }
    }
    return list;
}