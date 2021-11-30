#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

class Vehicle {

    public:
        Vehicle();
        Vehicle(string data);
        Vehicle(string make, string model);

        string toCSV();
        
        int getYear();
        void setYear(int year);

        string getMake();
        void setMake(string make);

        string getModel();
        void setModel(string model);

        string getColor();
        void setColor(string color);

        string getLicense();
        void setLicense(string license);

        friend ostream& operator<<(ostream& os, const Vehicle& v); 
        
        bool operator==(Vehicle& v1) {
            if (this->getYear() == v1.getYear() && this->getMake() == v1.getMake() && 
                this->getModel() == v1.getModel() && this->getColor() == v1.getColor() &&
                this->getLicense() == v1.getLicense()) {

                cout << "Idintical vehicle, WTF are you doing??" << endl;

                return true;

            }
            
            return false;
            
        }

        
    private:
        int year;
        string make;
        string model;
        string color;
        string license;

};

Vehicle::Vehicle() {
    year = 2021;
    make = "None";
    model = "None";
    color = "None";
    license = "None";
}

ostream& operator<<(ostream& os, const Vehicle& v) {
             
    os << v.year << " " << v.make << " " << v.model << " " << v.color << " " << v.license;

    return os;
}




Vehicle::Vehicle(string data) {

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
                year = stoi(result.at(i));
                break;

            case 1:
                make = result.at(i);
                break;

            case 2:
                model = result.at(i);
                break;

            case 3:
                color = result.at(i);
                break;
                
            case 4:
                license = result.at(i);
                break;

            default:
                cout << "Default option, you should not be here :/" << endl;
                break;
                
        }
    }
}

Vehicle::Vehicle(string make, string model) {
    this->make = make;
    this->model = model;
}

string Vehicle::toCSV() {
    string yearString = to_string(year);
    string data = yearString + "," + make + "," + model + "," + color + "," + license;
    
    return data;
}

int Vehicle::getYear() {
    return year;
}

void Vehicle::setYear(int year) {
    this->year = year;
}

string Vehicle::getMake() {
    return make;
}

void Vehicle::setMake(string make) {
    this->make = make;
}

string Vehicle::getModel() {
    return model;
}

void Vehicle::setModel(string model) {
    this->model = model;
}

string Vehicle::getColor() {
    return color;
}

void Vehicle::setColor(string color) {
    this->color = color;
}

string Vehicle::getLicense() {
    return license;
}

void Vehicle::setLicense(string license) {
    this->license = license;
}

#endif