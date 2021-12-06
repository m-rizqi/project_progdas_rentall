#include "../../include/model/RentForm.h"
/**
 * RentForm implementation
 */


RentForm::RentForm() {
    RentForm(0,0,0,"","","","");
}

/**
 * @param id
 * @param customerId
 * @param carId
 * @param destination
 * @param rentalDate
 * @param expectedReturnDate
 * @param returnDate
 */
RentForm::RentForm(long id, long customerId, long carId, string destination, string rentalDate, string expectedReturnDate, string returnDate) {
    this->id = id;
    this->customerId = customerId;
    this->carId = carId;
    this->destination = destination;
    this->rentalDate = rentalDate;
    this->expectedReturnDate = expectedReturnDate;
    this->returnDate = returnDate;
}

/**
 * @param id
 */
void RentForm::setId(long id) {
    this->id = id;
}

/**
 * @return long
 */
long RentForm::getId() {
    return this->id;
}

/**
 * @param customerId
 */
void RentForm::setCustomerId(long customerId) {
    this->customerId = customerId;
}

/**
 * @return long
 */
long RentForm::getCustomerId() {
    return this->customerId;
}

/**
 * @param carId
 */
void RentForm::setCarId(long carId) {
    this->carId = carId;
}

/**
 * @return long
 */
long RentForm::getCarId() {
    return this->carId;
}

/**
 * @param destination
 */
void RentForm::setDestination(string destination) {
    this->destination = destination;
}

/**
 * @return string
 */
string RentForm::getDestination() {
    return this->destination;
}

/**
 * @param rentalDate
 */
void RentForm::setRentalDate(string rentalDate) {
    this->rentalDate = rentalDate;
}

/**
 * @return string
 */
string RentForm::getRentalDate() {
    return this->rentalDate;
}

/**
 * @param expectedReturnDate
 */
void RentForm::setExpectedReturnDate(string expectedReturnDate) {
    this->expectedReturnDate = expectedReturnDate;
}

/**
 * @return string
 */
string RentForm::getExpectedReturnDate() {
    return this->expectedReturnDate;
}

/**
 * @param returnDate
 */
void RentForm::setReturnDate(string returnDate) {
    this->returnDate = returnDate;
}

/**
 * @return string
 */
string RentForm::getReturnDate() {
    return this->returnDate;
}

void RentForm::print() {
    printf("RentForm(id=%d,customerId=%d,carId=%d,destination=%s,rentalDate=%s,expectedReturnDate=%s,returnDate=%s)\n",this->id, this->customerId, this->carId, this->destination.c_str(), this->rentalDate.c_str(), this->expectedReturnDate.c_str(), this->returnDate.c_str());
}

/**
 * @param target
 * @return bool
 */
bool RentForm::isEquals(RentForm target) {
    return this->id == target.getId();
}