cmake_minimum_required(VERSION 3.26)
project(flightManagement)

set(CMAKE_CXX_STANDARD 17)

add_executable(flightManagement main.cpp
        src/header/FlightManagement.h
        src/definition/FlightManagement.cpp
        src/header/Airline.h
        src/header/Airport.h
        src/definition/Airport.cpp
        src/definition/Airline.cpp
        src/header/Graph.h)
