#include <stdio.h>

int b10_to_b7(int input);

int main() {

    int input;

    // Get integer
   printf("Enter number in base 10: ");
   scanf("%d", &input);

    printf("\n\n%d\n", b10_to_b7(input));
  

   return 0;
}


int b10_to_b7(int input) {
    int base7 = 7, remainder, dividend;
    int counter = 0;
    int numStore[20];
    int storeIndex = 19;

    dividend = input;

    while (dividend <= 0) {
        remainder = (dividend % base7);
        dividend = (dividend / base7);

        numStore[storeIndex] = remainder;

        storeIndex--;
        counter++;
     
    }

    for (int i = 19; i > counter; i--) {
        printf("Reverse order: %d\n", numStore[i]);
    }

    

    printf("Remainder: %d\nDividend: %d\n", remainder, dividend);

    if ((dividend = 0)) {
        printf("Dividend is 0");
    }

    else {
        remainder = (dividend % base7);
        dividend = (dividend / base7);
    }

    input = *numStore;

    return input;

}
