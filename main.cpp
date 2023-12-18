#include <iostream>
#include "src/header/FlightManagement.h"
#include "src/header/Menu.h"

int main() {
    FlightManagement flightManagement;
    flightManagement.readAirport();
    flightManagement.readAirline();
    flightManagement.readFlight();

    for (int i = 0; i < 40; i++) {
        Vertex<string>* v = flightManagement.getGraph().getVertexSet().at(i);
        unordered_map<string, Airport*> mapa = flightManagement.getAirportMap();
        Airport* airport = mapa[v->getInfo()];
        //cout << airport->getCode() << " " << airport->getName() << " " << airport->getCountry() << " " << airport->getCity() << "\n";
    }

    printStatisticsMenu(flightManagement);

    return 0;
}
