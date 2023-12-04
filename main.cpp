#include <iostream>
#include "src/header/FlightManagement.h"

int main() {
    FlightManagement flightManagement;
    flightManagement.readAirport();
    flightManagement.readAirline();
    flightManagement.readFlight();

    //Para já esta a guardar Aeroportos e companhias em vetores
    //Temos de fazer isto em Grafos
    //readFlights por implementar

    return 0;
}
