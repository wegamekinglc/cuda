#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

int main()
{

    const size_t N = 1000;

    vector<int> a(N*N);

    for(size_t i=0; i<N; ++i)
        for(size_t j=0; j<N; ++j)
            a[i*N + j] = i + j;

    vector<int> b(N*N);

#pragma omp parallel
    {
#pragma omp for
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < N; ++j)
                b[i * N + j] = i + j;
    }

    return 0;
}

