#pragma once
#include <iostream>
#include <vector>
#include "../../src/repository/Repository.cpp"
#include "../../src/model/Car.cpp"
using namespace std;

class CarRepository : public Repository<Car>{
public:
    /**
     * constructor
     */
    CarRepository();
    /**
     * @param name
     */
    Car searchByName(string name);
private:
};