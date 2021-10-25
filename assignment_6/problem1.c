#include "problem1.h"

#define SIZE 100

void enqueue(); 
void dequeue(); 
void show(); 

int inp_arr[SIZE]; 
int Rear = -1; 
int Front = -1;
int Count = 0;

vehicle_t NewVehicle() {
    vehicle_t newVehicle; 
    
    newVehicle.make = (char*) malloc((SIZE + 1) * sizeof(char)); 
    newVehicle.model = (char*) malloc((SIZE + 1) * sizeof(char)); 
    newVehicle.color = (char*) malloc((SIZE + 1) * sizeof(char)); 
    newVehicle.license = (char*) malloc((SIZE + 1) * sizeof(char)); 


    printf("Enter year: "); 
    scanf("%d", &newVehicle.year); 

    printf("Enter make: "); 
    scanf("%s", newVehicle.make);

    printf("Enter model: "); 
    scanf("%s", newVehicle.model);

    printf("Enter color: "); 
    scanf("%s", newVehicle.color);

    printf("Enter license: "); 
    scanf("%s", newVehicle.license);

    printf("Year is %d\n", newVehicle.year);
    printf("Make is %s\n", newVehicle.make);
    printf("Model is %s\n", newVehicle.model);
    printf("Color is %s\n", newVehicle.color);
    printf("License is %s\n", newVehicle.license);

    return newVehicle; 
} 

void EnqueueVehicle(vehicle_t* vehicleQueue) {
    if (Rear == SIZE - 1)
        printf("Overflow \n");
    else {
        vehicle_t temp = NewVehicle(); 
        if (Front == -1)
            Front = 0; 
        Rear = Rear + 1; 
        vehicleQueue[Rear] = temp; 
        printf("Successfully added vehicle to queue. \n");
        Count++; 
    }
}

void DequeueVehicle(vehicle_t* vehicleQueue) {
     if (Front == -1 || Front > Rear) {
        printf("Underflow \n"); 
        return;
    } 
    else {
        Front = Front + 1; 
        Count--;
    }
}


void NextVehicle(vehicle_t* vehicleQueue) {
    if (Front == -1 || Front > Rear) {
        printf("No more vehicles to repair! \n");
        return;  
    } 
    else {
        printf("Next up: %d %s %s %s LIC#%s \n", vehicleQueue[Front].year, vehicleQueue[Front].make, vehicleQueue[Front].model, vehicleQueue[Front].color, vehicleQueue[Front].license); 
        
        // Sub Menu 
        int ch; 

        while (1) {
            printf("1. Start Repair \n"); 
            printf("2. Go Back \n"); 
            printf("> "); 
            scanf("%d", &ch); 

            switch (ch) {
                case 1: 
                    DequeueVehicle(vehicleQueue); 
                    return; 

                case 2: 
                    return; 
                
                default: 
                    printf("Invalid Input\n");
                    break;
            }

        }
        
    }
}



void ViewVehicleQueue(vehicle_t* vehicleQueue) {
    if (Front > Rear)
        printf("No vehicles in queue. \n");
    else {
        int num = 0;
        for (int i = Front; i <= Rear; i++) {
            printf("%d. %d %s %s %s LIC#%s \n", (num + 1), vehicleQueue[i].year, vehicleQueue[i].make, vehicleQueue[i].model, vehicleQueue[i].color, vehicleQueue[i].license); 
            num++;
        }

        printf("\n");
    }
}


int main() {
    vehicle_t *vehicle_arr = (vehicle_t*) malloc((SIZE + 1) * sizeof(vehicle_t));  

    int ch; 
    while (1) {

        printf("1. Add Vehicle\n"); 
        printf("2. View Next Vehicle\n"); 
        printf("3. View Current Queue\n"); 
        printf("4. Quit\n"); 
        printf("> ");
        scanf("%d", &ch); 

        switch (ch) {
            case 1: 
                EnqueueVehicle(vehicle_arr); 
                break; 

            case 2: 
                NextVehicle(vehicle_arr); 
                break; 
            
            case 3: 
                ViewVehicleQueue(vehicle_arr); 
                break; 
            
            case 4: 
                exit(0);
            
            default: 
                printf("Incorrect choice \n"); 

        } 
    }

    return 0; 
}


void enqueue() {
    int insert_item; 

    if (Rear == SIZE - 1)
        printf("Overflow \n");
    else {
        if (Front == -1)
            Front = 0; 
        printf("Element to be inserted in the Queue\n : "); 
        scanf("%d", &insert_item); 
        Rear = Rear + 1; 
        inp_arr[Rear] = insert_item; 
    }
}

void dequeue() {
    if (Front == -1 || Front > Rear) {
        printf("Underflow \n"); 
        return ;
    } 
    else {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]); 
        Front = Front + 1; 
    }
}

void show() {

    if (Front == -1)
        printf("Empty Queue \n");
    else {
        printf("Queue: \n"); 
        
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]); 
        printf("\n");
    }
}