/**
 * Project Untitled
 */


#ifndef _CUSTOMERREPOSITORY_H
#define _CUSTOMERREPOSITORY_H

class CustomerRepository {
public: 
    
/**
 * @param line
 */
Customer stringToData(string line);
    
/**
 * @param customer
 */
string dataToString(Customer customer);
    
/**
 * @param name
 */
Customer searchByName(string name);
};

#endif //_CUSTOMERREPOSITORY_H