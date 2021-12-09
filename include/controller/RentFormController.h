
#ifndef _RENTFORMCONTROLLER_H
#define _RENTFORMCONTROLLER_H
#include "../../src/repository/RentRepository.cpp"

class RentFormController {
public: 

RentFormController();

void rentCar();
    
void returnCar();
private :
RentRepository rentRepository;
};

#endif //_RENTFORMCONTROLLER_H