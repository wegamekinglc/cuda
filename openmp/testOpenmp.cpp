#include <iostream>
#include <vector>
#include <sys/time.h>

using namespace std;

int main()
{

    const size_t N = 50000;

    vector<int> a(N*N);

    struct timeval start, end;

    gettimeofday(&start, NULL);

    for(size_t i=0; i<N; ++i)
        for(size_t j=0; j<N; ++j)
            a[i*N + j] = i + j;

    gettimeofday(&end, NULL);

    cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << endl;

    vector<int> b(N*N);

    gettimeofday(&start, NULL);

#pragma omp parallel
    {
#pragma omp for
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < N; ++j)
                b[i * N + j] = i + j;
    }

    gettimeofday(&end, NULL);

    cout << ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6 << endl;

    return 0;
}

