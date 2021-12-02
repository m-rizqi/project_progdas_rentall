#include <fstream>
#include <sstream>
#include <string>
#include "../../include/repository/Repository.h"
#include "../../include/model/Customer.h"
using namespace std;

template <class T>
Repository<T>::Repository(string filePath){
    this->filePath = filePath;
}

template <class T>
vector<T> Repository<T>::readObjectFile()
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
        this->objectList.push_back(this->stringToObject(line));
    }
    infile.close();
    return this->objectList;
}

template class Repository<Customer>;