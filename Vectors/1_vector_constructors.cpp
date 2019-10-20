#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //An empty vector
    vector<int> v;
  
    //A vector with 5 elements, each an integer
    vector<int> v1(5);

    //An array with 5 elements, each of which being an empty vector of integers
    vector<int> v1array[5];

    //A vector with 5 elements each having the value 99
    vector<int> v2(5, 99);

    //A vector with the size and value of v2
    vector<int> v3(v2);
 
    //Another way to create a vector with the size and value of v2
    vector<int> v4(v1.begin(), v2.end());

    for(int i = 0; i < v1.size(); i++)
        v1[i] = i + 1;

    for(int i = 0; i < v1.size(); i++)
        cout << v1[i] << endl;

    for(int j = 0; j < v3.size(); j++)
        cout << v3[j] << endl;
    
     return 0;
}


