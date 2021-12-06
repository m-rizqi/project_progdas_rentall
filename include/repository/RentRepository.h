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
    RentForm searchByCustomerId(long customerId);

    /**
     * @param carId
     */
    RentForm searchByCarId(long carId);

    /**
     * @param rentalDate
     */
    RentForm searchByRentalDate(string rentalDate);

    /**
     * @param expectedReturnDate
     */
    RentForm searchByExpectedReturnDate(string expectedReturnDate);

    /**
     * @param returnDate
     */
    RentForm searchByReturnDate(string returnDate);
};