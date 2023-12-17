#include "../header/Menu.h"


void printStatisticsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Check global number of airports;" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    int option = 0;
    cin >> option;
    switch (option){
        case 1:
            int numAirports;
            numAirports = flightManagement.getAirportMap().size();
            cout << "The global number of airports is " << numAirports << '.' << endl;
            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}
