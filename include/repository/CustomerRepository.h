#pragma once
#include <iostream>
#include <vector>
#include "../../src/repository/Repository.cpp"
#include "../../src/model/Customer.cpp"
using namespace std;

class CustomerRepository : public Repository<Customer>
{
public:
    /**
     * constructor
     */
    CustomerRepository();

    /**
     * @param name
     */
    vector<Customer> searchByName(string name);

private:
};