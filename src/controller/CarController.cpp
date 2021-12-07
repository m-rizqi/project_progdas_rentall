/**
 * Project Untitled
 */


#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <iostream>
#include "../../include/controller/CarController.h"

/**
 * CarController implementation
 * 
 * Child class from Controller to handle about car
 */

CarController::CarController()
{
    this->carRepository = CarRepository();
}

void CarController::registerCar(){

    int n;

    cout<<"-- R E G I S T E R   C A R --\n";
    
    cout<<"Berapa Mobil yang ingin Anda dimasukkkan: \n";
    cin>>n;

    cout<<"Silahkan isi form berikut dengan benar\n";

    for(int i=1; i <= n; i++){

        string nama, nomor_polisi;
        bool rent_status;
        
        cout<<"Nama Mobil";
        cin>>nama;

        cout<<"Nomor Polisi: ";
        cin>>nomor_polisi;

        cout<<"Rented: ";
        cin>>rent_status;

        Car car = Car(0, nama, nomor_polisi, rent_status);
        carRepository.appendData(car);

        cout<<"Data sudah tersimpan";
    }

}   /**
    Function to edit a car  
    */
void CarController::updateCar(){

    

}

