#include <iostream>
#include <vector>
#include "../../src/repository/Repository.cpp"
using namespace std;

class CustomerRepository : public Repository<Customer>{
    private:
        // vector<Customer> customerList;
        static CustomerRepository* _instance;
        CustomerRepository();
    public:
        static CustomerRepository* getInstance();
        Customer stringToObject(string data) override {return Customer();};
        // vector<Customer> readCustomerFile();
        // void writeCustomerFile(Customer customer);
};