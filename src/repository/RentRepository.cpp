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
RentForm RentRepository::searchByCustomerId(long customerId) {
    return RentForm();
}

/**
 * @param carId
 * @return RentForm
 */
RentForm RentRepository::searchByCarId(long carId) {
    return RentForm();
}

/**
 * @param rentalDate
 * @return RentForm
 */
RentForm RentRepository::searchByRentalDate(string rentalDate) {
    return RentForm();
}

/**
 * @param expectedReturnDate
 * @return RentForm
 */
RentForm RentRepository::searchByExpectedReturnDate(string expectedReturnDate) {
    return RentForm();
}

/**
 * @param returnDate
 * @return RentForm
 */
RentForm RentRepository::searchByReturnDate(string returnDate) {
    return RentForm();
}