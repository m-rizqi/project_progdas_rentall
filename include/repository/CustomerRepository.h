#pragma once
#include <iostream>
#include <vector>
#include "../../src/repository/Repository.cpp"
using namespace std;

#ifndef CUSTOMER_REPOSITORY_H
#define CUSTOMER_REPOSITORY_H

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

#endif