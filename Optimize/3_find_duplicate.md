# Find duplicate number
Problem Link: [findDuplicate_codeBetter](https://www.hackerrank.com/contests/temp-1621067388/challenges/algorithm-find-the-impostor)

## Problem statement
Given an array of integers arr containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is one and only one repeated number in arr, return this repeated number.

### Approach 1 - Brute force [TLE]
For each element in the array, scan the rest of the array check if it repeats. If a duplicate is found, then return it.   
```cpp
int findDuplicate(vector<int> arr, int M)
{
    for(int i=0;i<M;i++)
      {
        for(int j=i+1;j<M;j++)
        {
          if(arr[i]==arr[j])
            return arr[j];
        }
      }
      return -1;
}
```
*Time complexity: O(n²)*   
*Space complexity: O(1)*


### Approach 2 - Sort
Once the array is sorted, any duplicates would become adjancent elements. So check if any adjacent pair match and return it.  
```cpp
int findDuplicate(vector<int> arr, int M)
{
    sort(arr.begin(),arr.end());
    for (int i = 1; i < M; i++) {
        if (arr[i] == arr[i-1]) {
            return arr[i];
        }
    }
    return -1;
}
```
*Time complexity: O(nlogn)*   
*Space complexity: O(1)*

### Approach 3 - Hash Table
Insert elements into a hash table and store their frequency. Iterate over this hash table and return the number with frequency > 1.
```cpp
int findDuplicate(vector<int> arr, int M)
{
    vector<long> counts(M);
    for(auto i:arr)
      counts[i]++;
  
    for(int i=1;i<counts.size();i++)
      if(counts[i]>1)
          return i;
  
    return -1;
}
```
*Time complexity: O(n)*   
*Space complexity: O(n)*

### Approach 4 - Using Floyd's Tortoise and Hare (Cycle Detection) Algorithm
The idea is to reduce this problem to the Linked List Cycle detection problem: given a linked list, return the node where the cycle begins.      
Refer: https://leetcode.com/problems/find-the-duplicate-number/solution/     
Video explanations: https://www.youtube.com/watch?v=32Ll35mhWg0, https://www.youtube.com/watch?v=dfIqLxAf-8s     
```cpp
int findDuplicate(vector<int> arr, int M)
{
    int tortoise = arr[0];
    int hare = arr[0];
    do {
      tortoise = arr[tortoise];
      hare = arr[arr[hare]];
    } while (tortoise != hare);

    tortoise = arr[0];
    while (tortoise != hare) {
      tortoise = arr[tortoise];
      hare = arr[hare];
    }

    return hare;
}
```
*Time complexity: O(n)*   
*Space complexity: O(1)*
