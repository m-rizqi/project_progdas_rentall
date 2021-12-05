#pragma once
#include <iostream>
#include <vector>
#include "../../src/repository/Repository.cpp"
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
    Customer searchByName(string name);

private:
};