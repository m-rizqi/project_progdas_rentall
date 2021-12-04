#pragma once
#include <iostream>
#include <vector>
#include "../../src/repository/Repository.cpp"
using namespace std;

#ifndef CAR_REPOSITORY_H
#define CAR_REPOSITORY_H

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

#endif