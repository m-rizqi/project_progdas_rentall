#pragma once
#include <iostream>
using namespace std;

class RentForm
{
public:
    RentForm();

    /**
     * @param id
     * @param customerId
     * @param carId
     * @param destination
     * @param rentalDate
     * @param expectedReturnDate
     * @param returnDate
     */
    RentForm(long id, long customerId, long carId, string destination, string rentalDate, string expectedReturnDate, string returnDate);

    /**
     * @param id
     */
    void setId(long id);

    long getId();

    /**
     * @param customerId
     */
    void setCustomerId(long customerId);

    long getCustomerId();

    /**
     * @param carId
     */
    void setCarId(long carId);

    long getCarId();

    /**
     * @param destination
     */
    void setDestination(string destination);

    string getDestination();

    /**
     * @param rentalDate
     */
    void setRentalDate(string rentalDate);

    string getRentalDate();

    /**
     * @param expectedReturnDate
     */
    void setExpectedReturnDate(string expectedReturnDate);

    string getExpectedReturnDate();

    /**
     * @param returnDate
     */
    void setReturnDate(string returnDate);

    string getReturnDate();

    void print();

    /**
     * @param target
     */
    bool isEquals(RentForm target);

private:
    long id;
    long customerId;
    long carId;
    string destination;
    string rentalDate;
    string expectedReturnDate;
    string returnDate;
};