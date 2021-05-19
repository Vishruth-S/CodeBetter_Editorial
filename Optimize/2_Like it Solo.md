# Like it Solo
Problem link: [LikeItSolo_codeBetter](https://www.hackerrank.com/contests/temp-1621067388/challenges/algorithm-like-it-solo)    

## Problem statement
Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.  

### Approach 1 - Brute force [TLE]
For each element, iterate through the array and check if it has a duplicate. If not, then this is the single number, return it.
```cpp
int findSingleNum(vector<int>& nums, int n) 
{
    bool duplicate = false;
    for(int i=0; i<n; i++)
    {
        duplicate = false;
        for(int j=0; j<n; j++)
        {
            if(nums[i]==nums[j] and i!=j)
                duplicate = true;
        }
        if(!duplicate)
            return nums[i];
    }
    return -1;
}
```
*Time complexity: O(n²)*   
*Space complexity: O(1)*   


### Approach 2 - Sort
When the numbers are sorted, all pairs automatically become adjacent.   
Iterate through the array and check adjacent values, if a non-equal adjacent pair is found, then that is the single number.  
```cpp
int findSingleNum(vector<int>& nums, int n) 
{
    if(n<=1)  // for corner case when only 1 element in array
        return nums[0];

    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i+=2)
    {
        if(nums[i]!=nums[i+1])
            return nums[i];
    }
    return -1;
}
```
*Time complexity: O(nlogn)*       
*Space complexity: O(1)*    

### Approach 3 - Hash Table
A hash table can be used to store the frequency of each element efficiently. Then iterate through this hash table and return the number having frequency 1
```cpp
int findSingleNum(vector<int>& nums, int n) 
{
    unordered_map<int,int> counts;
    for(auto i:nums)
        counts[i]++;
        
    for(auto i:counts)
        if(i.second == 1)
            return i.first;
            
    return -1;
}
```
*Time complexity: O(n)*         
*Space complexity: O(n)*   


### Approach 4 - Using Math
Consider the following example `[a,a,b,b,c]`. Here `c` is the single number. To find `c`, we can use the following formula   
`2 ∗ (a+b+c) − (a+a+b+b+c) = c`    
or more generally,
`2 * sum(set(nums)) - sum(nums)`     

```cpp
int findSingleNum(vector<int>& nums, int n) 
{
  set<int> nums_set(nums.begin(), nums.end());
  int set_sum = 0, total_sum = 0;
  for(auto i:nums_set)
      set_sum += i;
  for(auto i:nums)
      total_sum += i;
  
  return 2*set_sum - total_sum;
}
```
*Time complexity: O(n)*            
*Space complexity: O(n)*    

### Approach 5 - Bit Manipulation
Concept behind this approach:   
- If we take XOR of zero and some bit, it will return that bit
  * a ⊕ 0 = a
- If we take XOR of two same bits, it will return 0
  * a ⊕ a = 0
- a ⊕ b ⊕ a = (a ⊕ a) ⊕ b = 0 ⊕ b = b   
So we can XOR all bits together and this will give the unique number.
```cpp
int findSingleNum(vector<int>& nums, int n) 
{
   int x = 0;
   for (int i=0;i<n;i++) 
      x ^= nums[i];
   return x;
}
```
*Time complexity: O(n)*        
*Space complexity: O(1)*   

