#ifndef FLIGHTMANAGEMENT_AIRPORT_H
#define FLIGHTMANAGEMENT_AIRPORT_H

#include <string>
using namespace std;

class Airport {
private:
    string code, name, city, country;
    float latitude;
    float longitude;
public:
    Airport(string code, string name, string city, string country, float latitude, float longitude);
    string getCode();
    string getName();
    string getCity();
    string getCountry();
    float getLatitude() const;
    float getLongitude() const;
    bool operator == (const Airport &airport) const;
    bool operator< (const Airport &airport) const;
};

#endif //FLIGHTMANAGEMENT_AIRPORT_H
