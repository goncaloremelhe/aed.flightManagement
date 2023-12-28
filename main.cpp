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
        printMainMenu();
        cin >> option;
        switch (option){
            case '1':
                printStatisticsMenu(flightManagement);
                break;
            case '2':
                printBestFlight(flightManagement);
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
