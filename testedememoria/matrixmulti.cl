__kernel void matrixmulti(__global int* a, __global int* b, __global int* rowSize)
{
    unsigned int row = get_global_id(0);
    unsigned int column = get_global_id(1);
	b[row+column*(*rowSize)] = a[row+column*(*rowSize)];
}
