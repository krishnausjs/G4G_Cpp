//C++ program to demonstrate 2D vector where each row is of different size
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector< vector <int> > vect = { {2, 3, 4}, {1, 2}, {4, 5, 6, 7}};
    for(int i = 0; i < vect.size(); i++) {
        for(int j = 0; j < vect[i].size(); j++)
            cout << vect[i][j] << " ";
            cout << endl;
    }
 
    return 0;
}
