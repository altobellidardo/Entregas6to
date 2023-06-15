#include <stdio.h>

#define LIM 30

typedef struct alumno {
  char nombre[LIM];
  char apellido[LIM];
  int anio;
  int edad;
  float promedio;
}
alumno;

void menu(void);

void crearalumno(alumno*, int);
void mostraralumnos(alumno*, int);
void veralumno(alumno*, int);
void editaralumno(alumno*, int);

char toUpper(char);
void limpiarBuffer(void);

int main(void) {

  printf("Bienvenido a base de datos de alumnos\n");
  
  menu();

  printf("Gracias por usar el software");
  
  return 0;
}

void menu(void){

  alumno alumnos[LIM]; //vector de hasta 30 alumnos
  int cantAlumnos = 0; //indice de alumno a crear
  int selAlumno; //alumno seleccionado
  char opc;  //opcion del menu 

  do {
    printf("-------------\n");
    printf("-A para ingresar un nuevo alumno\n-B para ver un alumno\n-C para editar un alumno\n-D para salir\n");
    scanf("%c", &opc);
    limpiarBuffer();
    if ((opc=='a')||(opc=='A')){
      crearalumno(&alumnos[0], cantAlumnos);
      cantAlumnos++;
    }
    else if ((opc=='b')||(opc=='B')){
      if (cantAlumnos){
        mostraralumnos(&alumnos[0], cantAlumnos);
        printf("Que alumno deseas ver: ");
        scanf("%d",&selAlumno);
        limpiarBuffer();
        if (selAlumno < cantAlumnos) veralumno(&alumnos[0], selAlumno);
        else printf("Ingrese un alumno de la lista\n");
      } else printf("Primero ingese un alumno\n");
    }
    else if ((opc=='c')||(opc=='C')){
      if (cantAlumnos){
        mostraralumnos(&alumnos[0], cantAlumnos);
        printf("Que alumno deseas editar: ");
        scanf("%d",&selAlumno);
        limpiarBuffer();
        if (selAlumno < cantAlumnos) editaralumno(&alumnos[0], selAlumno);
        else printf("Ingrese un alumno de la lista\n");
      } else printf("Primero ingese un alumno\n");
    }
    else if ((opc!='d')&&(opc!='D')) printf("Opcion invalida\n");
  } while ( (opc!='d')&&(opc!='D') );
}

void mostraralumnos(alumno *pAlumno, int cantAlumnos){
  for (int i = 0; i < cantAlumnos; i++){
    if(pAlumno[i].nombre[0] != '\0'){
      printf("#%d Nombre: %s %s\n", i, pAlumno[i].nombre, pAlumno[i].apellido);
    }
  }
}

void crearalumno(alumno *pAlumno, int indice) {
  printf("Alumno %d:\n",indice);
  printf("Nombre: ");
  scanf("%s",pAlumno[indice].nombre);
  limpiarBuffer();
  pAlumno[indice].nombre[0] = toUpper(pAlumno[indice].nombre[0]);
  printf("Apellido: ");
  scanf("%s",pAlumno[indice].apellido);
  limpiarBuffer();
  pAlumno[indice].apellido[0] = toUpper(pAlumno[indice].apellido[0]);
  printf("Año: ");
  scanf("%d", &pAlumno[indice].anio);
  limpiarBuffer();
  printf("Edad: ");
  scanf("%d", &pAlumno[indice].edad);
  limpiarBuffer();
  printf("Promedio: ");
  scanf("%f", &pAlumno[indice].promedio);
  limpiarBuffer();
}

void veralumno(alumno *pAlumno,int selAlumno) {
  if (selAlumno >= 0 && selAlumno < LIM) {
    if (pAlumno[selAlumno].nombre[0] != '\0') {
      printf("Nombre: %s\n",pAlumno[selAlumno].nombre);
      printf("Apellido: %s\n",pAlumno[selAlumno].apellido);
      printf("Año: %d\n",pAlumno[selAlumno].anio);
      printf("Edad: %d\n",pAlumno[selAlumno].edad);
      printf("Promedio: %.2f\n",pAlumno[selAlumno].promedio);
    } else printf("El alumno no existe.\n");
  } else printf("El Indice del alumno no es valido.\n");
}

void editaralumno(alumno *pAlumno, int indice) {
  static alumno alumnox;
  static const char punto[LIM] = ".";
  
  if (pAlumno[indice].nombre[0] == '\0') {
    printf("El alumno no existe.\n");
    return;
  }
  
  printf("Para mantener valor presiona .\n");
  printf("Nombre: %s\n",pAlumno[indice].nombre);
  scanf("%s",alumnox.nombre);
  limpiarBuffer();
  if (alumnox.nombre[0] != punto[0]) {
    alumnox.nombre[0] = toUpper(alumnox.nombre[0]);
    int i = 0;
    while ((pAlumno[indice].nombre[i] = alumnox.nombre[i]) != '\0') i++;
  }
  printf("Apellido: %s\n",pAlumno[indice].apellido);
  scanf("%s",alumnox.apellido);
  limpiarBuffer();
  if (alumnox.apellido[0] != punto[0]) {
    alumnox.apellido[0] = toUpper(alumnox.apellido[0]);
    int i = 0;
    while ((pAlumno[indice].apellido[i] = alumnox.apellido[i]) != '\0') i++;
  }
  printf("Año: %d\n",pAlumno[indice].anio);
  scanf("%d",&alumnox.anio);
  limpiarBuffer();
  if (alumnox.anio != 0) {
    pAlumno[indice].anio = alumnox.anio;
  }
  printf("Edad: %d\n",pAlumno[indice].edad);
  scanf("%d",&alumnox.edad);
  limpiarBuffer();
  if (alumnox.edad != 0){
    pAlumno[indice].edad = alumnox.edad;
  }
  printf("Promedio: %.2f\n",pAlumno[indice].promedio);
  scanf("%f",&alumnox.promedio);
  limpiarBuffer();
  if (alumnox.promedio != 0){
    pAlumno[indice].promedio = alumnox.promedio;
  }
  
}

void limpiarBuffer(void){
  static int c;
  while ((c = getchar()) != '\n') {}
}

char toUpper(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a' + 'A';
  }
  return c;
}
