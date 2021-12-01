#include <iostream>
#include <vector>
#include "../model/Customer.h"
using namespace std;

class CustomerRepository{
    private:
        vector<Customer> customerList;
        static CustomerRepository* _instance;
    public:
        static CustomerRepository* getInstance();
        vector<Customer> readCustomerFile();
        void writeCustomerFile(Customer customer);
};