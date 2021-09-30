#include <stdio.h>

char rotateASCII(char character, int value);

int main() {
  char inputChar;
  int valueToRotate;

  printf("> ");
  scanf("%c %d", &inputChar, &valueToRotate);

  printf("%c\n", rotateASCII(inputChar, valueToRotate));

  return 0;
}


char rotateASCII(char character, int value) {
  int rangeFloor = 33;
  int rangeCeiling = 126;

  int characterASCII = (int)character;

  int newCharASCII = characterASCII + value;

  // Check the value is within given range
  if (newCharASCII < rangeFloor) {
    newCharASCII = (newCharASCII - (rangeFloor - 1)) + rangeCeiling;
  }

  if (newCharASCII > rangeCeiling) {
    newCharASCII = (newCharASCII - (rangeCeiling + 1)) + rangeFloor;
  }

  char newChar = (char)newCharASCII;

  return newChar;
}
