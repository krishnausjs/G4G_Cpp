/*
 * Program: First element occuring k times in an array.
 * 
 * Problem : Given an array of n integers. The task is to find the first element that occurs k number of times.
 * If no element occurs k times then print -1. The distribution of integer element could be in any range.
 * 
 * Input: {1, 7, 4, 3, 4, 8, 7}
 *      k = 2
 * Output : 7
 * 
 * Both 7 and 4 occur two times. But 7 is the first that occurs 2 times.
 * 
 * 
 * Time Complexity 
 * ===============
 * Simple method   :  It has a time complexity of O(n2).
 * 
 * Efficient Approach : Use unodered_map for hashing as range is not known.
 * 
 * Approach:
 * =========
 * 1. Traverse the array elements from left to right.
 * 2. While traversing increment their count in the hash table.
 * 3. Again traverse the array from left to right and check which element has a count equal to k. Print the element and stop.
 * 4. If no element has count equal to k , print -1.
 * 
 * Time complexity in this case is O(n)
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int firstElement(int arr[], int n, int k)
{
    //Unordered_map to count
    //Occurences of each element
    unordered_map <int, int> count_map;
    for(int i=0; i<n; i++)
        count_map[arr[i]]++;
        
    for(int i=0; i<n; i++)
        if(count_map[arr[i]] == k)  //If count of element is k, then it is the required first element.
            return arr[i];
            
    //no element occurs k times
    return -1;
}

int main()
{
    int arr[] = {1, 7, 4, 3, 4, 8, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout << firstElement(arr, n, k)<<endl;
    return 0;
}