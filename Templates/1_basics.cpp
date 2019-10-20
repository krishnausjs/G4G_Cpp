//C++ program to demonstrate template
#include <iostream>

using namespace std;

template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

int main()
{
    int i = 5, j = 6, k;
    long l = 10, m =5, n;
    k = getMax(i, j);
    n = getMax(l, m);
    cout << k << endl;
    cout << n << endl;
    return 0;
}
