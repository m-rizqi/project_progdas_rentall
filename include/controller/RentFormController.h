#include "../../include/repository/RentRepository.h"

#ifndef _RENTFORMCONTROLLER_H
#define _RENTFORMCONTROLLER_H

class RentFormController {
public: 

void rentCar();
    
void returnCar();
private :
RentRepository rentRepository;
};

#endif //_RENTFORMCONTROLLER_H