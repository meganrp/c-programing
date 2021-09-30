#include <stdio.h>

int main() {

  int input;
  printf("Enter an integer: ");
  scanf("%d", &input);

  // Iterator and storage
  int k = 0, i, factors[30];

  for (i = 1; i <= input; i++) {
    if (input % i == 0) {
      factors[k] = i;
      k++;
    }
  }

  // If length of factors is 4 or less then print all.
  if (k <= 4) {
    for (i = 0; i < k; i++) {
      printf("%9d\n", factors[i]);
    }

  } else {
    printf("%9d\n", factors[1]);
    printf("%9d\n", factors[2]);
    printf("%9d\n", factors[k-3]);
    printf("%9d\n", factors[k-2]);
  }

  // Check for prime
  if (k == 2) {
    printf("%d is a prime!\n", input);
  }

  return 0;
}
