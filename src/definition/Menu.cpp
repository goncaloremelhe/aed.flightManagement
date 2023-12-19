
#include "../header/Menu.h"
#include <unordered_set>
#include <iostream>
#include <set>
#include <algorithm>


void printStatisticsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Check global number of airports or flights" << endl;
    cout << "2 - Check global number of available flights" << endl;
    cout << "3 - Check number of flights per airport, city or airline" << endl;
    cout << "4 - Check number of different countries connected to a specific airport or city" << endl;
    cout << "5 - Check number of destinations available for a given airport;" << endl;
    cout << "6 - Check number of reachable destinations with X lay-overs from a given airport" << endl;
    cout << "7 - Check maximum trips with the greatest number of stops between them" << endl;
    cout << "8 - Check top-k airports with the greatest traffic capacity" << endl;
    cout << "9 - Identify the airports that are essential to the network's circulation capability" << endl;
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
        case 7:
            printMaximumTrip(flightManagement);
            break;
        case 8:
            printAirportsGreatestCapability(flightManagement);
            break;
        case 9:
            printEssentialAirports(flightManagement);
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
            printNumberCitiesWithStops(flightManagement);
            break;
        case 3:
            printNumberCountriesWithStops(flightManagement);
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

vector<string> reachableDest(const FlightManagement& flightManagement, string sourceAirportCode, int maxStops){
    Graph<string> graph = flightManagement.getGraph();
    Vertex<string> * s = graph.findVertex(sourceAirportCode);
    vector<string> reachableDest;

    if (s == NULL){
        return reachableDest;
    }

    for (auto node : graph.getVertexSet()){
        node->setVisited(false);
    }

    queue<Vertex<string> * > unvisited;
    s->setIndegree(0);
    unvisited.push(s);
    s->setVisited(true);
    while(!unvisited.empty()){
        auto v = unvisited.front();
        unvisited.pop();
        for (auto & neighbor : v->getAdj()){
            auto w = neighbor.getDest();
            if(!w->isVisited()){
                w->setIndegree(v->getIndegree()+1);
                unvisited.push(w);
                w->setVisited(true);}
        }
        if (v->getIndegree() <= maxStops)
            reachableDest.push_back(v->getInfo());
    }

    return reachableDest;
}

void printNumberAirportsWithStops(const FlightManagement& flightManagement){
    cout << "Enter the code of the source airport: ";
    string sourceAirportCode;
    cin >> sourceAirportCode;

    cout << "Enter the maximum number of stops (X): ";
    int maxStops;
    cin >> maxStops;

    vector<string> reachable = reachableDest(flightManagement, sourceAirportCode, maxStops);
    int numDestinations = reachable.size() - 1; // tira ele mesmo

    cout << "The number of destination airports reachable from " << sourceAirportCode << " in a maximum of " << maxStops << " stops is: " << numDestinations << endl;
    cout << " Do you want to consult which cities are available? [Y/N]" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y'){
        for (auto destination : reachable){
            cout << destination << endl;
        }
    }
}

void printNumberCitiesWithStops(const FlightManagement& flightManagement){
    cout << "Enter the code of the source airport: ";
    string sourceAirportCode;
    cin >> sourceAirportCode;

    cout << "Enter the maximum number of stops (X): ";
    int maxStops;
    cin >> maxStops;

    vector<string> reachable = reachableDest(flightManagement, sourceAirportCode, maxStops);
    set<string> citiesDest;
    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    for (auto destinationAirport : reachable){
        for (auto element : allAirports){
            if(element.first == destinationAirport){
                citiesDest.insert(element.second->getCity());
            }
        }
    }

    int numDestinations = citiesDest.size();

    cout << "The number of destination cities reachable from " << sourceAirportCode << " in a maximum of " << maxStops << " stops is: " << numDestinations << endl;
    cout << " Do you want to consult which cities are available? [Y/N]" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y'){
        for (auto destination : reachable){
            cout << destination << endl;
        }
    }
}

void printNumberCountriesWithStops(const FlightManagement& flightManagement){
    cout << "Enter the code of the source airport: ";
    string sourceAirportCode;
    cin >> sourceAirportCode;

    cout << "Enter the maximum number of stops (X): ";
    int maxStops;
    cin >> maxStops;

    vector<string> reachable = reachableDest(flightManagement, sourceAirportCode, maxStops);
    set<string> countriesDest;
    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    for (auto destinationAirport : reachable){
        for (auto element : allAirports){
            if(element.first == destinationAirport){
                countriesDest.insert(element.second->getCountry());
            }
        }
    }

    int numDestinations = countriesDest.size();

    cout << "The number of destination countries reachable from " << sourceAirportCode << " in a maximum of " << maxStops << " stops is: " << numDestinations << endl;
    cout << " Do you want to consult which countries are available? [Y/N]" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y'){
        for (auto destination : reachable){
            cout << destination << endl;
        }
    }
}

void printMaximumTrip(const FlightManagement& flightManagement){
    Graph<string> graph = flightManagement.getGraph();
    Vertex<string> * s = graph.getVertexSet().front();
    vector<string> reachableDest;
    int max = 0;

    if (s == NULL)
        return;


    for (auto node : graph.getVertexSet()){
        node->setVisited(false);
    }

    // fazer o resto aqui

}

void printAirportsGreatestCapability(const FlightManagement& flightManagement){
    cout << "Enter the value of k for top-k airports: ";
    int k;
    cin >> k;

    Graph<string> graph = flightManagement.getGraph();
    vector<Vertex<string>*> nodes = graph.getVertexSet();
    set<pair<int, string>, greater<pair<int, string>>> totalFlights;

    int numFlightsToAirport = 0;
    int numFlightsOut = 0;

    for (auto specificNode : nodes){
        numFlightsToAirport = 0;
        for (auto node : nodes){
            if (node->getInfo() == specificNode->getInfo()) {
                numFlightsOut = node->getAdj().size();
            } else {
                for (auto dest : node->getAdj()){
                    if (dest.getDest()->getInfo() == specificNode->getInfo())
                        numFlightsToAirport++;
                }
            }
        }

        int total = numFlightsToAirport + numFlightsOut;
        totalFlights.insert(make_pair(total, specificNode->getInfo()));

    }

    cout << "Top " << k << " airports by traffic capacity:" << endl;
    int i = 0;
    for (const auto& airport : totalFlights) {
        if (i >= k) {
            break;
        }
        cout << airport.second << " - " << airport.first << " flights" << endl;
        i++;
    }
}


void printEssentialAirports(const FlightManagement& flightManagement){
    Graph<string> graph = flightManagement.getGraph();
    unordered_set<string> essentialAirports;
    stack<string> s;

    int i = 0;
    for (auto element : graph.getVertexSet()){
        element->setVisited(false);
        element->setProcessing(false);
        element->setNum(i);
    }
    i++;

    for (auto element : graph.getVertexSet()){
        if (element->getNum() == 0){
            dfs_art(graph, element, s, essentialAirports, i);
        }
    }

    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    cout << "There are " << essentialAirports.size() <<  " essential airports to the network's circulation capability: " << endl;
    cout << "Code     Name" << endl;
    for (auto element : essentialAirports){
        for (auto airport : allAirports){
            if (element == airport.first){
                cout << airport.first << " " << airport.second->getName() << endl;
            }
        }
    }
}

void dfs_art(Graph<string> g, Vertex<string> *v, stack<string> &s, unordered_set<string> &l, int &i){
    v->setProcessing(true);
    v->setNum(i);
    v->setLow(i);
    i++;

    int children = 0;
    for (auto element : v->getAdj()){
        if(element.getDest()->getNum() == 0){
            children++;
            dfs_art(g, element.getDest(), s, l, i);
            v->setLow(min(element.getDest()->getLow(), v->getLow()));
            if(v != g.getVertexSet().at(0) &&element.getDest()->getLow() >= v->getNum()) {
                l.insert(v->getInfo());
            }
        } else if(element.getDest()->isProcessing()){
            v->setLow(min(element.getDest()->getNum(), v->getLow()));
        }

    }

    v->setProcessing(false);
    if(v == g.getVertexSet().at(0) &&children > 1){
        l.insert(v->getInfo());
    }
}