#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //An emtpy vector of vectors. The space between 2 > sign is encessary
    vector <vector<int>> v2d;
   
    typedef vector<vector<int> > IntMatrix;
    IntMatrix m;

    vector<int> v2(5, 99);
  
    //Now create a vector of 3 elements. 
    vector<vector<int> > v2d2(3, v2);
    
    //print out the elements
    for(int i = 0; i < v2d2.size(); i++)  {
        for(int j = 0; j < v2d2[i].size(); j++) 
            cout << v2d2[i][j] << " ";
        cout << endl;
    }
     
    return 0;
}
