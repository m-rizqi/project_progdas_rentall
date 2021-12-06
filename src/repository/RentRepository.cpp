#include <fstream>
#include <sstream>
#include <string>
#include "../../include/repository/RentRepository.h"
using namespace std;

/**
 * RentRepository implementation
 */

#define RENTFORM_FILE_PATH "src//repository//rentform.txt"
// #define RENTFORM_FILE_PATH "../src/repository/rentform.txt"

RentRepository::RentRepository() : Repository<RentForm>(RENTFORM_FILE_PATH) {}

/**
 * @param line
 */
template <>
RentForm Repository<RentForm>::stringToData(string line)
{
    string arr[7];
    stringstream temp(line);
    string str;
    int i = 0;
    while (getline(temp, str, '_'))
    {
        arr[i] = str;
        i++;
    }
    return RentForm(std::stol(arr[0]), std::stol(arr[1]), std::stol(arr[2]), arr[3], arr[4], arr[5], arr[6]);
}

/**
 * @param object
 */
template <>
string Repository<RentForm>::dataToString(RentForm object)
{
    return to_string(object.getId()) + "_" 
    + to_string(object.getCustomerId()) + "_" 
    + to_string(object.getCarId()) + "_" 
    + object.getDestination() + "_"
    + object.getRentalDate() + "_"
    + object.getExpectedReturnDate() + "_"
    + object.getReturnDate();
}

/**
 * @param customerId
 * @return RentForm
 */
vector<RentForm> RentRepository::searchByCustomerId(long customerId)
{
    vector<RentForm> resultList;
    for(RentForm rF : readAllData()){
        if(rF.getCustomerId() == customerId){
            resultList.push_back(rF);
        }
    }
    return resultList;
}

/**
 * @param carId
 * @return RentForm
 */
vector<RentForm> RentRepository::searchByCarId(long carId)
{
    vector<RentForm> resultList;
    for (RentForm rF : readAllData())
    {
        if (rF.getCarId() == carId)
        {
            resultList.push_back(rF);
        }
    }
    return resultList;
}

/**
 * @param rentalDate
 * @return RentForm
 */
vector<RentForm> RentRepository::searchByRentalDate(string rentalDate)
{
    vector<RentForm> resultList;
    for (RentForm rF : readAllData())
    {
        if (rF.getRentalDate() == rentalDate)
        {
            resultList.push_back(rF);
        }
    }
    return resultList;
}

/**
 * @param expectedReturnDate
 * @return RentForm
 */
vector<RentForm> RentRepository::searchByExpectedReturnDate(string expectedReturnDate)
{
    vector<RentForm> resultList;
    for (RentForm rF : readAllData())
    {
        if (rF.getExpectedReturnDate() == expectedReturnDate)
        {
            resultList.push_back(rF);
        }
    }
    return resultList;
}

/**
 * @param returnDate
 * @return RentForm
 */
vector<RentForm> RentRepository::searchByReturnDate(string returnDate)
{
    vector<RentForm> resultList;
    for (RentForm rF : readAllData())
    {
        if (rF.getReturnDate() == returnDate)
        {
            resultList.push_back(rF);
        }
    }
    return resultList;
}