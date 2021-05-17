# Find Unique Paths

## Problem Statement
You are at the top left corner of a m x n grid. Your objective is to reach the finish line located at the bottom right corner.   
You may only move down or right at any point in time. How many possible unique paths are there?

### Approach 1 - Brute force Recursion [TLE]   
```cpp
int findUniquePaths(int m, int n)
{
	  if ( m == 1 and n == 1) 
      return 1;
  	if ( m <= 0 or n<= 0) 
      return 0;

  	return findUniquePaths(m - 1, n) + findUniquePaths(m , n - 1); 
}
```
*Time complexity: O(2^n)*   
*Space complexity: O(n)*

### Approach 2 - Dynamic Programming - Memoization 
```cpp
vector<vector<int>> dp(m, vector<int>(n, 1));
int findUniquePaths(int m, int n)
{
}
```
*Time complexity: O(2^n)*   
*Space complexity: O(n)*
