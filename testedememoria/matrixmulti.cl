#pragma OPENCL EXTENSION cl_khr_fp64 : enable

__kernel void matrixmulti(__global float* a, __global float* b, __global int* rowSize, __global int* columnSize)
{
    unsigned int row = get_global_id(0);
    unsigned int column = get_global_id(1);
	b[row+column*(*rowSize)] = a[row+column*(*rowSize)];
}
