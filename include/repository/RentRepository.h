/**
 * Project Untitled
 */


#ifndef _RENTREPOSITORY_H
#define _RENTREPOSITORY_H

class RentRepository {
public: 
    
/**
 * @param line
 * @param Parameter1
 */
void stringToData(string line, void Parameter1);
    
/**
 * @param Parameter1
 * @param Parameter2
 */
void dataToString(void Parameter1, void Parameter2);
    
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

#endif //_RENTREPOSITORY_H