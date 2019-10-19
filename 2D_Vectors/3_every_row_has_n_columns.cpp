//C++ program to create a 2D vector where every row has n columns.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row = 5;
    int column[] = { 5, 4, 3, 2, 1};
    
    vector<vector<int>> vec(row);

    for(int i = 0; i < row; i++) {
        //size of column
        int col;
        col = column[i];
         
        //Declare ith row to size of column
        vec[i] = vector<int> (col);
        for(int j = 0; j < col; j++)
            vec[i][j] = j + 1;
    }
   
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;   
    }
    return 0;
}
