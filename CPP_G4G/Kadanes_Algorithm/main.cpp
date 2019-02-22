#include <iostream>
#include <climits>
#if 0
int maxSubArraySum(int arr[], int n)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    
    for(int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        
        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;   
}
#else
int maxSubArraySum(int arr[], int size)
{
    int i, max_sum, max_global_sum;

    max_sum = max_global_sum = arr[0];

    for (i = 1; i < size; ++i) {
        //maxSum = arr[i] > arr[i] + maxSum ? arr[i] : arr[i] + maxSum;
        //maxGlobalSum = maxSum > maxGlobalSum ? maxSum : maxGlobalSum;
        if(arr[i] > arr[i] + max_sum)
            max_sum = arr[i];
        else
            max_sum = arr[i] + max_sum;
        
        if(max_sum > max_global_sum)
            max_global_sum = max_sum;
    }

    return max_global_sum;
}
#endif

/*Driver program to test maxSubArraySum*/
int main() 
{ 
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum = maxSubArraySum(a, n); 
    std::cout << "Maximum contiguous sum is " << max_sum; 
    return 0; 
} 