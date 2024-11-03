#ifndef CARGO_H
#define CARGO_H

#include <iostream>
#include "AirVehicle.h"

using namespace std;


class Cargo : public AirVehicle
{
    private:
        int capacity;
        int maxCapacity;
        string name = "General Cargo";
    public:
        Cargo();
        ~Cargo();
        AirVehicle* clone();
        bool isFull();
        void setCapacity(int cap);
        void setMaxCapacity(int cap);
        string getName();
        void setName(string name);

    protected:
        

};

#endif