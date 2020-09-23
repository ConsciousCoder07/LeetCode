# Problem Description
```
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.

Given N, calculate F(N).
```

# Explanation
```
Return the nth fibonacci term assuming 0-based index starting from 0
```

# Code

## C++
```c++
class Solution {
public:
    int fib(int N) {
        
        int f = 0, a = 0, b = 1;
        if (N < 2) return N;
        for( int i = 2; i <= N; i++)
        {
            f = a + b;
            a = b; 
            b = f;
        }
        return f;
    }
};
```

## Python
```py
class Solution:
    def fib(self, N: int) -> int:
        fib = [0,1]
        if N == 0:
            return 0;
        elif N == 1:
            return 1
        for i in range(2, N+1):
            fib.append(fib[-1]+fib[-2])
        return fib[-1]
```
