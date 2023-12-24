
#include "../header/Menu.h"
#include <unordered_set>
#include <iostream>
#include <set>
#include <algorithm>
#include <limits>
#include <iomanip>

struct airportComparator {
    bool operator()(const Airport* firstAirport, const Airport* secondAirport) const {
        return *firstAirport < *secondAirport;
    }
};


void printStatisticsMenu(){
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Global statistics" << endl;                                                                        //Check
    cout << "2 - Total number of flights per airport/city/airline" << endl;                                         //Check
    cout << "3 - Countries connected to a specific airport/city" << endl;
    cout << "4 - Check number of destinations available for a given airport;" << endl;
    cout << "5 - Consult reachable destinations with 'n' layovers" << endl;                                         //Check, a pensar em mais
    cout << "6 - Check maximum trips with the greatest number of stops between them" << endl;
    cout << "7 - Check the airports with the most traffic" << endl;                                                 //Check
    cout << "8 - Consult the essential airports" << endl;
    cout << "0 - Exit" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
}


void printNumberFlightsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Choose one option:" << endl;
    cout << "1 - Total flights of an airport" << endl;
    cout << "2 - Total flights of a city" << endl;
    cout << "3 - Total flights of an airline" << endl;
    cout << "0 - Return to the main menu" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    char option = '0';
    cin >> option;
    switch (option){
        case '1':
            printNumFlights_outAirport(flightManagement);
            break;
        case '2':
            printNumFlights_perCity(flightManagement);
            break;
        case '3':
            printNumFlights_perAirline(flightManagement);
            break;
        case '0':
            cout << "--------------------------------------------------\n";
            cout << "Returning to the main menu." << endl;
            return;
        default:
            cout << "--------------------------------------------------\n";
            cout << "Invalid option. Please, try again." << endl;
            break;
        }
}

void printCountriesOptionsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "You chose to check how many different countries are connected to a specific airport or city!" << endl;
    cout << "Choose one option:" << endl;
    cout << "1 - Check number of different countries that a given airport flies to" << endl;
    cout << "2 - Check number of different countries that a given city flies to" << endl;
    cout << "0 - Return to the main menu" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    char option = '0';
    cin >> option;
    switch (option){
        case '1':
            printNumCountries_perAirport(flightManagement);
            break;
        case '2':
            printNumCountries_perCity(flightManagement);
            break;
        case '0':
            cout << "--------------------------------------------------\n";
            cout << "Returning to the main menu." << endl;
            return;
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
    cout << "0 - Return to the main menu" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    char option = '0';
    cin >> option;
    switch (option) {
        case '1':
            printNumAirports_perAirport(flightManagement);
            break;
        case '2':
            printNumCities_perAirport(flightManagement);
            break;
        case '3':
            printNumCountries_perAirport(flightManagement);
            break;
        case '0':
            cout << "--------------------------------------------------\n";
            cout << "Returning to the main menu." << endl;
            return;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}

/*
void printDestinationWithStopsMenu(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "You chose to check how many destinations are reachable from an airport in a maximum of X stops!" << endl;
    cout << "Choose one option:" << endl;
    cout << "1 - Check number of destination airports available for a given airport in a maximum of X stops" << endl;
    cout << "2 - Check number of destination cities available for a given airport in a maximum of X stops" << endl;
    cout << "3 - Check number of destination countries available for a given airport in a maximum of X stops" << endl;
    cout << "0 - Return to the main menu" << endl;
    cout << "--------------------------------------------------\n";
    cout << "Option:";
    char option = '0';
    cin >> option;
    switch (option) {
        case '1':
            printNumberAirportsWithStops(flightManagement);
            break;
        case '2':
            printNumberCitiesWithStops(flightManagement);
            break;
        case '3':
            printNumberCountriesWithStops(flightManagement);
            break;
        case '0':
            cout << "--------------------------------------------------\n";
            cout << "Returning to the main menu." << endl;
            return;
        default:
            cout << "Invalid option. Exiting." << endl;
            break;
    }
}
 */


void printGlobalStatistics(const FlightManagement& flightManagement){
    Graph<string> graph = flightManagement.getGraph();
    int numAirports = graph.getNumVertex();
    int numAirlines = flightManagement.getAirlineMap().size();

    vector<Vertex<string>*> nodes = graph.getVertexSet();
    int numFlights = 0;

    unordered_map<string, Airport*> airportMap = flightManagement.getAirportMap();
    unordered_set<string> countriesSet;
    unordered_set<string> citiesSet;

    for (Vertex<string> *node: nodes) {
        numFlights += node->getAdj().size();
        Airport* airport = airportMap[node->getInfo()];
        countriesSet.insert(airport->getCountry());
        citiesSet.insert(airport->getCity());
    }


    cout << "--------------------------------------------------\n";
    cout << "There are a total of:" << endl;
    cout << "     - " << numAirports << " airports;" << endl;
    cout << "     - " << numFlights << " flights;" << endl;
    cout << "     - " << numAirlines << " airlines;" << endl;
    cout << "     - " << countriesSet.size() << " reachable countries;" << endl;
    cout << "     - " << citiesSet.size() << " reachable cities." << endl;
}           //Com O(n)

/*
void printGlobalFlights(const FlightManagement& flightManagement){
    Graph<string> graph = flightManagement.getGraph();
    vector<Vertex<string>*> nodes = graph.getVertexSet();
    int numFlights = 0;

    for (Vertex<string> *node: nodes) {
        numFlights += node->getAdj().size();
    }

    cout << "--------------------------------------------------\n";
    cout << "The global number of available flights is " << numFlights << '.' << endl;
}
*/

//CHECK - O(n)
void printNumFlights_outAirport(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Enter the airport code [XXX]:";
    string airportCode;
    cin >> airportCode;
    airportCode = upperCase(airportCode);

    Graph<string> graph = flightManagement.getGraph();
    Vertex<string>* airport_ = graph.findVertex(airportCode);

    if (airport_ != NULL) {
        unordered_map<string, Airport*> mapa = flightManagement.getAirportMap();
        Airport* airport = mapa[airportCode];

        unordered_set<string> uniqueAirlines;
        for (const Edge<string>& edge : airport_->getAdj()) {
            uniqueAirlines.insert(edge.getAirline());
        }

        cout << "--------------------------------------------------\n";
        cout << "The number of flights involving the airport " << airport->getCode() << " (" << airport->getName() << ") is " << airport_->getAdj().size() + airport_->getIndegree() << ":" << endl;

        if (airport_->getAdj().size() == 1) {
            cout << "   - There is 1 flight leaving the airport;" << endl;
        } else {
            cout << "   - There are " << airport_->getAdj().size() << " flights leaving the airport;" << endl;
        }

        if (airport_->getIndegree() == 1) {
            cout << "   - There is 1 flight arriving the airport." << endl;
        } else {
            cout << "   - There are " << airport_->getIndegree() << " flights arriving in the airport." << endl;
        }

        cout << "Those flights are from " << uniqueAirlines.size() << " different airlines." << endl;

        return;
    }
    cout << "--------------------------------------------------\n";
    cout << "Airport not found! Please try again." << endl;
}

//CHECK - O(n^2) -> Dá para melhorar?
void printNumFlights_perCity(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Enter the city name:";
    string cityName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, cityName);
    cityName = upperCase(cityName);

    int numFlightsToCity = 0;
    int numFlightsOutCity = 0;

    Graph<string> graph = flightManagement.getGraph();
    unordered_map<string, Airport*> airports = flightManagement.getAirportMap();
    vector<string> airportsOfCity;

    //Primeiro confere quais os aeroportos da cidade
    for (pair<const string, Airport*> airport : airports){
        if(airport.second->getCity() == cityName){
            airportsOfCity.push_back(airport.first);
        }
    }

    if (airportsOfCity.empty()) {
        cout << "--------------------------------------------------\n";
        cout << "City not found! Please, try again." << endl;
        return;
    }


    unordered_set<string> uniqueAirlines;

    //Depois confere quantos voos saem e chegam desses aeroportos
    for (const string& airportCode : airportsOfCity){

        Vertex<string>* vertex = graph.findVertex(airportCode);
        if (vertex != NULL) {
            numFlightsOutCity += vertex->getAdj().size();
            numFlightsToCity += vertex->getIndegree();

            for (Edge<string> edge : vertex->getAdj()) {
                uniqueAirlines.insert(edge.getAirline());
            }
        }
    }


    cout << "--------------------------------------------------\n";
    cout << "The number of flights involving the city of " << cityName << " is " << (numFlightsToCity + numFlightsOutCity) << ':' << endl;

    if (numFlightsOutCity == 1) {
        cout << "   - There is 1 flight leaving the city;" << endl;
    } else {
        cout << "   - There are " << numFlightsOutCity << " flights leaving the city;" << endl;
    }

    if (numFlightsToCity == 1) {
        cout << "   - There is 1 flight arriving the city." << endl;
    } else {
        cout << "   - There are " << numFlightsToCity << " flights arriving in the city." << endl;
    }
    cout << "Those flights are from " << uniqueAirlines.size() << " different airlines." << endl;
}

//CHECK - O(1)
void printNumFlights_perAirline(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Enter the airline's code [XXX]:";
    string airlineCode;
    cin >> airlineCode;
    airlineCode = upperCase(airlineCode);

    unordered_map<string, Airline*> airlineMap = flightManagement.getAirlineMap();
    auto it = airlineMap.find(airlineCode);

    cout << "--------------------------------------------------\n";
    if (it != airlineMap.end()) {
        cout << "The number of flights operated by " << airlineMap[airlineCode]->getName() << " (" << airlineCode << ")" << " is " << airlineMap[airlineCode]->getFlights() << '.' << endl;
    } else {
        cout << "Airline not found. Please try again." << endl;
    }
}


//O(NlogN)
void printNumCountries_perAirport(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Enter the airport's code [XXX]:";
    string airportCode;
    cin >> airportCode;
    airportCode = upperCase(airportCode);

    Graph<string> graph = flightManagement.getGraph();
    unordered_set<string> airports;

    Vertex<string>* vertex = graph.findVertex(airportCode);
    if (vertex != NULL) {
        for (const Edge<string>& edge : vertex->getAdj()) {
            airports.insert(edge.getDest()->getInfo());
        }
    } else {
        cout << "Airport not found! Please, try again." << endl;
        return;
    }

    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    set<string> countries;
    for (const string& destinationAirport : airports){
        Airport* airport = allAirports[destinationAirport];
        countries.insert(airport->getCountry());
    }


    int numCountries = countries.size();
    cout << "--------------------------------------------------\n";
    if (numCountries == 1) {
        cout << "The airport " << airportCode << " is connected to " << numCountries << " different country." << endl;
    } else {
        cout << "The airport " << airportCode << " is connected to " << numCountries << " different countries." << endl;
    }
    cout << "Do you want to consult which countries are available? [Y/N]";
    char answer;
    cout << "Option:";
    cin >> answer;
    if (answer == 'Y' || answer == 'y'){
        cout << "--------------------------------------------------\n";
        for (const string& destination : countries){
            cout << destination << endl;
        }
    }
}

//O(n^2)
void printNumCountries_perCity(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Enter the name of the city:";
    string cityName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, cityName);
    cityName = upperCase(cityName);

    Graph<string> graph = flightManagement.getGraph();
    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    vector<string> airportsOfCity;

    for (pair<const string, Airport*> element : allAirports) {
        if(element.second->getCity() == cityName){
            airportsOfCity.push_back(element.first);
        }
    }

    if (airportsOfCity.empty()) {
        cout << "City not found! Please, try again." << endl;
        return;
    }

    unordered_set<string> airportsDestination;
    for (const string& airport : airportsOfCity) {

        Vertex<string>* airport_ = graph.findVertex(airport);
        if (airport_) {
            for (const Edge<string>& edge : airport_->getAdj()){
                airportsDestination.insert(edge.getDest()->getInfo());
            }
        }
    }

    set<string> countries;
    for (const string& destinationAirport : airportsDestination){
        Airport* airport = allAirports[destinationAirport];
        countries.insert(airport->getCountry());
    }

    int numCountries = countries.size();
    cout << "--------------------------------------------------\n";
    if (numCountries == 1) {
        cout << "The city " << cityName << " is connected to " << numCountries << " different country." << endl;
    } else {
        cout << "The city " << cityName << " is connected to " << numCountries << " different countries." << endl;
    }

    cout << "Do you want to consult which countries are available? [Y/N]" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y') {
        cout << "--------------------------------------------------\n";
        for (const string& destination : countries) {
            cout << destination << endl;
        }
    }
}

//O(NlogN)
void printNumAirports_perAirport(const FlightManagement& flightManagement){
    cout << "Enter the airport's code [XXX]:";
    string airportCode;
    cin >> airportCode;
    airportCode = upperCase(airportCode);

    Graph<string> graph = flightManagement.getGraph();
    unordered_set<string> airports;

    Vertex<string>* airport = graph.findVertex(airportCode);
    if (airport != NULL) {
        for (const Edge<string>& edge : airport->getAdj()) {
            string destinationAirportCode = edge.getDest()->getInfo();
            airports.insert(destinationAirportCode);
        }
    } else {
        cout << "Airport not found!. Please, try again." << endl;
        return;
    }


    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    set<string> airportsDest;
    for (const string& destinationAirport : airports){
        Airport* airport_ = allAirports[destinationAirport];
        airportsDest.insert(airport_->getName());
    }

    int numAirports = airportsDest.size();
    cout << "--------------------------------------------------\n";
    if (numAirports == 1) {
        cout << "The airport " << airportCode << " is connected to " << numAirports << " different airport." << endl;
    } else {
        cout << "The airport " << airportCode << " is connected to " << numAirports << " different airports." << endl;
    }
    cout << "Do you want to consult which airports are available? [Y/N]" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y'){
        cout << "--------------------------------------------------\n";
        for (const string& destination : airportsDest){
            cout << destination << endl;
        }
    }
}

//O(NlogN)
void printNumCities_perAirport(const FlightManagement& flightManagement){
    cout << "Enter the airport's code [XXX]:";
    string airportCode;
    cin >> airportCode;
    airportCode = upperCase(airportCode);

    Graph<string> graph = flightManagement.getGraph();
    unordered_set<string> airports;

    Vertex<string>* airport = graph.findVertex(airportCode);
    if (airport != NULL) {
        for (const Edge<string>& edge : airport->getAdj()) {
            string destinationAirportCode = edge.getDest()->getInfo();
            airports.insert(destinationAirportCode);
        }
    } else {
        cout << "Airport not found!. Please, try again." << endl;
        return;
    }

    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    set<string> citiesDest;
    for (const string& destinationAirport : airports){
        Airport* airport_ = allAirports[destinationAirport];
        citiesDest.insert(airport_->getCity());
    }

    int numCities = citiesDest.size();
    cout << "--------------------------------------------------\n";
    if (numCities == 1) {
        cout << "The airport " << airportCode << " is connected to " << numCities << " different airport." << endl;
    } else {
        cout << "The airport " << airportCode << " is connected to " << numCities << " different airports." << endl;
    }

    cout << " Do you want to consult which cities are available? [Y/N]" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y'){
        cout << "--------------------------------------------------\n";
        for (const string& destination : citiesDest){
            cout << destination << endl;
        }
    }
}



vector<string> reachableDest(const FlightManagement& flightManagement, const string& sourceAirportCode, int maxStops){
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
    s->setDistance(0);
    unvisited.push(s);
    s->setVisited(true);
    while(!unvisited.empty()){
        Vertex<string>* v = unvisited.front();
        unvisited.pop();
        for (const Edge<string> &neighbor : v->getAdj()){
            Vertex<string>* w = neighbor.getDest();
            if(!w->isVisited()){
                w->setDistance(v->getDistance()+1);
                unvisited.push(w);
                w->setVisited(true);}
        }
        if (v->getDistance() <= maxStops)
            reachableDest.push_back(v->getInfo());
    }

    return reachableDest;
}

//O(NlogN)
void printStatisticWithStops(const FlightManagement& flightManagement) {
    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();

    cout << "--------------------------------------------------\n";
    cout << "Enter the source airport's code [XXX]:";
    string sourceAirportCode;
    cin >> sourceAirportCode;
    sourceAirportCode = upperCase(sourceAirportCode);

    unordered_map<string, Airport *>::iterator it;
    it = allAirports.find(sourceAirportCode);
    if (it == allAirports.end()) {
        cout << "Airport not found! Please, try again." << endl;
        return;
    }

    cout << "Enter the maximum number of layovers:";
    string maxStops_;
    cin >> maxStops_; cout << endl;
    for (char c : maxStops_) {
        if (!isdigit(c)) {
            cout << "--------------------------------------------------" << endl;
            cout << "Invalid input! Please, try again." << endl;
            return;
        }
    }
    int maxStops = stoi(maxStops_);

    vector<string> reachable = reachableDest(flightManagement, sourceAirportCode, maxStops);

    set<string> citiesDest;
    set<string> countriesDest;
    set<Airport*, airportComparator> airportSet;

    for (const string& destinationAirport : reachable) {
        Airport* airport = allAirports[destinationAirport];
        airportSet.insert(airport);
        citiesDest.insert(airport->getCity());
        countriesDest.insert(airport->getCountry());
    }


    cout << "--------------------------------------------------" << endl;
    cout << "From " << sourceAirportCode << " (" << (*it).second->getCity() << ")" << ", with " << maxStops << " layovers, you can reach:" << endl;
    cout << "     - " << reachable.size() - 1 << " airports;" << endl;
    cout << "     - " << citiesDest.size() << " cities;" << endl;
    cout << "     - " << countriesDest.size() << " countries." << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Do you want to consult any of the results?" << endl;
    cout << "1. Only airports" << endl;
    cout << "2. Only cities" << endl;
    cout << "3. Only countries" << endl;
    cout << "4. Countries, cities and airports" << endl;
    cout << "0. None of them" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Option:";
    char option = '0';
    cin >> option;
    switch (option) {
        case '0':
            return;
        case '1':
            printAirport(airportSet, false);
            break;
        case '2':
            printList(citiesDest, true);
            break;
        case '3':
            printList(countriesDest, false);
            break;
        case '4':
            printAirport(airportSet, true);
            break;
        default:
            cout << "--------------------------------------------------" << endl;
            cout << "Invalid option! Please, try again." << endl;
            return;
    }

}

void printAirport(const set<Airport *, airportComparator>& set, bool b) {
    /*
    cout << "--------------------------------------------------" << endl;
    cout << "How many airports do you want to see? Maximum of " << set.size() << " airports." << endl;
    string value;
    while (true) {
        cout << "Number of airports:";
        cin >> value;
        if (isNumber(value)) {
            break;
        } else {
            cout << "Invalid input! Please, try again." << endl;
            cout << "--------------------------------------------------" << endl;
        }
    }
    int val = stoi(value);
     */
    cout << "--------------------------------------------------" << endl;
    if (b) {
        cout << "Code   Country                     City                      Name" << endl;
        for (Airport* airport : set) {
            cout << left << setw(6) << airport->getCode() << " ";
            cout << left << setw(27) << airport->getCountry() << " ";
            cout << left << setw(25) << airport->getCity() << " ";
            cout << left << setw(35) << airport->getName() << "\n";
            //val--;
            //if (val == 0) {
            //    break;
            //}
        }
    } else {
        cout << "Code   Name" << endl;
        for (Airport *airport: set) {
            cout << left << setw(6) << airport->getCode() << " ";
            cout << left << setw(35) << airport->getName() << "\n";
            //val--;
            //if (val == 0) {
            //    break;
            //}
        }
    }
}

void printList(const set<string>& set, bool b) {
    /*
    cout << "--------------------------------------------------" << endl;
    cout << "How many cities/countries do you want to see? Maximum of " << set.size() << " cities/countries." << endl;
    string value;
    while (true) {
        cout << "Number of cities/countries:";
        cin >> value;
        if (isNumber(value)) {
            break;
        } else {
            cout << "Invalid input! Please, try again." << endl;
            cout << "--------------------------------------------------" << endl;
        }
    }
    int val = stoi(value);
     */
    cout << "--------------------------------------------------" << endl;
    if (b) {
        cout << "City" << endl;
    } else {
        cout << "Country" << endl;
    }
    for (const string& str : set) {
        cout << str << "\n";
        //val--;
        //if (val == 0) {
        //    break;
        //}
    }
}



//TODO
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


//CHECK -> Pensar em deixar + bonito
//O(n)
void printAirportsGreatestCapability(const FlightManagement& flightManagement){
    cout << "--------------------------------------------------\n";
    cout << "Enter the number of airports to be seen (Maximum of " << flightManagement.getAirportMap().size() << " airports):";
    int k;
    cin >> k;
    cout << "--------------------------------------------------\n";

    Graph<string> graph = flightManagement.getGraph();
    set<pair<int, string>, greater<>> totalFlights;

    for (Vertex<string>* specificNode : graph.getVertexSet()){
        totalFlights.insert(make_pair(specificNode->getIndegree() + specificNode->getAdj().size(), specificNode->getInfo()));
    }


    unordered_map<string, Airport *> airports = flightManagement.getAirportMap();
    cout << "Top " << k << " airports by traffic capacity:" << endl;
    int i = 0;
    for (const auto& airport : totalFlights) {
        if (i >= k) {
            break;
        }
        cout << i+1 << ". " << airport.second << " - " << airport.first << " flights" << endl;
        i++;
    }
}


//308?
//O(n^2)
void printEssentialAirports(const FlightManagement& flightManagement){
    Graph<string> graph = flightManagement.getGraph();
    unordered_set<string> essentialAirports;

    int i = 0;
    for (auto element : graph.getVertexSet()){
        element->setVisited(false);
        element->setProcessing(false);
        element->setNum(i);
    }
    i++;

    for (auto element : graph.getVertexSet()){
        if (element->getNum() == 0){
            dfs_art(graph, element, essentialAirports, i);
        }
    }

    unordered_map<string, Airport*> allAirports = flightManagement.getAirportMap();
    cout << "There are " << essentialAirports.size() <<  " essential airports to the network's circulation capability: " << endl;
    cout << "Code   Country                     City                      Name" << endl;

    set<Airport*, airportComparator> airportSet;
    for (const string& element : essentialAirports){
        airportSet.insert(allAirports[element]);
    }

    for (Airport* airport : airportSet) {
        cout << left << setw(6) << airport->getCode() << " ";
        cout << left << setw(27) << airport->getCountry() << " ";
        cout << left << setw(25) << airport->getCity() << " ";
        cout << left << setw(35) << airport->getName() << "\n";
    }
}

void dfs_art(const Graph<string>& g, Vertex<string> *v, unordered_set<string> &l, int &i){
    v->setProcessing(true);
    v->setNum(i);
    v->setLow(i);
    i++;
    int children = 0;
    for (const Edge<string>& edge : v->getAdj()){
        if(edge.getDest()->getNum() == 0){
            children++;
            dfs_art(g, edge.getDest(), l, i);
            v->setLow(min(edge.getDest()->getLow(), v->getLow()));
            if(v != g.getVertexSet().at(0) && edge.getDest()->getLow() >= v->getNum()) {
                l.insert(v->getInfo());
            }
        } else if(edge.getDest()->isProcessing()){
            v->setLow(min(edge.getDest()->getNum(), v->getLow()));
        }

    }

    v->setProcessing(false);
    if(v == g.getVertexSet().at(0) && children > 1){
        l.insert(v->getInfo());
    }
}



string upperCase(const string& str) {
    string s;
    for (char c : str) {
        s += toupper(c);
    }
    return s;
}

bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}