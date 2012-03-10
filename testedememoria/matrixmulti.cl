__kernel void matrixmulti(__global int* a, __global int* b)
{
    unsigned int row = get_global_id(0);
    unsigned int column = get_global_id(1);
    column = 1000*column;
    b[row+column] = a[row+column];
}
