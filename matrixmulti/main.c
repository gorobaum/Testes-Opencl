#include <stdio.h>
#include "opcl.h"

int main() {
  printf("Iniciando a Camada de Plataforma do OpenCL!");
  if ( opencl_create_platform() < 0 ) return -1; 
  printf("SUCCEEEESSSOOOO\n");
  return 0;
}
