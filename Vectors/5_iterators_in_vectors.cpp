#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> g1;
    
    for(int i = 1; i <= 5; i++)
        g1.push_back(i);

    //begin : Returns an iterator pointing to the first element in vector
    //end : Returns an iterator pointing to the theoretical element that follows the last element in the vector
    cout << "Output of begin and end: ";
    for(auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";

    //Returns a constant iterator pointing to the first element in the vector
    //Returns a constant iterator pointing to the theoretical element that follows the last element in the vector
    cout << "\nOutput of cbegin and cend: ";
    for(auto i = g1.cbegin(); i != g1.cend(); ++i)
        cout << *i << " ";

    
    //rbegin() - Return a reverse iterator pointing to the last element in the vector    //It moves from last to first element
    //rend() - Return a reverse iterator pointing to the theoretical element preceding the first element in the vector. 
    cout << "\nOutput of rbegin and rend: ";
    for(auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        cout << *ir << " ";

    //crbegin() - Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves last to first element.
    //crend() - Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector 
    cout << "\nOutput of cbegin and crend: ";
    for(auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        cout << *ir << " ";

    cout << endl;

    return 0;
}
