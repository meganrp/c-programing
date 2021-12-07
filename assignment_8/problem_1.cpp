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


    for (vehicle_t v: vehicleList) {
        testing.insertVehicle(v);
    }

    vehicle_t tempBinaryVehicle = NewVehicle(); 
    tempBinaryVehicle = testing.getVehicle(2015);
    printVehicle(tempBinaryVehicle);


   
    // cout << "What is the make: ";
    // cin >> test.make;
    // cout << "You have entered: " << test.make << endl;


    // testing.insert(123);
    // testing.insert(456);
    // testing.insert(789);

    // node *temp;
    // temp = testing.search(654);
    
    // if (temp == NULL) {
    //     cout << "Does not exist in data" << endl;
    // }

    // else {
    //     cout << temp->key_value << endl;
    // }

    return 0;
}