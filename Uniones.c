//Este programa muestra cómo se puede representar un número de punto flotante en memoria como una serie de bytes utilizando una unión en C.

#include <stdio.h>

union pf{
  char division[4];
  float numFl;
}numero;

int main(void) {

  float aux;

  printf("Bienvenido\nIngrese el número a convertir:");
  scanf("%f",&aux);
  numero.numFl = aux;
  
  printf("0x");
  for(int i=3;i!=-1;i--) printf("%0.2x",numero.division[i]);
  
  return 0;
}
