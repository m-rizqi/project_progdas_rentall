#include <fstream>
#include <sstream>
#include <string>
#include "../../include/repository/CarRepository.h"
using namespace std;

/**
 * CarRepository implementation
 */

#define CAR_FILE_PATH "src//repository//car.txt"
// #define CAR_FILE_PATH "../src/repository/car.txt"

CarRepository::CarRepository() : Repository<Car>(CAR_FILE_PATH) {}

/**
 * @param line
 * @return Car
 */
template <>
Car Repository<Car>::stringToData(string line)
{
    string arr[4];
    stringstream temp(line);
    string str;
    int i = 0;
    while (getline(temp, str, '_'))
    {
        arr[i] = str;
        i++;
    }
    bool rented = stoi(arr[3]) == 1 ? true : false;
    return Car(std::stol(arr[0]), arr[1], arr[2], rented);
}

template <>
string Repository<Car>::dataToString(Car object)
{
    string rented = object.isRented() ? "1" : "0";
    return to_string(object.getId()) + "_" + object.getName() + "_" + object.getPoliceNumber() + "_" + rented;
}

/**
 * @param line
 * @return Car
 */
Car CarRepository::searchByName(string line) {
    return Car();
}