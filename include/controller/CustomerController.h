#pragma once
#ifndef _CUSTOMER_CONTROLLER_H
#define _CUSTOMER_CONTROLLER_H
#include <iostream>
#include <vector>
#include "../../include/repository/CustomerRepository.h"
using namespace std;

class CustomerController
{
public:
    /**
     *  constructor
     */
    CustomerController();
    /**
     * function to register a customer
     */
    void registerCustomer();

    /**
     * function to edit and save customer
     */
    void updateCustomer();

    /**
     * function to delete customer
     */
    void deleteCustomer();

    /**
     * function to show multiple customer
     */
    void displayCustomers();

    /**
     * function to show previous page of display customer
     */
    void navigatePrevious();

    /**
     * function to show next page of display customer
     */
    void navigateNext();

    /**
     * function to search one or multiple customer by condition
     */
    void searchCustomer();
private:
    CustomerRepository customerRepository;
};

#endif //_CONTROLLER_H