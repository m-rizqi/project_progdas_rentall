/**
 * Project Untitled
 */


#ifndef _CARREPOSITORY_H
#define _CARREPOSITORY_H

class CarRepository {
public: 
    
/**
 * @param line
 */
Car stringToData(string line);
    
void dataToString();
    
/**
 * @param line
 */
Car searchByName(string line);
};

#endif //_CARREPOSITORY_H