/**
 * Project Untitled
 */


#ifndef _CARCONTROLLER_H
#define _CARCONTROLLER_H
#include "../../src/repository/CarRepository.cpp"


class CarController {
public: 
    
//void displayFormat();
    
//void searchData();


/**
     *  constructor
     */
    CarController();
    /**
     * function to register a Car
     */
    void registerCar();

    /**
     * function to edit and save Car
     */
    void updateCar();

    /**
     * function to delete Car
     */
    void deleteCar();

    /**
     * function to show multiple Car
     */
    void displayCars(int entry);

    /**
     * function to show previous page of display Car
     */
    void navigatePrevious(int entry, int idx, vector<Car> carList);

    /**
     * function to show next page of display Car
     */
    void navigateNext(int entry, int idx, vector<Car> carList);

    /**
     * function to search one or multiple Car by condition
     */
    void searchCar();
private:
    CarRepository carRepository;

};

#endif //_CARCONTROLLER_H