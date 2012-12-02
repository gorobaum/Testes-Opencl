__kernel void processbound(__global float* MatrixA, __global float* MatrixB, __global float* MatrixC, __global int* N)
{
    unsigned i = get_global_id(0);
    unsigned j = get_global_id(1);
    unsigned k;
    MatrixC[i*(*N)+j] = 0;
    for( k = 0; k < (*N); k++ ) 
    	MatrixC[i*(*N)+j] += MatrixA[i*(*N)+k]*MatrixB[j+k*(*N)];
}
