#pragma once
#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <iostream>
#include <vector>
#include "../../include/model/Customer.h"
#include "../../include/model/Car.h"
#include "../../include/model/RentForm.h"
using namespace std;

/**
 * Parent Class
 */
template <class T>
class Repository
{
public:
    /**
     *  constructor
     */
    Repository(string filePath);
    /**
     * read file and then convert it into object of T
     */
    vector<T> readAllData();

    /**
     * add new line into data file
     * @param object
     */
    void appendData(T object);

    /**
     * change line that represent the data
     * @param object
     */
    void updateData(T object);

    /**
     * delete line that represent the data
     * @param id
     */
    void deleteData(long id);

    /**
     * find line that match with id and then convert it into object of T
     * @param id
     */
    T findData(long id);

    /**
     * convert string (form read data) into object of T
     * @param line
     */
    virtual T stringToData(string line);

    /**
     * convert object of T into string to store it int file
     * @param object
     */
    virtual string dataToString(T object);

    long generateId();

private:
    /**
     * List of all customer data from database
     */
    vector<T> objectList;
    string filePath;
};

template class Repository<Customer>;
template class Repository<Car>;
template class Repository<RentForm>;

#endif