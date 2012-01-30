#include "opcl.h"

cl_context context;
cl_platform_id platform;
cl_kernel kernel;
cl_program program;

int opencl_create_platform() {
  if ( clGetPlatformIDs( 1, &platform, NULL ) == CL_SUCCESS ) return 1;
  else return -1;
}
