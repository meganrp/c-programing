#include <stdio.h>
#include <string.h>



void PrintBits(size_t const size, unsigned char readByte, int numSequence) {
    unsigned char *byte =  &readByte;
    unsigned char displayBit; 
    unsigned char bit;
    unsigned char nextBit;
    int seqCounter = 0;
    int output = 0; 

    int j; 

        // Just to display the entire byte
        printf("Binary Number: ");
        for (j = 7; j >= 0; j--) {
        displayBit = (byte[0] >> j) & 1;
        printf("%hhu", displayBit);
        
        }
        puts("");

        printf("Checking pairs\n==============");

        // Accessing bits, accessing index at 7 (Byte[7]) 

                   
        for (j = 7; j >= 0; j--) {

            bit = (byte[0] >> j) & 1;

            nextBit = (byte[0] >> (j-1)) & 1;
            
            // Check if the next byte next to it is also a one 
            if (bit == 1 && nextBit == 1) {
                seqCounter++;

                if (seqCounter == numSequence) {
                    output++; 

                    seqCounter = 0; 
                }
            }

            // Reset sequenceCounter if zero is encountered 
            if (bit == 0) {
                seqCounter = 0; 
            }
           
        }


    printf("\nTotal Counted 1's: %d \n", seqCounter);
    printf("Output: %d \n\n", output);
}



int main() {

    const int ARRAY_SIZE = 128;
    unsigned char buffer; 
    char fileName[ARRAY_SIZE];
    int numSequence = 0;
    FILE *ptr; 

    printf("Enter file name: ");
    fgets(fileName, sizeof(fileName), stdin);

    int len;
    // remove newline from entered string
    len = strlen(fileName);
    if( fileName[len-1] == '\n' )
        fileName[len-1] = 0;

    ptr = fopen(fileName, "rb"); 
    // Check if file exists 
    if (ptr == NULL) {
        printf("File %s does not exist!", fileName);
        return 0;
    }

    printf("Enter number: ");
    scanf("%d", &numSequence); 

    int counter = 0;

    while(feof(ptr) == 0) {
        fread(&buffer, sizeof(buffer), 1, ptr); 
        PrintBits(sizeof(buffer), buffer, numSequence);
        counter++;
    }

    if (feof(ptr)) {
        printf("\nReached end of file!\n");
        printf("Counted %d bytes of data!\n\n", counter);
    }

    fclose(ptr); 

    return 0;
}