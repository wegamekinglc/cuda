#include <cuda_runtime.h>
#include "cublas_v2.h"
#include <iostream>

#define IDX2C(i,j,ld) (((j)*(ld))+(i))

int main(int argc, char **argv)
{
    float* A = new float[4];
    float* x = new float[2];
    float* y = new float[2];

    for (int i=0; i<2; ++i)
    {   x[i] = static_cast<float>(i + 1.0);
        for (int j=0; j<=i; ++j)
            A[IDX2C(i,j,2)] = static_cast<float>(i + j + 1.0);
    }

    cublasHandle_t handle;
    cudaError_t cudastat;
    cublasStatus_t stat;
    float* d_A = 0;  //device matrix
    float* d_x = 0;  //device vector
    float* d_y = 0;  //device result

    cudastat = cudaMalloc((void**)&d_A, 4 * sizeof(float));
    cudastat = cudaMalloc((void**)&d_x, 2 * sizeof(float));
    cudastat = cudaMalloc((void**)&d_y, 2 * sizeof(float));

    float alf = 1.0f;
    float beta = 0.f;

    cudaMemcpy(d_A, A, sizeof(float) * 4, cudaMemcpyHostToDevice);
    cudaMemcpy(d_x, x, sizeof(float) * 2, cudaMemcpyHostToDevice);

    float z = 0.f;
    stat = cublasCreate(&handle);
    stat = cublasSsymv(handle, CUBLAS_FILL_MODE_LOWER, 2, &alf, d_A, 2, d_x, 1, &beta, d_y, 1);
    stat = cublasSdot(handle, 2, d_y, 1, d_x, 1, &z);

    cudaMemcpy(y, d_y, sizeof(float) * 2, cudaMemcpyDeviceToHost);

    for(int i=0; i!=2; ++i)
        std::cout << " " << y[i] <<std::endl;
    std::cout << z << std::endl;
    delete [] A;
    delete [] x;
    delete [] y;
    cudaFree(d_A);
    cudaFree(d_x);
    cudaFree(d_y);
    return 0;
}

