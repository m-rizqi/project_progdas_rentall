#pragma once
#include <iostream>
#include <vector>
#include "../../src/repository/Repository.cpp"
#include "../../src/model/RentForm.cpp"
using namespace std;

class RentRepository : public Repository<RentForm>
{
public:
    /**
     * constructor
     */
    RentRepository();

    /**
     * @param customerId
     */
    vector<RentForm> searchByCustomerId(long customerId);

    /**
     * @param carId
     */
    vector<RentForm> searchByCarId(long carId);

    /**
     * @param rentalDate
     */
    vector<RentForm> searchByRentalDate(string rentalDate);

    /**
     * @param expectedReturnDate
     */
    vector<RentForm> searchByExpectedReturnDate(string expectedReturnDate);

    /**
     * @param returnDate
     */
    vector<RentForm> searchByReturnDate(string returnDate);
};