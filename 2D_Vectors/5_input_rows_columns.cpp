//C++ program to create a 2D vector of n rows and m columns and input values
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    int m = 4;
    vector<vector<int>> vec(n, vector<int> (m,0));
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++) 
            vec[i][j] = j + i + 1;
    }
  
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
    return 0;
}
