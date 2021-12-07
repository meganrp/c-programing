#include <fstream>

#include "binary_tree.h"
#include "btree_vehicle.h"


int main(int argc, char** argv) {

    if (argc != 2) {
        cout << "Missing file name on command line" << endl;
        return 1;
    }

    btree testing = btree();

    string line;
    ifstream myfile (argv[1]);
    vector<vehicle_t> vehicleList; 

    if (myfile.is_open())
    {
        // gets each line from a file
        while (getline (myfile,line))
        {
            // Call Vehicle from CSV
            vehicle_t temp = vehiclesCSV(line); 

            // append to vehicle list
            vehicleList.push_back(temp); 
        }

        myfile.close();

    } else {
        cout << "Unable to open file"; 
    } 

    // insert each vehicle into the binary tree
    for (vehicle_t v: vehicleList) {

        testing.insertVehicle(v);
    }

    // Menu 

    int input = 0; 
    while (input != 3) {
        cout << "1. Traverse Tree" << endl; 
        cout << "2. Search" << endl; 
        cout << "3. Exit" << endl;
        cin >> input; 

        switch (input) {
            case 1: 
                // Call Traverse Tree 
                break; 
            case 2: 
                int yearInput; 
                cout << "Enter year of vehicle: "; 
                cin >> yearInput; 

                vehicle_t *temp; 
                temp = testing.getVehicle(yearInput); 

                if (temp != NULL) {
                    printVehicle(*temp); 
                } else {
                    cout << "Vehicle not found." << endl; 
                }

                break; 

            case 3: 
                cout << "Exiting Program." << endl; 
                break;  
            
            default: 
                cout << "Please enter a valid choice" << endl; 
        }
    }

    return 0;
}