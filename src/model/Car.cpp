#include "../../include/model/Car.h"

/**
 * Car implementation
 */


Car::Car() {
    Car(0,"","", false);
}

/**
 * @param id
 * @param name
 * @param police_number
 */
Car::Car(long id, string name, string police_number, bool rented) {
    this->id = id;
    this->name = name;
    this->police_number = police_number;
    this->rented = rented;
}

/**
 * Set the cars' id
 * @param id
 */
void Car::setId(long id) {
    this->id = id;
}

/**
 * Return cars' id
 * @return long
 */
long Car::getId() {
    return this->id;
}

/**
 * Set the cars' name
 * @param name
 */
void Car::setName(string name) {
    this->name = name;
}

/**
 * Return cars' name
 * @return string
 */
string Car::getName() {
    return this->name;
}

/**
 * Set the cars' police number
 * @param police_number
 */
void Car::setPoliceNumber(string police_number) {
    this->police_number = police_number;
}

/**
 * Return cars' police number
 * @return string
 */
string Car::getPoliceNumber() {
    return this->police_number;
}

/**
 * @param rented
 */
void Car::setRented(bool rented) {
    this->rented = rented;
}

/**
 * @return bool
 */
bool Car::isRented() {
    return this->rented;
}

/**
 * Print the car information detail
 * @return void
 */
void Car::print() {
    printf("Car(id=%d, name=%s, policeNumber=%s, rented=%d)\n", this->id, this->name.c_str(), this->police_number.c_str(), this->rented);
}

/**
 * Comparing two cars whether the same or not.
 * @return bool
 */
bool Car::isEquals(Car target) {
    return this->id == target.getId();
}