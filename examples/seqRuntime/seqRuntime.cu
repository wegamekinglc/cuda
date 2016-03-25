#include <iostream>
using namespace std;

#include <thrust/reduce.h>
#include <thrust/sequence.h>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

__global__ void fillKernel(int *a,int n)
{
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if(tid < n) a[tid] = tid;
}

void fill(int * d_a, int n)
{
    int nThreadPerBlock = 512;
    int nBlocks = n / nThreadPerBlock + ((n%nThreadPerBlock)?1:0);
    fillKernel <<< nBlocks, nThreadPerBlock >>> (d_a, n);
}

int main()
{
    const int N = 50000;
    thrust::device_vector<int> a(N);

    fill(thrust::raw_pointer_cast(&a[0]), N);

    int sumA = thrust::reduce(a.begin(), a.end(), 0);

    int sumCheck = 0;
    for(int i=0; i!=N; ++i)
        sumCheck += i;

    if(sumA == sumCheck)
        cout << "Test Succeeded!" << endl;
    else {
        cerr << "Test FAILED!" << endl;
        return 1;
    }

    return 0;
}