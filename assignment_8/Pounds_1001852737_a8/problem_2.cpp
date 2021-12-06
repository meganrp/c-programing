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

    vector<Vehicle> carList;
   
    int input;

    while (1) {

        cout << "1-Add vehicle\n2-Load vehicles\n3-Print vehicles\n4-Print vehicles CSV" << endl;
        cin >> input;

        Vehicle tempCar; 
        vector<Vehicle> tempList;

        switch (input) {

            case 1:
                tempCar = NewVehicle();
                carList.push_back(tempCar);
                break;
            
            case 2:
                tempList = LoadVehicles();
                carList.insert(carList.end(), tempList.begin(), tempList.end());
                break;

            case 3:
                PrintVehicles(carList);
                break;

            case 4:
                PrintVehiclesCSV(carList);
                break;

            default:
                cout << "Not an option" << endl;
                return 0;
        }
   
    }
    
    return 0;
}
