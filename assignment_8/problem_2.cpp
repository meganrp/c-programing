#include <fstream>
#include "vehicle.h"


Vehicle NewVehicle() {
    string year, make, model, color, license; 
    cout << "Enter vehicle year: ";
    cin >> year; 
    cout << "Enter vehicle make: "; 
    cin >> make; 
    cout << "Enter vehicle model: "; 
    cin >> model; 
    cout << "Enter vehicle color: "; 
    cin >> color; 
    cout << "Enter vehicle license plate: "; 
    cin >> license; 

    string csvData = year + "," + make + "," + model + "," + color + "," + license; 
    Vehicle car = Vehicle(csvData);

    return car;
}

void PrintVehicles(vector<Vehicle> cars) { 

    for (Vehicle v : cars) {
        cout << v << endl;
    }
}

void PrintVehiclesCSV(vector<Vehicle> cars) {
    
    for (Vehicle v : cars) {
        string csvData = v.toCSV(); 
        cout << csvData << endl; 
    }
}

vector<Vehicle> LoadVehicles() {
    vector<Vehicle> carList;

    string filename; 
    cout << "Enter csv filename: "; 
    cin >> filename; 

    ifstream file (filename);
    string line;
    
    if (file.is_open()) {

        while (getline (file, line)) {
            Vehicle tempCar = Vehicle(line); 

            carList.push_back(tempCar);
        }

    } else {
        cout << "Unable to find file.";
    }

    return carList;
}

int main(int argc, char *argv[]) {

    vector<Vehicle> carList = LoadVehicles(); 
    
    // Vehicle car1 = Vehicle("2010,Kia,Sorinto,Grey,123abc");
    // cout << car1 << endl;
    // Vehicle car2 = NewVehicle();
    // Vehicle car3 = Vehicle("2010,Kia,Sorinto,Grey,123abc");

    // carList.push_back(car1);
    // carList.push_back(car2);
    // carList.push_back(car3);
    
    // if (car1 == car3) {
    //     cout << "Cars are the same" << endl;
    // }
    // else {
    //     cout << "Cars are different" << endl;
    // }

    PrintVehicles(carList);
    PrintVehiclesCSV(carList); 

    // string carThree = car3.toCSV();
    // cout << carThree << endl;
    // cout << car1.getYear() << endl;
    // cout << car1.getMake() << endl;
    // cout << car1.getModel() << endl;
    // cout << car1.getColor() << endl;
    // cout << car1.getLicense() << endl;

    return 0;
}
