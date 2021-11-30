#include <fstream>
#include <sstream>
#include <string>
#include "../../include/repository/CustomerRepository.h"
using namespace std;

CustomerRepository* CustomerRepository::_instance = NULL;

CustomerRepository* CustomerRepository::getInstance(){
    if(CustomerRepository::_instance == NULL){
        CustomerRepository::_instance = new CustomerRepository();
    }
    return CustomerRepository::_instance;
}

vector<Customer> CustomerRepository::readCustomerFile(){
    ifstream infile;
    customerList.clear();
    infile.open("src//repository//customer.txt");
    // infile.open("../src/repository/customer.txt");
    if (!infile.is_open())
    {
        printf("Sorry! File not found");
        exit(0);
    }
    string line;
    while(infile.peek() != EOF){
        getline(infile, line);
        string arr[5];
        stringstream temp(line);
        string str;
        int i = 0;
        while (getline(temp, str, ','))
        {
            arr[i] = str;
            i++;
        }
        customerList.push_back(Customer(1, arr[1], arr[2], arr[3], arr[4]));
    }
    infile.close();
    return customerList;
}