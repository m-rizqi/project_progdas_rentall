#pragma once
#ifndef _CUSTOMER_CONTROLLER_H
#define _CUSTOMER_CONTROLLER_H
#include <iostream>
#include <vector>
using namespace std;

class Controller
{
public:
    /**
     *  constructor
     */
    Controller();
    /**
     * function to register a data such as customer and car , or add new rental form
     */
    void registerData();

    /**
     * function to edit and save a data
     */
    void updateData();

    /**
     * function to delete a data
     */
    void deleteData();

    /**
     * function to show multiple data
     */
    void displayDatas();

    /**
     * function to show previous page of display data
     */
    void navigatePrevious();

    /**
     * function to show next page of display data
     */
    void navigateNext();

    /**
     * function to search one or multiple data by condition
     */
    void searchData();
};

#endif //_CONTROLLER_H