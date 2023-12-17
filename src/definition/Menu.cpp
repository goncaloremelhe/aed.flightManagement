
#include "../header/Menu.h"
#include <iostream>


void printStatisticsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Check global number of airports;" << endl;
    cout << "2 - Check global number of available flights;" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option: ";
    int option = 0;
    cin >> option;
    switch (option){
        case 1: {
            Graph<string> graph = flightManagement.getGraph();
            int numAirports = graph.getNumVertex();
            cout << "The global number of airports is " << numAirports << '.' << endl; }
            break;
        case 2: {
            Graph<string> graph = flightManagement.getGraph();
            vector<Vertex<string>*> nodes = graph.getVertexSet();
            int numFlights = 0;

            for (auto node : nodes){
                numFlights += node->getAdj().size();
            }

            cout << "The global number of available flights is " << numFlights << '.' << endl; }
            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}
