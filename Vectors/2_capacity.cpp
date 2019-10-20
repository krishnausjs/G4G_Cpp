//C++ program that prints the capacity as it grows
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    for(int i = 0; i < 50; i++)
    {
        cout << "Size  = " << v.size() << "and capacity = " << v.capacity() << endl;
        v.push_back(i);
    }
    return 0;
}
