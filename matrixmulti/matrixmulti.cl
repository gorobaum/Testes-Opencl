__kernel void matrixmulti(__global int* a, __global int* b, __global int* c)
{
    unsigned int i = get_global_id(0);
    
    c[i] = a[i]+b[i]; 
}
