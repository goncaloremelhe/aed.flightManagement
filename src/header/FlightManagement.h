#ifndef FLIGHTMANAGEMENT_FLIGHTMANAGEMENT_H
#define FLIGHTMANAGEMENT_FLIGHTMANAGEMENT_H

#include <vector>
#include "Airport.h"
#include "Airline.h"

class FlightManagement {
private:
    vector<Airport> airport;
    vector<Airline> airline;
public:
    FlightManagement() = default;
    void readAirline();
    void readAirport();
    void readFlight();
    vector<Airport> getAirports();
    vector<Airline> getAirlines();
};

#endif //FLIGHTMANAGEMENT_FLIGHTMANAGEMENT_H
