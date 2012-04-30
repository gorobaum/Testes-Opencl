#include <stdio.h>
#include "opcl.h"

#define MAXSTR 512
#define MS 500
#define NANO 1e9 

/* Objetos do Open CL */
cl_platform_id platform;
cl_context context;
cl_device_id* devices;
cl_command_queue queue;
cl_kernel kernel;
cl_program program;
cl_event event;
cl_mem opclMatrixA, opclMatrixB, opclMatrixC;

/* Informações sobre os devices */
unsigned int devices_found;
unsigned int device_used = 0;

unsigned int opencl_create_platform(unsigned int num_platforms) {
  char name[MAXSTR];
  int num_platforms_found;
  
  clGetPlatformIDs( 0, NULL, &num_platforms_found);
  printf("Num Plat == %d\n\n", num_platforms_found); 
  if ( clGetPlatformIDs( num_platforms, &platform, &num_platforms_found ) == CL_SUCCESS ) {
    /* As duas linhas abaixo são usadas para teste. */
    clGetPlatformInfo( platform, CL_PLATFORM_NAME, MAXSTR, &name, NULL );
    printf("Nome da plataforma %s\n",name);  
    return num_platforms_found;
  }
  else return -1;
}

unsigned int opencl_get_devices_id(cl_device_type device_type) {
  unsigned int vendor_id;
  
  /* Achando o número de devices na máquina */
  clGetDeviceIDs(platform, device_type, 0, NULL, &devices_found);
  devices = malloc(devices_found*(sizeof(cl_device_id)));
  
  if ( clGetDeviceIDs( platform, device_type, devices_found, devices, NULL) 
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
  if ( ( context = clCreateContext( 0, 1, devices, NULL, NULL, NULL ) ) != NULL ) {
      return 1;
  }
  else return -1;
}

int opencl_create_queue() {
  if ( ( queue = clCreateCommandQueue(context, devices[device_used], CL_QUEUE_PROFILING_ENABLE, NULL ) ) != NULL ) {
    return 1;
  }
  else return -1;
}

/* Funções auxiliares para a criação do program */
char* loadProgramFromSource(char* program_path, int *size) {
  char* program_string;
  FILE* prog;

  prog = fopen(program_path, "r");
  fseek(prog, 0, SEEK_END);
  *size = ftell(prog);
  fseek(prog, 0, SEEK_SET);

  program_string = malloc((*size+1)*sizeof(char));
  *size = fread(program_string, 1, *size, prog);
  fclose(prog);
  program_string[*size] = '\0';

  return program_string;
}

int buildProgram() {
    int err;
    char *build_log;
		size_t ret_val_size;
		
    err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
		if ( err != CL_SUCCESS ) {
  		clGetProgramBuildInfo(program, devices[device_used], CL_PROGRAM_BUILD_LOG, 0, NULL, &ret_val_size);

	  	build_log = malloc((ret_val_size+1)*sizeof(char));
	  	clGetProgramBuildInfo(program, devices[device_used], CL_PROGRAM_BUILD_LOG, ret_val_size, build_log, NULL);
  		build_log[ret_val_size] = '\0';

	  	printf("BUILD LOG: \n %s", build_log);
      printf("program built\n");
      return -1;
    }
    else return 1;
}
/* Fim das funções auxiliares para a criação do program */

void profile_event (cl_event* profiler) {
  cl_ulong start, finish;
  size_t nano_clocks;
    
  clGetDeviceInfo(devices[0], CL_DEVICE_PROFILING_TIMER_RESOLUTION, sizeof(size_t), &nano_clocks, NULL);
  printf("Nano_clock = %ld\n", nano_clocks);
  clWaitForEvents(1, &event);
  if (clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_START, (size_t)sizeof(cl_ulong), &start, NULL) != CL_SUCCESS) printf("Erro!\n");
  if (clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_END, (size_t)sizeof(cl_ulong), &finish, NULL) != CL_SUCCESS) printf("Erro!\n");
  printf("Tempo Total = %f\n", (finish-start)*NANO*nano_clocks);
}

int opencl_create_program(char* program_path) {
  char* program_source;
  int size;
  size_t prog_size;
  cl_int err;
  
  program_source = loadProgramFromSource(program_path, &size);
  prog_size = (size_t)size;
  program = clCreateProgramWithSource(context, 1, (const char**)&program_source, &prog_size, &err);
  if ( err != CL_SUCCESS ) printf("Erro = %d\n",err);
  return buildProgram();
}

int opencl_create_kernel(char* kernel_name) {
  cl_int err;
  kernel = clCreateKernel( program, (const char*) kernel_name, &err);
  if ( err == CL_SUCCESS ) return 1;
  else return -1;
}

void prepare_kernel() {
  double MatrixA[MS][MS], MatrixB[MS][MS];
  int i, j, size;
  cl_mem matrix_size;

  for ( i = 0; i < MS; i++ ) {
    for ( j = 0; j < MS; j++ ) {
      MatrixA[i][j] = i+j;
      MatrixB[i][j] = 2.0;
    }
  }
  size = MS;

  /* Criação dos buffers que o OpenCL vai usar. */
  opclMatrixA = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(double)*MS*MS, MatrixA, NULL);
  opclMatrixB = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(double)*MS*MS, MatrixB, NULL);
  opclMatrixC = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(double)*MS*MS, NULL, NULL);
  matrix_size = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(int), (&size), NULL);
  
  clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&opclMatrixA);
  clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&opclMatrixB);
  clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&opclMatrixC);
  clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&matrix_size);

  clFinish(queue);
}

int opencl_run_kernel() {
  size_t work_dim[2] = { MS, MS };
  double Mc[MS][MS];
  int i, j;

  prepare_kernel();
  clEnqueueNDRangeKernel(queue, kernel, 2, NULL, work_dim, NULL, 0, NULL, &event);
  clReleaseEvent(event);
  clFinish(queue);

  if( clEnqueueReadBuffer(queue, opclMatrixC, CL_TRUE, 0, sizeof(double)*MS*MS, &Mc, 0, NULL, &event) 
      == CL_INVALID_VALUE ) printf("ERRROROOO\n");
  profile_event(&event);
  clReleaseEvent(event);
  /*for( i = 0; i < MS; i++ ) {
    for( j = 0; j< MS; j++ ) {
      printf("%d  ", Mc[i][j]);
    }
    printf("\n");
  }*/

  return 1;
}

