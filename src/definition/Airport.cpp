#include <utility>

#include "../header/Airport.h"

Airport::Airport(string code, string name, string city, string country, float latitude, float longitude) {
    this->code = std::move(code);
    this->name = std::move(name);
    this->city = std::move(city);
    this->country = std::move(country);
    this->latitude = latitude;
    this->longitude = longitude;
}

string Airport::getCode() {
    return code;
}

string Airport::getName() {
    return name;
}

string Airport::getCity() {
    return city;
}

string Airport::getCountry() {
    return country;
}

float Airport::getLatitude() const {
    return latitude;
}

float Airport::getLongitude() const {
    return longitude;
}

bool Airport::operator==(const Airport &airport) const {
    return (code == airport.code &&
            name == airport.name &&
            city == airport.city &&
            country == airport.country &&
            latitude == airport.latitude &&
            longitude == airport.longitude);
}

