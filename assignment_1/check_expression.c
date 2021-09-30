#include <stdio.h>

void check(int factors[]);

int main(void){

  char input[5];

  //Get expression
  printf(">  ");

  int i;
  for(i=0; i<5; i++){
    scanf("%c", &input[i]);
  }

  //Convert to ascii
  int convert[5] = {input[0], input[1], input[2], input[3], input[4]};

  check(convert);

  return 0;
}
  //Check validity of expression

void check(int convert[]){

int num_floor = 48;
int num_ceiling = 57;

  if(convert[0] >= num_floor && convert[0] <= num_ceiling){
    //check opperator ascii values
    if(convert[1] == 42 || convert[1] == 43 || convert[1] == 45 || convert[1] == 47){
      if(convert[2] >= num_floor && convert[2] <= num_ceiling){
        if(convert[3]==42 || convert[3]==43 || convert[3]==45 || convert[3]==47){
          if(convert[4] >= num_floor && convert[4] <= num_ceiling){
            printf("Valid Expression\n");
          }
          else{
            printf("Invalid Expression\n");
          }
        }
        else{
          printf("Invalid Expression\n");
        }
      }
      else{
        printf("Invalid Expression\n");
      }
    }
    else{
      printf("Invalid Expression\n");
    }
  }
  else{
    printf("Invalid Expression\n");
  }
}
