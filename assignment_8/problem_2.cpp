#include "vehicle.h"


int main(int argc, char *argv[]) {
 
    Vehicle car1 = Vehicle("2010,Kia,Sorinto,Grey,123abc");
    cout << car1;
    Vehicle car2 = Vehicle("2011,Ford,Ranger,Blue,456def");
    Vehicle car3 = Vehicle("2010,Kia,Sorinto,Grey,123abc");
    
    if (car1 == car3) {
        cout << "Cars are the same" << endl;
    }
    else {
        cout << "Cars are different" << endl;
    }

    string carThree = car3.toCSV();
    cout << carThree << endl;
    // cout << car1.getYear() << endl;
    // cout << car1.getMake() << endl;
    // cout << car1.getModel() << endl;
    // cout << car1.getColor() << endl;
    // cout << car1.getLicense() << endl;

    return 0;
}
