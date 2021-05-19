# Fibonacci 
Problem link: [Fibonacci_codeBetter](https://www.hackerrank.com/contests/temp-1621067388/challenges/algorithm-fibonacci)     

## Problem statement
Given a number n, print n-th Fibonacci Number


### Approach 1 - Brute force Recursion. [TLE]  
A simple method that is a direct recursive implementation mathematical recurrence relation F(n) = F(n-1) + F(n-2), F(0) = 0, F(1) = 1.  
```cpp
int fib(int n)
{
  if(n<=1) 
    return n;
  return (fib(n-1) + fib(n-2))%1000000007;
}
```
*Time complexity: O(2^n)*    
*Space complexity: O(n)*

### Approach 2 - Using Dynamic Programming - Memoization
We can observe that the previous implementation does a lot of repeated work. The idea here is to store the fibonacci numbers calculated so far and use them to calculate the next.  
```cpp
vector<int> FibNums(n+1, -1);
int fib(int n)
{
  if(n<=1) 
    return n;
  if (FibNums[n] != -1)
      return FibNums[n];
  return FibNums[n] = (fib(n-1) + fib(n-2))%1000000007;
}
```
*Time complexity: O(n)*     
*Space complexity: O(n)*

### Approach 3 - Using Dynamic Programming - Tabulation
This is the iterative implementation of approach 2. 
```cpp
int fib(int n)
{
    vector<int> fibNums(n+1, -1);
    fibNums[0] = 0;
    fibNums[1] = 1;
    for (int i = 2; i <= n; i++)
        fibNums[i] = (fibNums[i - 1] + fibNums[i - 2])%1000000007;

    return fibNums[n];
}
```
*Time complexity: O(n)*     
*Space complexity: O(n)*

### Approach 4 - Using Dynamic Programming - Space optimized approach 3
In the previous approach, you can observe that only 2 of the previous values are needed at any time. Hence we don't need an entire array, instead just 2 variables.  
```cpp
int fib(int n)
{
    int n1, n2, n3;
    n1 = 0;
    n2 = 1;
    for (int i = 2; i <= n; i++)
    {
        n3 = (n1 + n2)%1000000007;
        n1 = n2;
        n2 = n3;
    }
    return n3;
}
```
*Time complexity: O(n)*     
*Space complexity: O(1)*

### Approach 5 - Using Math
On solving the recurrence relation F(n) = F(n-1) + F(n-2), F(0) = 0, F(1) = 1, we get the formula for the general term as     
`F(n) = {[(√5 + 1)/2] ^ n} / √5` 
```cpp
int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return (round(pow(phi, n) / sqrt(5)));
}
```
*Time complexity: O(1)*     
*Space complexity: O(1)*   
Note: This appraoch only works for values < 75. For larger values, `pow` overflows integer size, so custom `pow` function must be implemented taking `modulus 1000000007` of value at each step.



