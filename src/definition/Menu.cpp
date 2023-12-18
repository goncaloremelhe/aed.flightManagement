
#include "../header/Menu.h"
#include <unordered_set>
#include <iostream>
#include <set>


void printStatisticsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Check global number of airports" << endl;
    cout << "2 - Check global number of available flights" << endl;
    cout << "3 - Check number of flights per airport, city or airline" << endl;
    cout << "4 - Check number of different countries connected to a specific airport or city" << endl;
    cout << "5 - Check number of destinations available for a given airport;" << endl;
    cout << "6 - Check number of reachable destinations with X lay-overs from a given airport" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option: ";
    int option = 0;
    cin >> option;
    switch (option){
        case 1:
            printGlobalAirports(flightManagement);
            break;
        case 2:
            printGlobalFlights(flightManagement);
            break;
        case 3:
            printNumberFlightsMenu(flightManagement);
            break;
        case 4:
            printCountriesOptionsMenu(flightManagement);
            break;
        case 5:
            printDestinationOptionMenu(flightManagement);
            break;
        case 6:
            printDestinationWithStopsMenu(flightManagement);
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
        case 1:
            printNumFlights_outAirport(flightManagement);
            break;
        case 2:
            printNumFlights_perCity(flightManagement);
            break;
        case 3:
            printNumFlights_perAirline(flightManagement);
            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
        }
}

void printCountriesOptionsMenu(const FlightManagement& flightManagement){
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
        case 1:
            printNumCountries_perCity(flightManagement);
            break;
        case 2:
            printNumCountries_perCity(flightManagement);
            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}

void printDestinationOptionMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "You chose to check how many destinations are available to a specific airport!" << endl;
    cout << "Choose one option:" << endl;
    cout << "1 - Check number of destination airports available for a given airport" << endl;
    cout << "2 - Check number of destination cities available for a given airport" << endl;
    cout << "3 - Check number of destination countries available for a given airport" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option: ";
    int option = 0;
    cin >> option;
    switch (option) {
        case 1:
            printNumAirports_perAirport(flightManagement);
            break;
        case 2:
            printNumCities_perAirport(flightManagement);
            break;
        case 3:
            printNumCountries_perAirport(flightManagement);
            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}

void printDestinationWithStopsMenu(const FlightManagement flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "You chose to check how many destinations are reachable from an airport in a maximum of X stops!" << endl;
    cout << "Choose one option:" << endl;
    cout << "1 - Check number of destination airports available for a given airport in a maximum of X stops" << endl;
    cout << "2 - Check number of destination cities available for a given airport in a maximum of X stops" << endl;
    cout << "3 - Check number of destination countries available for a given airport in a maximum of X stops" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option: ";
    int option = 0;
    cin >> option;
    switch (option) {
        case 1:
            printNumberAirportsWithStops(flightManagement);
            break;
        case 2:

            break;
        case 3:

            break;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}

void printGlobalAirports(const FlightManagement& flightManagement){
    Graph<string> graph = flightManagement.getGraph();
    int numAirports = graph.getNumVertex();
    cout << "The global number of airports is " << numAirports << '.' << endl;
}

void printGlobalFlights(const FlightManagement& flightManagement){
    Graph<string> graph = flightManagement.getGraph();
    vector<Vertex<string>*> nodes = graph.getVertexSet();
    int numFlights = 0;

    for (auto node : nodes)
        numFlights += node->getAdj().size();

    cout << "The global number of available flights is " << numFlights << '.' << endl;
}

void printNumFlights_outAirport(const FlightManagement& flightManagement){
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

void printNumFlights_perCity(const FlightManagement& flightManagement){
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

void printNumFlights_perAirline(const FlightManagement& flightManagement){
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

void printNumCountries_perAirport(const FlightManagement& flightManagement){
    cout << "Enter the code of the airport: ";
    string airportCode;
    cin >> airportCode;

    Graph<string> graph = flightManagement.getGraph();
    vector<Vertex<string>*> nodes = graph.getVertexSet();
    unordered_set<string> airports;

    for (auto node : nodes) {
        if (node->getInfo() == airportCode) {
            for (auto edge : node->getAdj()) {
                string destinationAirportCode = edge.getDest()->getInfo();
                airports.insert(destinationAirportCode);
            }
        }
    }

    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    set<string> countries;
    for (auto destinationAirport : airports){
        for (auto element : allAirports){
            if(element.first == destinationAirport){
                countries.insert(element.second->getCountry());
            }
        }
    }

    int numCountries = countries.size();
    cout << "The airport " << airportCode << " is connected to " << numCountries << " different countries." << endl;
    cout << " Do you want to consult which countries are available? [Y/N]" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y'){
        for (auto destination : countries){
            cout << destination << endl;
        }
    }
}

void printNumCountries_perCity(const FlightManagement& flightManagement){
    cout << "Enter the name of the city: ";
    string cityName;
    cin >> cityName;

    Graph<string> graph = flightManagement.getGraph();
    vector<Vertex<string>*> nodes = graph.getVertexSet();
    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    vector<string> airportsOfCity;

    for (auto element : allAirports) {
        if(element.second->getCity() == cityName){
            airportsOfCity.push_back(element.first);
        }
    }


    unordered_set<string> airportsDestination;
    for (auto airport : airportsOfCity) {
        for (auto node : nodes){
            if (node->getInfo() == airport){
                for (auto edge : node->getAdj()){
                    airportsDestination.insert(edge.getDest()->getInfo());
                }
            }
        }
    }

    set<string> countries;
    for (auto destinationAirport : airportsDestination){
        for (auto element : allAirports){
            if(element.first == destinationAirport){
                countries.insert(element.second->getCountry());
            }
        }
    }

    int numCountries = countries.size();
    cout << "The city " << cityName << " is connected to " << numCountries << " different countries." << endl;
    cout << " Do you want to consult which countries are available? [Y/N]" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y') {
        for (auto destination : countries) {
            cout << destination << endl;
        }
    }
}

void printNumAirports_perAirport(const FlightManagement& flightManagement){
    cout << "Enter the code of the airport: ";
    string airportCode;
    cin >> airportCode;

    Graph<string> graph = flightManagement.getGraph();
    vector<Vertex<string>*> nodes = graph.getVertexSet();
    unordered_set<string> airports;

    for (auto node : nodes) {
        if (node->getInfo() == airportCode) {
            for (auto edge : node->getAdj()) {
                string destinationAirportCode = edge.getDest()->getInfo();
                airports.insert(destinationAirportCode);
            }
        }
    }

    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    set<string> airportsDest;
    for (auto destinationAirport : airports){
        for (auto element : allAirports){
            if(element.first == destinationAirport){
                airportsDest.insert(element.second->getName());
            }
        }
    }

    int numAirports = airportsDest.size();
    cout << "The airport " << airportCode << " is connected to " << numAirports << " different airports." << endl;
    cout << " Do you want to consult which airports are available? [Y/N]" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y'){
        for (auto destination : airportsDest){
            cout << destination << endl;
        }
    }
}
void printNumCities_perAirport(const FlightManagement& flightManagement){
    cout << "Enter the code of the airport: ";
    string airportCode;
    cin >> airportCode;

    Graph<string> graph = flightManagement.getGraph();
    vector<Vertex<string>*> nodes = graph.getVertexSet();
    unordered_set<string> airports;

    for (auto node : nodes) {
        if (node->getInfo() == airportCode) {
            for (auto edge : node->getAdj()) {
                string destinationAirportCode = edge.getDest()->getInfo();
                airports.insert(destinationAirportCode);
            }
        }
    }

    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    set<string> citiesDest;
    for (auto destinationAirport : airports){
        for (auto element : allAirports){
            if(element.first == destinationAirport){
                citiesDest.insert(element.second->getCity());
            }
        }
    }

    int numCities = citiesDest.size();
    cout << "The airport " << airportCode << " is connected to " << numCities << " different cities." << endl;
    cout << " Do you want to consult which cities are available? [Y/N]" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y'){
        for (auto destination : citiesDest){
            cout << destination << endl;
        }
    }
}

void printNumberAirportsWithStops(const FlightManagement& flightManagement){
        cout << "Enter the code of the source airport: ";
        string sourceAirportCode;
        cin >> sourceAirportCode;

        cout << "Enter the maximum number of stops (X): ";
        int maxStops;
        cin >> maxStops;

        Graph<string> graph = flightManagement.getGraph();
        Vertex<string> * s = graph.findVertex(sourceAirportCode);
        vector<string> reachableDest;

        if (s == NULL){
            return;
        }

        for (auto node : graph.getVertexSet()){
            node->setVisited(false);
        }

        queue<pair<Vertex<string> *, int>> unvisited;
        unvisited.push(make_pair(s, 0));
        s->setVisited(true);
        while(!unvisited.empty()){
            auto v = unvisited.front();
            unvisited.pop();
            for (auto & neighbor : v.first->getAdj()){
                auto w = neighbor.getDest();
                if(!w->isVisited())
                    unvisited.push(make_pair(w, v.second+1));
                    w->setVisited(true);
            }
            if (v.second <= maxStops)
                reachableDest.push_back(v.first->getInfo());
        }

        int numDestinations = reachableDest.size() - 1; // tira ele mesmo

        cout << "The number of destination airports reachable from " << sourceAirportCode << " in a maximum of " << maxStops << " stops is: " << numDestinations << endl;
}
