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
                printGlobalStatistics(flightManagement);
                break;
            case '2':
                printNumberFlightsMenu(flightManagement);
                break;
            case '3':
                printDestinationOptionMenu(flightManagement);
                break;
            case '4':
                printLayoverMenu(flightManagement);
                break;
            case '5':
                printAirportsGreatestCapability(flightManagement);
                break;
            case '6':
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
