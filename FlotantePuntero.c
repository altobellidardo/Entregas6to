#include <stdio.h>

int main(void) {
  
  float floatNum;
  char *P = (char *) &floatNum;
  floatNum = 12.25;

  printf("0x");
  printf("%.2x",P[3]);
  printf("%.2x",P[2]);
  printf("%.2x",P[1]);
  printf("%.2x",P[0]);

  printf("\n0b");
  for (int u=3; u >=0; u--) {
    for (int i=7; i >=0; i--) printf("%d",((P[u] >> i) & 1));
  }
  
  return 0;
}
