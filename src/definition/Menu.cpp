
#include "../header/Menu.h"
#include <iostream>
#include <set>


void printStatisticsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Check global number of airports" << endl;
    cout << "2 - Check global number of available flights" << endl;
    cout << "3 - Check number of flights of an airport" << endl;
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
        case 3:{
            cout << "What is the code of the airport? [XXX] " << endl;
            cout << "Airport Code: ";
            string airportCode;
            cin >> airportCode;

            Graph<string> graph = flightManagement.getGraph();
            vector<Vertex<string>*> nodes = graph.getVertexSet();

            for (auto node : nodes){
                if(node->getInfo() == airportCode){
                    cout << "The number of flights out of the Airport " + airportCode + " is " + to_string(node->getAdj().size()) << endl;

                    set<string> uniqueAirlines;
                    for (auto edge : node->getAdj()) {
                        uniqueAirlines.insert(edge.getAirline());
                    }

                    int numberOfAirlines = uniqueAirlines.size();
                    cout << " Those flights are from " << numberOfAirlines << " different airlines." << endl;
                }
            }
        }
            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}
