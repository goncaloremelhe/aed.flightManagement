
#include "../header/Menu.h"
#include <iostream>
#include <set>


void printStatisticsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Check global number of airports" << endl;
    cout << "2 - Check global number of available flights" << endl;
    cout << "3 - Check number of flights per airport, city or airline" << endl;
    cout << "4 - Check number of different countries connected to a specific airport or city" << endl;
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
        case 3:
            printNumberFlightsMenu(flightManagement);
            break;
        case 4:
            printDestinationOptionsMenu(flightManagement);
            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}

void printNumberFlightsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "You chose to check number of flights!" << endl;
    cout << "Choose one option:" << endl;
    cout << "1 - Check number of flights out of an airport" << endl;
    cout << "2 - Check number of flights per city" << endl;
    cout << "3 - Check number of flights per airline" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option: ";
    int option = 0;
    cin >> option;
    switch (option){
        case 1: {
            cout << "What is the code of the airport? [XXX] " << endl;
            cout << "Airport Code: ";
            string airportCode;
            cin >> airportCode;

            Graph<string> graph = flightManagement.getGraph();
            vector<Vertex<string>*> nodes = graph.getVertexSet();

            for (auto node : nodes){
                if(node->getInfo() == airportCode){
                    cout << "The number of flights out of the Airport " << airportCode << " is " << node->getAdj().size() << endl;

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
        case 2:{
            cout << "Enter the name of the city: ";
            string cityName;
            cin >> cityName;
            int numFlightsToCity = 0;
            int numFlightsOutCity = 0;

            Graph<string> graph = flightManagement.getGraph();
            vector<Vertex<string>*> nodes = graph.getVertexSet();
            unordered_map<string, Airport*> airports = flightManagement.getAirportMap();
            vector<string> airportsOfCity;

            //Primeiro confere quais os aeroportos da cidade
            for (auto element : airports){
                if(element.second->getCity() == cityName){
                    airportsOfCity.push_back(element.first);
                }
            }

            //Depois confere quantos voos saem e chegam desses aeroportos
            for (auto airportCode : airportsOfCity){
                for (auto node : nodes){
                    if(node->getInfo() == airportCode){
                        numFlightsOutCity += node->getAdj().size();}
                    else {
                        for (auto dest : node->getAdj()){
                            if (dest.getDest()->getInfo() == airportCode){
                                numFlightsToCity++;
                            }
                        }
                    }
                }
            }
            cout << "--------------------------------------------------\n";
            cout << "The number of flights involving the city " << cityName << " is " << (numFlightsToCity + numFlightsOutCity) << '.' << endl;
            cout << " There are " << numFlightsOutCity << " flights leaving the city." << endl;
            cout << " There are " << numFlightsToCity << " flights arriving in the city." << endl;
        }
            break;
        case 3:{
            cout << "Enter the airline's code: ";
            string airlineCode;
            cin >> airlineCode;
            int numFlightsAirline = 0;

            Graph<string> graph = flightManagement.getGraph();
            vector<Vertex<string>*> nodes = graph.getVertexSet();

            for (auto node : nodes){
                for (auto edge : node->getAdj()){
                    if (edge.getAirline() == airlineCode){
                        numFlightsAirline++;
                    }
                }
            }

            cout << "The number of flights operated by " << airlineCode << " is " << numFlightsAirline << '.' << endl;
        }
            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
        }
}

void printDestinationOptionsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "You chose to check how many different countries are connected to a specific airport or city!" << endl;
    cout << "Choose one option:" << endl;
    cout << "1 - Check number of different countries that a given airport flies to" << endl;
    cout << "2 - Check number of different countries that a given city flies to" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option: ";
    int option = 0;
    cin >> option;
    switch (option){
        case 1: {
        }
            break;
        case 2: {
        }
            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}