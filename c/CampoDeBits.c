#include <stdio.h>

typedef struct ColorRGB {
  unsigned int rojo:8;
  unsigned int verde:8;
  unsigned int azul:8;
}
ColorRGB;

int ConvertHEX (ColorRGB);

int main(void) {
  ColorRGB color = {255, 0, 255};
  
  printf("Rojo: %d, Verde: %d, Azul: %d\n", color.rojo, color.verde, color.azul);
  
  color.verde = 128;
  
  printf("Rojo: %d, Verde: %d, Azul: %d\n", color.rojo, color.verde, color.azul);
  
  printf("Color hexadecimal: #%06X\n", ConvertHEX(color));
  
  return 0;
}

int ConvertHEX (ColorRGB color){
  static int hex;
  hex = (color.rojo << 16) + (color.verde << 8) + color.azul;
  return hex;
}
