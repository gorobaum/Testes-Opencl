#include <stdio.h>
#include "opcl.h"

int main() {
  unsigned int num_platforms, num_devices;

  printf("Iniciando a Camada de Plataforma do OpenCL...\n");
  if ( ( num_platforms =  opencl_create_platform(1)  ) <= 0 ) {
      printf("Erro na criação da camada de plataforma!\n");
      return -1; 
  }
  else printf("Num Plataformas = %d\n", num_platforms);
  printf("\n");
  
  printf("Iniciando a Busca por Devices...\n");
  if ( ( num_devices = opencl_get_devices_id(CL_DEVICE_TYPE_GPU) ) <= 0 ) {
    printf("Erro na busca por devices!\n");
    return -1;
  }
  else printf("Num devices = %d\n", num_devices);
  printf("\n");

  printf("Iniciando a criação do contexto...\n");
  if ( opencl_create_context() <= 0 ) {
    printf("Erro na criação do contexto!\n");
    return -1;
  }
  else printf("Contexto criado com sucesso!\n");
  printf("\n");

  printf("Iniciando a criação da fila de comandos...\n");
  if ( opencl_create_queue() <= 0 ) {
    printf("Erro na criação da fila de comandos\n");
    return -1;
  }
  else printf("Fila de comandos criado com sucesso!\n");
  printf("\n");

  printf("Iniciando a criação do programa...\n");
  if ( opencl_create_program("matrixmulti.cl") <= 0 ) {
    printf("Erro na criação do programa\n");
    return -1;
  }
  else printf("Programa criado com sucesso!\n");
  printf("\n");

  return 0;
}
