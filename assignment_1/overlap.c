#include <stdio.h>

void check_overlap(int cx1_pos, int cx1_neg, int cy1_pos, int cy1_neg, int cx2_pos, int cx2_neg, int cy2_pos, int cy2_neg, int cx1_radius, int cx2_radius);

int main() {

  //Gather input
  int circle_1[3], circle_2[3];
  printf("Enter circle one parameters (x y radius): ");
  scanf("%d %d %d", &circle_1[0], &circle_1[1], &circle_1[2]);
  printf("Enter circle two parameters (x y radius): ");
  scanf("%d %d %d", &circle_2[0], &circle_2[1], &circle_2[2]);

  int cx1_pos, cy1_pos, cx1_neg, cy1_neg;
  int cx2_pos, cy2_pos, cx2_neg, cy2_neg;
  int cx1_radius = circle_1[2];
  int cx2_radius = circle_2[2];

  //Create usable variables
  cx1_pos = circle_1[0] + cx1_radius;
  cx1_neg = circle_1[0] - cx1_radius;
  cy1_pos = circle_1[1] + cx1_radius;
  cy1_neg = circle_1[1] - cx1_radius;

  cx2_pos = circle_2[0] + cx2_radius;
  cx2_neg = circle_2[0] - cx2_radius;
  cy2_pos = circle_2[1] + cx2_radius;
  cy2_neg = circle_2[1] - cx2_radius;


  check_overlap(cx1_pos, cx1_neg, cy1_pos, cy1_neg, cx2_pos, cx2_neg, cy2_pos, cy2_neg, cx1_radius, cx2_radius);

   return 0;
}

void check_overlap(int cx1_pos, int cx1_neg, int cy1_pos, int cy1_neg, int cx2_pos, int cx2_neg, int cy2_pos, int cy2_neg, int cx1_radius, int cx2_radius){

  //Find larger circle
  if (cx1_radius > cx2_radius) {
    if ((cx1_pos >= cx2_pos) && (cy1_pos >= cy2_pos) && (cx1_neg <= cx2_neg) && (cy1_neg <= cy2_neg)) {
      printf("Overlap Detected!");
    }
    else {
      printf("No overlap!");
    }
  }

  if (cx1_radius < cx2_radius) {
    if((cx1_pos <= cx2_pos) && (cy1_pos <= cy2_pos) && (cx1_neg >= cx2_neg) && (cy1_neg >= cy2_neg)) {
      printf("Overlap detected!");
    }
    else {
      printf("No overlap!");
    }
  }

  if (cx1_radius == cx2_radius) {
    if((cx1_pos == cx2_pos) && (cy1_pos == cy2_pos) && (cx1_neg == cx2_neg) && (cy1_neg == cy2_neg)) {
      printf("Overlap detected!");
    }
    else {
      printf("No overlap!");
    }
  }
}
