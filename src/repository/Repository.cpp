#include <fstream>
#include <sstream>
#include <string>
#include "Repository.h"
#include "../../include/repository/Repository.h"
#include "../../include/model/Customer.h"

/**
 * Repository implementation
 */


/**
 * constructor
 */
template <class T>
Repository<T>::Repository(string filePath)
{
    this->filePath = filePath;
}

/**
 * read file and then convert it into object of T
 * @return vector<T>
 */
template <class T>
vector<T> Repository<T>::readAllData()
{
    ifstream infile;
    this->objectList.clear();
    infile.open(this->filePath);
    if (!infile.is_open())
    {
        printf("Sorry! File not found");
        exit(0);
    }
    string line;
    while (infile.peek() != EOF)
    {
        getline(infile, line);
        this->objectList.push_back(stringToObject(line));
    }
    infile.close();
    return this->objectList;
}

/**
 * add new line into data file
 * @param object
 */
template <class T>
void Repository<T>::appendData(T object)
{
    FILE *outfile;
    outfile = fopen(this->filePath.c_str(), "ab");
    if (outfile)
    {
        fprintf(outfile, objectToString(object).c_str());
    }
    fclose(outfile);
}

/**
 * change line that represent the data
 * @param object
 */
template <class T>
void Repository<T>::updateData(T object)
{
}

/**
 * delete line that represent the data
 * @param id
 */
template <class T>
void Repository<T>::deleteData(long id)
{
}

/**
 * find line that match with id and then convert it into object of T
 * @param id
 * @return T
 */
template <class T>
T Repository<T>::findData(long id)
{
    return null;
}

/**
 * @return long
 */
template <class T>
long Repository<T>::generateId()
{
    return 0;
}

template class Repository<Customer>;