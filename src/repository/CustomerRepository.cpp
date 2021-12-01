#include <fstream>
#include <sstream>
#include <string>
#include "../../include/repository/CustomerRepository.h"
using namespace std;

#define CUSTOMER_FILE_PATH "src//repository//customer.txt"
// #define CUSTOMER_FILE_PATH "../src/repository/customer.txt"

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
    infile.open(CUSTOMER_FILE_PATH);
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
        while (getline(temp, str, '_'))
        {
            arr[i] = str;
            i++;
        }
        customerList.push_back(Customer(std::stol(arr[0]), arr[1], arr[2], arr[3], arr[4]));
    }
    infile.close();
    return customerList;
}

void CustomerRepository::writeCustomerFile(Customer customer){
    FILE *outfile;
    outfile = fopen(CUSTOMER_FILE_PATH, "ab");
    if (outfile)
    {
        fprintf(outfile, "\n%d_%s_%s_%s_%s", customer.getId(), customer.getName().c_str(), customer.getAddress().c_str(), customer.getPhone().c_str(), customer.getKTPNumber().c_str());
    }
    fclose(outfile);
}