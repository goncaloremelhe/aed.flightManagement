#include <iostream>
#include "src/header/FlightManagement.h"
#include "src/header/Menu.h"

int main() {
    FlightManagement flightManagement;
    flightManagement.readAirport();
    flightManagement.readAirline();
    flightManagement.readFlight();

    char option = '0';
    bool flag = true;
    while (flag) {
        printStatisticsMenu();
        cin >> option;
        switch (option){
            case '1':
                printGlobalAirports(flightManagement);
                break;
            case '2':
                printGlobalFlights(flightManagement);
                break;
            case '3':
                printNumberFlightsMenu(flightManagement);
                break;
            case '4':
                printCountriesOptionsMenu(flightManagement);
                break;
            case '5':
                printDestinationOptionMenu(flightManagement);
                break;
            case '6':
                printDestinationWithStopsMenu(flightManagement);
                break;
            case '7':
                printMaximumTrip(flightManagement);
                break;
            case '8':
                printAirportsGreatestCapability(flightManagement);
                break;
            case '9':
                printEssentialAirports(flightManagement);
                break;
            case '0':
                flag = false;
                break;
            default:
                cout << "Invalid option. Exiting." << endl;
                break;
        }
    }

    cout << "--------------------------------------------------\n";
    cout << "Exiting..." << endl;
    cout << "--------------------------------------------------\n";
    cout << "Goodbye!" << endl;
    return 0;
}
