
#include "../header/FlightManagement.h"
#include "../header/Airport.h"
#include "../header/Airline.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void FlightManagement::readAirline() {
    ifstream input("../dataset/airlines.csv");
    if (!input.is_open()) {
        cout << "Not read\n";
        return;
    }

    string line;
    getline(input, line);

    while (getline(input, line)) {
        istringstream iss(line);
        string code, name, callSign, country;
        getline(iss, code, ',');
        getline(iss, name, ',');
        getline(iss, callSign, ',');
        getline(iss, country, ',');

        Airline tempAirline(code, name, callSign, country);
        airlineMap[code] = new Airline(tempAirline);

    }
}

void FlightManagement::readAirport() {
    ifstream input("../dataset/airports.csv");
    if (!input.is_open()) {
        cout << "Not read\n";
        return;
    }

    string line;
    getline(input, line);

    while (getline(input, line)) {

        istringstream iss(line);
        string code, name, city, country, latitude, longitude;
        getline(iss, code, ',');
        getline(iss, name, ',');
        getline(iss, city, ',');
        getline(iss, country, ',');
        getline(iss, latitude, ',');
        getline(iss, longitude, ',');
        float newLatitude = stof(latitude);
        float newLongitude = stof(longitude);

        Airport tempAirport(code, name, city, country, newLatitude, newLongitude);
        flightManagement.addVertex(code);
        airportMap[code] = new Airport(tempAirport);
    }
}

void FlightManagement::readFlight() {
    ifstream input("../dataset/flights.csv");
    if (!input.is_open()) {
        cout << "Not read\n";
        return;
    }

    string line;
    getline(input, line);

    while (getline(input, line)) {

        istringstream iss(line);
        string source, target, airline;
        getline(iss, source, ',');
        getline(iss, target, ',');
        getline(iss, airline, ',');

        flightManagement.addEdge(source,target,0,airline);
    }
}

FlightManagement::~FlightManagement() {
    for (auto const& airline : airlineMap) {
        delete airline.second;
    }

    for (auto const& airport : airportMap) {
        delete airport.second;
    }
}

Graph<string> FlightManagement::getGraph() const{
    return flightManagement;
}

unordered_map<string, Airport *> FlightManagement::getAirportMap() const {
    return airportMap;
}

unordered_map<string, Airline *> FlightManagement::getAirlineMap() const{
    return airlineMap;
}

