#ifndef FLIGHTMANAGEMENT_AIRLINE_H
#define FLIGHTMANAGEMENT_AIRLINE_H

#include <string>
using namespace std;

class Airline {
private:
    string code, name, callSign, country;
public:
    Airline(string code, string name, string callSign, string country);
    string getCode();
    string getName();
    string getCallSign();
    string getCountry();
};

#endif //FLIGHTMANAGEMENT_AIRLINE_H
