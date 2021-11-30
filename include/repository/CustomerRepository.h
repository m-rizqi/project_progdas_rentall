#include <iostream>
#include <vector>
#include "../model/Customer.h"
using namespace std;

class CustomerRepository{
    private:
        vector<Customer> customerList;
    public:
        
        vector<Customer> readCustomerFile();
};