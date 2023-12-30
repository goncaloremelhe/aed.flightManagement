#ifndef FLIGHTMANAGEMENT_AIRLINE_H
#define FLIGHTMANAGEMENT_AIRLINE_H

#include <string>
using namespace std;

class Airline {
    string code, name, callSign, country;
    int flights;
public:
    Airline(string code, string name, string callSign, string country);
    void incrementFlights();
    string getCode();
    string getName();
    string getCallSign();
    string getCountry();
    int getFlights() const;
};

#endif //FLIGHTMANAGEMENT_AIRLINE_H
