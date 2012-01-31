#include <stdio.h>
#include "opcl.h"

#define MAXSTR 512

cl_context context;
cl_platform_id platform;
cl_kernel kernel;
cl_program program;
cl_device_id devices;
unsigned int devices_found;

unsigned int opencl_create_platform(unsigned int num_platforms) {
  char name[MAXSTR];
  unsigned int num_platforms_found;
  
  if ( clGetPlatformIDs( num_platforms, &platform, &num_platforms_found ) == CL_SUCCESS ) {
    /* As duas linhas abaixo são usadas para teste. 
    clGetPlatformInfo( platform, CL_PLATFORM_NAME, MAXSTR, &name, NULL );
    printf("Nome da plataforma %s\n",name); */
    return num_platforms_found;
  }
  else return -1;
}

unsigned int opencl_get_devices_id(cl_device_type device_type, unsigned int num_devices) {
  unsigned int vendor_id;
  
  if ( clGetDeviceIDs( platform, device_type, num_devices, &devices, &devices_found ) 
      == CL_SUCCESS ) 
  {
    /* As duas linhas abaixo são usadas para teste. 
    clGetDeviceInfo( devices, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(unsigned int), &vendor_id, NULL );
    printf("Vendor ID do Device %d\n",vendor_id); */
    return devices_found;
  }
  else return -1;
}

int opencl_create_context() {
  if ( ( context = clCreateContext( NULL, devices_found, &devices, NULL, NULL, NULL ) ) != NULL ) {
      return 1;
  }
  else return -1;
}
