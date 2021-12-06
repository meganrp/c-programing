#include "binary_tree.h"
#include "btree_vehicle.h"


int main(int argc, char** argv) {

    if (argc != 2) {
        cout << "Missing file name on command line" << endl;
        return 1;
    }

    //btree testing = btree();

    vehicle_t test = vehiclesCSV("2010,Kia,Sorinto,Grey,123abc");
    printVehicle(test);

    
   
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