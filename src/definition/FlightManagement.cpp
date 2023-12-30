
#include "../header/FlightManagement.h"
#include "../header/Airport.h"
#include "../header/Airline.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string upperCase(const std::string &str) {
    string s;
    for (char c : str) {
        s += toupper(c);
    }
    return s;
}


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

        city = upperCase(city);
        country = upperCase(country);

        Airport tempAirport(code, name, city, country, newLatitude, newLongitude);
        flightManagement.addVertex(code);
        airportMap[code] = new Airport(tempAirport);
    }

    for (Vertex<string>* vertex : flightManagement.getVertexSet()) {
        vertex->setIndegree(0);
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

        Vertex<string>* vertex = flightManagement.findVertex(target);
        if (vertex != NULL) {
            vertex->setIndegree(vertex->getIndegree() + 1);
        }
        airlineMap[airline]->incrementFlights();
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

