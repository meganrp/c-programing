#include <stdio.h>

void swap(int *swap1, int *swap2);

int main() {

    int input1, input2;
    int *swap1, *swap2;

    printf(">  ");
    scanf("%d %d", &input1, &input2);

    swap1 = &input1;
    swap2 = &input2;


    printf("%d\n%d\n", input1, input2);

    swap(swap1, swap2);

    printf("%d\n%d\n", input1, input2);

    return 0;
}

//accepts two pointers and swaps the values within
void swap(int *swap1, int *swap2) {
    
    int save;
    save = *swap1;

    *swap1 = *swap2;
    *swap2 = save;

}
