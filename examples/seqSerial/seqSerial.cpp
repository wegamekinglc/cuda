#include <iostream>
#include <vector>
using namespace std;



int main()
{
    const int N = 50000;

    vector<int> a(N);

    for(int i=0; i!=N; ++i)
        a[i] = i;

    int sumA = 0;
    for(int i=0; i!=N; ++i)
        sumA += a[i];

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
