#include <stdio.h>

union {
  float floatNum;
  struct {
    unsigned int mantisa :23;
    unsigned int exponente :8;
    unsigned int signo :1;
  } structNum;
} unionNum;

int main(void) {
  printf("Ingrese el número a convertir a IEE754: ");
  scanf("%f",&unionNum.floatNum);
  
  printf("%d | ", unionNum.structNum.signo);
  
  for (int i = 7; i >= 0; i--) {
    printf("%d", ((unionNum.structNum.exponente >> i) &1));
  }
  printf(" | ");
  for (int i = 22; i >= 0; i--) {
    printf("%d", ((unionNum.structNum.mantisa >> i) &1));
  }
  return 0;
}
