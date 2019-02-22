#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//#define USE_UNORDERED_SET

#ifdef USE_UNORDERED_SET
int has_array_two_candidates(int arr[], int n, int sum)
{
        unordered_set<int> s;
        int temp;
        bool ret = false;
        
        for(int i =1; i < n; i++)
        {
            temp = sum - arr[i];
            if(temp >=0 && (s.find(temp) != s.end()))
            {
                cout << "Pair is " << arr[i] << " " << temp << endl;
                ret = true;
                break;
            }
            s.insert(arr[i]);
        }
        return ret;
}
#else
int has_array_two_candidates(int arr[], int n, int sum)
{
        int i,j;
        i = 0;
        j = n - 1;
        int ret = 0;
        
        sort(arr,arr+n);
        
        while(i < j)
        {
            if(arr[i] + arr[j] == sum)
            {
                ret = 1;
                cout << "Pair " << arr[i] << '+' << arr[j] << '='<< sum <<endl;
                break;
            }
            else if( arr[i] + arr[j] < sum ) 
            {   
                i++;        
            }   
            else
            {
                j--;
            }
        }
        return ret;
}
    
#endif


/* Driver program to test above function */
int main() 
{ 
    int A[] = {1, 4, 45, 6, 10, -8}; 
    int n = 16; 
    int arr_size = sizeof(A) / sizeof(A[0]); 
      
    // Function calling 
    if (has_array_two_candidates(A, arr_size, n)) 
        cout << "Array has two elements with given sum" << endl; 
    else
        cout << "Array doesn't have two elements with given sum" << endl;; 
          
    return 0; 
} 