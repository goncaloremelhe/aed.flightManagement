#ifndef FLIGHTMANAGEMENT_MENU_H
#define FLIGHTMANAGEMENT_MENU_H

#include <iostream>
#include "FlightManagement.h"


void printStatisticsMenu(const FlightManagement& flightManagement);
void printNumberFlightsMenu (const FlightManagement& flightManagement);
void printCountriesOptionsMenu(const FlightManagement& flightManagement);
void printDestionationOptionMenu(const FlightManagement& flightManagement);

void printGlobalAirports(const FlightManagement& flightManagement);
void printGlobalFlights(const FlightManagement& flightManagement);
void printNumFlights_outAirport(const FlightManagement& flightManagement);
void printNumFlights_perCity(const FlightManagement& flightManagement);
void printNumFlights_perAirline(const FlightManagement& flightManagement);
void printNumCountries_perAirport(const FlightManagement& flightManagement);
void printNumCountries_perCity(const FlightManagement& flightManagement);
void printNumAirports_perAirport(const FlightManagement& flightManagement);
void printNumCities_perAirport(const FlightManagement& flightManagement);

#endif //FLIGHTMANAGEMENT_MENU_H
