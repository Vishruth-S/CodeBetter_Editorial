# Maximum sum subarray  
## Problem statement  
Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

### Aprroach 1 - Brute force [TLE]
Calculate sum of all subarrays and take the maximum.
```cpp
int largestSubarraySum(vector<int> arr, int n)
{
  int max_sum  = INT_MIN;
  for(int i=0;i<n;i++)
  {
      int curr_sum=0;
      for(int j=i;j<n;j++)
      {
          curr_sum+=arr[j];
          max_sum = max(max_sum,curr_sum);
      }
  }
  return max_sum;
}
```
*Time complexity: O(n²)*   
*Space complexity: O(1)*


### Approach 2 - Kadane's Algorithm
Refer: https://en.wikipedia.org/wiki/Maximum_subarray_problem , https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/      
Video explanations: https://www.youtube.com/watch?v=w_KEocd__20 , https://www.youtube.com/watch?v=2MmGzdiKR9Y
```cpp
int largestSubarraySum(vector<int> nums, int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        maxi = max(maxi,sum);
        if(sum<0)
            sum = 0;
    }
    return maxi;
}
```
*Time complexity: O(n)*   
*Space complexity: O(1)*
