#ifndef BTREE_VEHICLE_H
#define BTREE_VEHICLE_H

#include <vector>
#include <string>
#include <sstream>

using namespace::std;

struct vehicle_t {
    char *make;
    char *model;
    char *color;
    char *license_plate;
    int year;
};

vehicle_t NewVehicle() {
    int BUFFER = 1024; 
    vehicle_t temp = {};

    temp.make = new char[BUFFER];
    temp.model = new char[BUFFER];
    temp.color = new char[BUFFER]; 
    temp.license_plate = new char[BUFFER];

    return temp;
}

vehicle_t vehiclesCSV(string data) {

    vehicle_t temp = NewVehicle();

    vector<string> result;
    stringstream s_stream(data);

    while(s_stream.good()) {
        string substr;
        getline(s_stream, substr, ',');
        result.push_back(substr);
    }

    for(int i = 0; i < (int)result.size(); i++) {    
        
        switch (i) {
            case 0:
                temp.year = stoi(result.at(i));
                break;

            case 1:
                temp.make = (char*)result.at(i).c_str();
                break;

            case 2:
                temp.model = (char*)result.at(i).c_str();
                break;

            case 3:
                temp.color = (char*)result.at(i).c_str();
                break;
                
            case 4:
                temp.license_plate = (char*)result.at(i).c_str();
                break;

            default:
                cout << "Default option, you should not be here :/" << endl;
                break;
                
        }
    }
    return temp;
}

void printVehicle(vehicle_t vehicle) {
    cout << vehicle.year << "-" << vehicle.make << "-" << vehicle.model << "-" << vehicle.color << "-" << vehicle.license_plate << endl;
}

#endif