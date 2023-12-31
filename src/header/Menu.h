#ifndef FLIGHTMANAGEMENT_MENU_H
#define FLIGHTMANAGEMENT_MENU_H

#include <iostream>
#include "FlightManagement.h"
#include <unordered_set>
#include <set>

struct airportComparator;
struct AirportData;

void printMainMenu();
void printStatisticsMenu(const FlightManagement& flightManagement);
void printNumberFlightsMenu (const FlightManagement& flightManagement);
void printDestinationOptionMenu(const FlightManagement& flightManagement);
void printLayoverMenu(const FlightManagement& flightManagement);
void printDestinationsPrintOption(const FlightManagement& flightManagement, const set<Airport*, airportComparator>& airportSet, const set<string>& citiesDest, const set<string>& countriesDest);
/**
* @brief Prints the best flight's paths for a given input
* @complexity O(n^3)
*/
void printBestFlight(const FlightManagement& flightManagement);
/**
* @brief Adds to the exclusion sets the inputs of the user
* @complexity O(n^2) for countries and cities, O(n) for airports and airlines
*/
void includeConstraint(const FlightManagement& flightManagement, unordered_set<string>& exclude, int mode);
/**
* @brief Constructs the flight's paths
* @complexity O(n^2)
*/
list<list<string>> constructFlights(const string& dest, const unordered_map<string, pair<list<string>, int>>& path);
/**
* @brief Finds flight paths with the given exclusions
* @complexity O(V*(V+E))
*/
set<list<string>> findFlight(const FlightManagement& flightManagement, const unordered_set<string>& sourceLocation, const unordered_set<string>& destLocation, const unordered_set<string>& excludeLocation, const unordered_set<string>& excludeAirline);

/**
* @brief Prints the total number of airports, flights, airlines, reachable cities and reachable countries
* @complexity O(E)
*/
void printGlobalStatistics(const FlightManagement& flightManagement);

/**
* @brief Prints the number of flights involving a chosen airport and from how many different airlines
* @complexity O(V)
*/
void printNumFlights_outAirport(const FlightManagement& flightManagement);
/**
* @brief Prints the number of flights that involve a chosen city
* @complexity O(V)
*/
void printNumFlights_perCity(const FlightManagement& flightManagement);
/**
* @brief Prints the number of flights operated by a chosen airline
* @complexity O(1)
*/
void printNumFlights_perAirline(const FlightManagement& flightManagement);

/**
* @brief Prints the number of different countries that a given airport flies to
* @complexity O(V)
*/
void printNumByAirport(const FlightManagement& flightManagement);
/**
* @brief Prints the number of different countries that a given city flies to
* @complexity O(V+E)
*/
void printNumByCity(const FlightManagement& flightManagement);

/**
* @brief prints the number of reachable destinations from a given airport
* @complexity O(V+E)
*/
void printMaximumDestinations(const FlightManagement& flightManagement);
/**
* @brief prints the number of reachable destinations from a given airport in a maximum number of lay-overs
* @complexity O(V+E)
*/
void printStatisticWithStops(const FlightManagement& flightManagement);
/**
* @brief auxiliary function to calculate the  max number of trips possible from a given airport
* @complexity O(V+E)
*/
int maxPathDistance(const FlightManagement& flightManagement, const string& sourceAirportCode);
/**
* @brief prints the flight trip(s) with the greatest number of stops between the source and destination
* @complexity O(V*(V+E))
*/
void printMaximumTrip(const FlightManagement& flightManagement);
/**
* @brief prints a chosen number of airports sorted by greatest number of incoming flights, outgoing flights, or total flights
* @complexity O(V*log(V))
*/
void printAirportsGreatestCapability(const FlightManagement& flightManagement);
/**
* @brief prints the airports that are essential to the network's circulation capability
* @complexity O(V*(V+E))
*/
void printEssentialAirports(const FlightManagement& flightManagement);
/**
* @brief Finds articulation points in the graph
* @complexity O(V+E)
*/
void dfs_art(const Graph<string>& g, Vertex<string> *v, unordered_set<string> &l, int &i);
/**
* @brief Finds the nearest airport to the chosen location
* @complexity O(V)
*/
unordered_set<string> findNearestAirport(const FlightManagement& flightManagement);
/**
* @brief Finds airports on a chosen radius in haversine distance
* @complexity O(V)
*/
unordered_set<string> findAirportHaversine(const FlightManagement& flightManagement);
/**
* @brief Finds an airport based on airport code
* @complexity O(1)
*/
unordered_set<string> findAirport(const FlightManagement& flightManagement);
/**
* @brief Finds an airport based on a chosen city
* @complexity O(V)
*/
unordered_set<string> findAirportInCity(const FlightManagement& flightManagement);
/**
* @brief Prompts the user to choose the country if the same city name exists in multiple countries
* @complexity O(V)
*/
int multiCityChoice(const unordered_map<string, vector<string>>& options, const string& city);
/**
* @brief Prints the list of Airport's code and name or code, name, country and city
* @complexity O(n) for reachable destinations, O(n*log n) for unreachable destinations
*/
void printAirport(const FlightManagement& flightManagement, set<Airport *, airportComparator> set, bool b, bool reachable);
/**
* @brief Prints the list of cities or countries
* @complexity O(n) for reachable destinations, O(n*log n) for unreachable destinations
*/
void printList(const FlightManagement& flightManagement, set<string> set, bool b, bool reachable);
/**
* @brief Returns the haversine distance between two points
* @complexity O(1)
*/
double haversineDistance(double latA, double lonA, double latB, double lonB);
/**
* @brief Returns true if the string is a float number
* @complexity O(n)
*/
bool isFloat(const string& str);
/**
* @brief Returns true if the string is an integer
* @complexity O(n)
*/
bool isNumber(const string& str);
/**
* @brief Returns the string in the capitalized format
* @complexity O(n)
*/
string capitalizeWords(const string& str);
/**
* @brief Returns the string only in uppercase
* @complexity O(n)
*/
string upperCase(const string& str);

#endif //FLIGHTMANAGEMENT_MENU_H
