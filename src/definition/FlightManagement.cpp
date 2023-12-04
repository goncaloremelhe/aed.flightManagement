
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
        airline.push_back(tempAirline);
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
        airport.push_back(tempAirport);
    }
}

void FlightManagement::readFlight() {
    ifstream input("../dataset/flights.csv");
    if (!input.is_open()) {
        cout << "Not read\n";
        return;
    }

    /*
    string line;
    getline(input, line);

    while (getline(input, line)) {

    }
     */
}

vector<Airport> FlightManagement::getAirports() {
    return airport;
}

vector<Airline> FlightManagement::getAirlines() {
    return airline;
}

