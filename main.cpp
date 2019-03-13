#include <iostream>

using namespace std;

class ParkedCar;
class ParkingMeter;
class ParkingTicket;
class PoliceOfficer;


class ParkedCar {
    string make;
    string model;
    string color;
    int licenceNum;
    int timeElapsed;

public:
    ParkedCar (string mk, string md, string c, int l, int te)
    {
        string make = mk;
        string model = md;
        string color = c;
        int licenceNum = l;
        int timeElapsed = te;
    }

    int timePassed () const
    {
        return timeElapsed;
    }

    void printCar () const;
};

void ParkedCar::printCar() const
{
    cout << "Make:              " << make << endl;
    cout << "Model:             " << model << endl;
    cout << "Color:             " << color << endl;
    cout << "Licence Number:    " << licenceNum << endl;
    cout << "Time Elapsed:      " << timeElapsed << endl << endl;
}


class ParkingMeter {

    int timePurchased;

public:
    int timeBought () const {
        return timePurchased;
    }

};


class ParkingTicket {
public:
    void illegalCarInfo (ParkedCar illegalCar);
    int fine (string tp, string te)
    {

    }

    void police (PoliceOfficer Cop)
    {
        Cop.printPolice();
    }

};

void ParkingTicket::illegalCarInfo (ParkedCar illegalCar)
{
    illegalCar.printCar();

}


class PoliceOfficer {
    string name;
    int badge;

public:

    void printPolice () const;

    void checkIllegal(ParkingMeter meter, ParkedCar car)
    {
        int tp = meter.timeBought ();
        int te = car.timePassed ();

        if (tp < te) {
            //car.illegalCarInfo (car);
        }

    }

};

void PoliceOfficer::printPolice() const
{
    cout << "Officer Name:  " << name << endl;
    cout << "Badge Number:  " << badge << endl;
}


int main() {

    /*
     * Chapter 14 Programming Challenge #14 Parking Ticket Sim Pg 889
     *
     * For this assignment you will design a set of classes that work together to simulate a police officer issuing a
     * parking ticket. The classes you should design are:
     *
     *      • The ParkedCar Class: This class should simulate a parked car. The class’s responsibilities are:
     *              – To know the car's make, model, color, license number, and the number of minutes that the car has
     *                been parked
     *
     *      • The ParkingMeter Class: This class should simulate a parking meter. The class’s only responsibility is:
     *              – To know the number of minutes of parking time that has been purchased
     *
     *      • The ParkingTicket Class: This class should simulate a parking ticket. The class’s responsibilities are:
     *              – To report the make, model, color, and license number of the illegally parked car
     *              – To report the amount of the fine, which is $25 for the first hour or part of an hour that the
     *                car is illegally parked, plus $10 for every additional hour or part of an hour that the car is
     *                illegally parked
     *              – To report the name and badge number of the police officer issuing the ticket
     *
     *      • The PoliceOfficer Class: This class should simulate a police officer inspecting parked cars. The class’s
     *        responsibilities are:
     *              – To know the police officer’s name and badge number
     *              – To examine a ParkedCar object and a ParkingMeter object, and determine whether the car's time
     *                has expired
     *              – To issue a parking ticket (generate a ParkingTicket object) if the car’s time has expired
     *
     * Write a program that demonstrates how these classes collaborate.
     */





    return 0;
}