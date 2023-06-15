#include <stdio.h>
#define LIM 30

char *p1, *p2;
char compare (char *, char *);

int main(void) {

  char string1[LIM];
  char string2[LIM];
  
  printf("Bienvenido\n");
  printf("Ingrese la primera cadena de texto:\n");
  scanf("%s", string1);
  printf("Ingrese la segunda cadena de texto:\n");
  scanf("%s", string2);
  if (compare(string1,string2)){
    printf("Las cadenas son iguales");
  } else printf("Las cadenas no son iguales");
  
  return 0;
}

char compare (char *p1, char *p2) {
  while (*p1 != '\0' || *p2 != '\0'){
    if (*(p1++) != *(p2++)) return 0;
  }
  return 1;
}
