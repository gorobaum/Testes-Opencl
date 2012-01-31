#include "CL/opencl.h"


unsigned int opencl_create_platform( unsigned int num_platforms);
unsigned int opencl_get_devices_id(cl_device_type device_type, unsigned int num_devices);
int opencl_create_context();
void opencl_create_kernel();
void opencl_create_buffer();
void opencl_write_buffer();
void opencl_read_buffer();

