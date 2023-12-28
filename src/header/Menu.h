#ifndef FLIGHTMANAGEMENT_MENU_H
#define FLIGHTMANAGEMENT_MENU_H

#include <iostream>
#include "FlightManagement.h"
#include <unordered_set>
#include <set>

struct airportComparator;

void printMainMenu();
void printStatisticsMenu(const FlightManagement& flightManagement);
void printNumberFlightsMenu (const FlightManagement& flightManagement);
void printDestinationOptionMenu(const FlightManagement& flightManagement);
void printLayoverMenu(const FlightManagement& flightManagement);

void printBestFlight(const FlightManagement& flightManagement);

void printGlobalStatistics(const FlightManagement& flightManagement);

void printNumFlights_outAirport(const FlightManagement& flightManagement);
void printNumFlights_perCity(const FlightManagement& flightManagement);
void printNumFlights_perAirline(const FlightManagement& flightManagement);

void printNumByAirport(const FlightManagement& flightManagement);
void printNumByCity(const FlightManagement& flightManagement);

void printStatisticWithStops(const FlightManagement& flightManagement);
void printMaximumTrip(const FlightManagement& flightManagement);

void printAirportsGreatestCapability(const FlightManagement& flightManagement);

void printEssentialAirports(const FlightManagement& flightManagement);
void dfs_art(const Graph<string>& g, Vertex<string> *v, unordered_set<string> &l, int &i);

void printAirport(const set<Airport *, airportComparator>& set, bool b);
void printList(const set<string>& set, bool b);

unordered_set<string> findAirportHaversine(const FlightManagement& flightManagement);
unordered_set<string> findAirport(const FlightManagement& flightManagement);
unordered_set<string> findAirportInCity(const FlightManagement& flightManagement);
void includeConstraint(const FlightManagement& flightManagement, unordered_set<string>& exclude, int mode);
vector<list<string>> findFlight(const FlightManagement& flightManagement, const unordered_set<string>& sourceLocation, const unordered_set<string>& destLocation, const unordered_set<string>& excludeLocation, const unordered_set<string>& excludeAirline);
double haversineDistance(double latA, double lonA, double latB, double lonB);
bool isFloat(const string& str);
string upperCase(const string& str);
string capitalizeWords(const string& str);

#endif //FLIGHTMANAGEMENT_MENU_H
