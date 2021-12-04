#include <fstream>
#include <sstream>
#include <string>
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
        fprintf(outfile, ("\n" + dataToString(object)).c_str());
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
    // for(T temp : listObject)    
    return T();
}

/**
 * @return long
 */
template <class T>
long Repository<T>::generateId()
{
    ifstream infile;
    this->objectList.clear();
    infile.open(this->filePath);
    if (!infile.is_open()){return 0;}
    infile.seekg(-1, ios_base::end);
    bool keepLooping = true;
    while (keepLooping)
    {
        char ch;
        infile.get(ch); // Get current byte's data

        if ((int)infile.tellg() <= 1)
        {                        // If the data was at or before the 0th byte
            infile.seekg(0);        // The first line is the last line
            keepLooping = false; // So stop there
        }
        else if (ch == '\n')
        {                        // If the data was a newline
            keepLooping = false; // Stop at the current position.
        }
        else
        {                                 // If the data was neither a newline nor at the 0 byte
            infile.seekg(-2, ios_base::cur); // Move to the front of that data, then to the front of the data before it
        }
    }

    string lastLine;
    getline(infile, lastLine);
    stringstream temp(lastLine);
    string str;
    getline(temp, str, '_');
    infile.close();
    return stol(str)+1;
}

template class Repository<Customer>;