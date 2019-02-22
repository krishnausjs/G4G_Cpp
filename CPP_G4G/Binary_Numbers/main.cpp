#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int max = 0;
    int count = 0;
    
    while(n > 0)  {
        if(n%2 > 0) 
        {
            ++count;
        } else {
            count = 0;
        }
        
        if(max <= count) 
        {
             max = count;
        }
        n=n/2;
    }
    cout << max << endl;
    return 0;
}
