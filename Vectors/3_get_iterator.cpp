//C++ program to get the index of an element given an iterator to it
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> v(3);
    v[0] = "apple";
    v[1] = "banana";
    v[2] = "carror";
    
    vector<string>::iterator it = find(v.begin(), v.end(), "apple");
    cout << it->first << endl;
    it = find(v.begin(), v.end(), "carrot");
    cout << "Index of carrot = " << std::distance(v.begin(), it) << endl;
    return 0;
}

