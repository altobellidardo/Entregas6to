#include <stdio.h>
#include <stdlib.h>

typedef struct val{
  int valor;
  struct val *siguiente;
} val_t;

val_t * inicio = NULL;

void crear (void);
void mostrar (void);
void borrar (void);

int main(void) {
  char accion;
  val_t * inicio = NULL;
  do {
    printf("- c crear - l mostrar - s salir\n");
    accion = getchar();
    if (accion=='c') crear();
    if (accion=='l') mostrar();
  } while (accion != 's');
  borrar();
  return 0;
}

void crear (void) {
  val_t * p = malloc(sizeof(val_t));
  printf("Ingrese valor a guardar: ");
  scanf("%d", &p->valor);
  if (inicio == NULL) inicio = p;
  else {
    p -> siguiente = inicio;
    inicio = p;
  }
}

void mostrar (void) {
  val_t * p = inicio;
  while (p != NULL) {
    printf("Valor guardado %d\n", p->valor);
    p = p->siguiente;
  }
}

void borrar (void) {
  val_t *p = inicio, *paux=inicio;
  if (inicio != NULL) {
    paux = inicio -> siguiente;
  }
  
  while (paux != NULL) {
    free(p);
    p = paux;
    paux = p -> siguiente;
  }
}
