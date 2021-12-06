#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include "../../include/repository/Repository.h"


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
        this->objectList.push_back(stringToData(line));
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
    object.setId(generateId());
    FILE *outfile;
    outfile = fopen(this->filePath.c_str(), "ab");
    if (outfile)
    {
        string line = dataToString(object);
        if(readAllData().size() > 0){
            line = "\n"+line;
        }
        fprintf(outfile, line.c_str());
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
    vector<T> listObject = readAllData();
    FILE *outfile;
    outfile = fopen(this->filePath.c_str(), "w");
    if (outfile)
    {
        for(int i = 0; i < listObject.size(); i++){
            T temp = listObject.at(i);
            string line = dataToString((temp.isEquals(object)) ? object : temp);
            line = ((i==0) ? line : ("\n"+line));
            fprintf(outfile, line.c_str());
        }
    }
    fclose(outfile);
}

/**
 * delete line that represent the data
 * @param id
 */
template <class T>
void Repository<T>::deleteData(long id)
{
    vector<T> listObject;
    for(auto &temp : readAllData()){
        if(temp.getId() != id){
            listObject.push_back(temp);
        }
    }
    FILE *outfile;
    outfile = fopen(this->filePath.c_str(), "w");
    if (outfile)
    {
        for (int i = 0; i < listObject.size(); i++)
        {
            T temp = listObject.at(i);
            string line = dataToString(temp);
            line = ((i == 0) ? line : ("\n" + line));
            fprintf(outfile, line.c_str());
        }
    }
    fclose(outfile);
}

/**
 * find line that match with id and then convert it into object of T
 * @param id
 * @return T
 */
template <class T>
T Repository<T>::findData(long id)
{
    vector<T> listObject = readAllData();
    T res = T();
    for(auto &temp : listObject){
        if(temp.getId() == id){
            res = temp;
            break;
        }
    }    
    return res;
}

/**
 * @return long
 */
template <class T>
long Repository<T>::generateId()
{
    vector<T> listObject = readAllData();
    if(listObject.size() == 0){
        return 1;
    }
    T temp = listObject.at(listObject.size() - 1);
    return temp.getId() + 1;
}