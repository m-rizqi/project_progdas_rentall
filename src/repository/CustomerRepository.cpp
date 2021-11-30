#include "../../include/repository/CustomerRepository.h"

CustomerRepository* CustomerRepository::_instance = NULL;

CustomerRepository* CustomerRepository::getInstance(){
    if(CustomerRepository::_instance == NULL){
        CustomerRepository::_instance = new CustomerRepository();
    }
    return CustomerRepository::_instance;
}

void CustomerRepository::test(){
    cout<<"Test"<<endl;
}