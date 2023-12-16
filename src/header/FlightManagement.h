#ifndef FLIGHTMANAGEMENT_FLIGHTMANAGEMENT_H
#define FLIGHTMANAGEMENT_FLIGHTMANAGEMENT_H

#include <vector>
#include "Airport.h"
#include "Airline.h"
#include "Graph.h"
#include <unordered_map>

class FlightManagement {
private:
    Graph<string> flightManagement;
    unordered_map<string, Airport*> airportMap;
    unordered_map<string, Airline*> airlineMap;
public:
    FlightManagement() = default;
    ~FlightManagement();
    void readAirline();
    void readAirport();
    void readFlight();
    Graph<string> getGraph();
    unordered_map<string, Airport*> getAirportMap();
    unordered_map<string, Airline*> getAirlineMap();
};

#endif //FLIGHTMANAGEMENT_FLIGHTMANAGEMENT_H
