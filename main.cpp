#include <iostream>

using namespace std;

// This class creates a parked car
class ParkedCar {
    string make;
    string model;
    string color;
    string licenseNum;
    double timeElapsed;

public:
    // Declare Car Object
    ParkedCar (string mk, string md, string c, string l, double te)
    {
        make = mk;
        model = md;
        color = c;
        licenseNum = l;
        timeElapsed = te;
    }

    // Allows timeElapsed to be easily accessed
    double timePassed () const
    {
        return timeElapsed;
    }

    // Print out info about car
    void printCar () const {
        cout << "Make:              " << make << endl;
        cout << "Model:             " << model << endl;
        cout << "Color:             " << color << endl;
        cout << "License Number:    " << licenseNum << endl;
        cout << "Hours Elapsed:     " << timeElapsed << endl << endl;
    }
};

// This class creates a parking meter
class ParkingMeter {
    double timePurchased;

public:
    // Declare ParkingMeter Object
    ParkingMeter (double tp)
    {
        timePurchased = tp;
    }

    // Allows timePurchased to be easily accessed
    double timeBought () const {
        return timePurchased;
    }

};

// This class creates a parking ticket
class ParkingTicket {
public:
    // Determines what the fine amount is
    void fine (double tp, double te)
    {
        // For the first hour the fine is $25, so that's the base amount
        int fineOwed = 25;
        double timeOver = te - tp;

        // For every hour past the first there is an additional $10 charge
        if (timeOver > 1)
        {
            // This determines how many hours there are past the first (in other words, [(hours_over - 1) * 10])
            for (int i = 1; (float)i < timeOver; i++)
            {
                fineOwed += 10;
            }
        }

        cout << "The fine is:       $ " << fineOwed << endl << endl;
    }

};

class PoliceOfficer {
    string name;
    int badge;

public:

    // Declare PoliceOfficer Object
    PoliceOfficer (string n, int b){
        name = n;
        badge = b;
    }

    // Check if a car is illegally parked after the meter is up
    void checkIllegal(ParkingMeter meter, ParkedCar car)
    {
        // Get how much time was payed for and how long the car has been there
        double tp = meter.timeBought ();
        double te = car.timePassed ();

        // If the car has been there longer than payed for, then issue a ticket
        if (tp < te)
        {
            ParkingTicket ticket;

            // Print car info, meter info, what the fine is, and who is issuing the ticket
            car.printCar();
            cout << "Hours Purchased:   " << tp << endl << endl;
            ticket.fine(tp, te);
            cout << "Officer Name:  " << name << endl;
            cout << "Badge Number:  " << badge << endl;

        }
    }
};


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

    // Declare objects
    PoliceOfficer policeOfficer = PoliceOfficer ("Jim Lawman", 123456);
    ParkingMeter parkingMeter = ParkingMeter (2);
    ParkedCar parkedCar = ParkedCar("Honda", "Accord", "Blue", "1ABC234", 3.5);

    // Check if car is parked illegally
    policeOfficer.checkIllegal (parkingMeter, parkedCar);

    return 0;
}