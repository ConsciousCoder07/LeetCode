# Problem Description
```
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
```

# Explanation
```
Mathematical Approach: 
The digital root (also repeated digital sum) of a natural number in a given number base is the (single digit) value obtained by an iterative process of summing digits, on each iteration using the result from the previous iteration to compute a digit sum. The process continues until a single-digit number is reached.

For base b (decimal case b = 10), the digit root of an integer is:

dr(n) = 0 if n == 0
dr(n) = (b-1) if n != 0 and n % (b-1) == 0
dr(n) = n mod (b-1) if n % (b-1) != 0

or

dr(n) = 1 + (n - 1) % 9
```

# Code

## C++
```c++
// Method 1: Brute
class Solution {
public:

    int addDigits(int num) {
        while(num > 9)
        {   int sum = 0;
            while(num != 0)
            {
                sum = sum + num%10;
                num = num/10;
            }
            num = sum;
        }
        return num;
    }
};

// Method 2: Mathematical Approach
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
```

## Python
```py
# Method 1: Brute
class Solution:
    def addDigits(self, num: int) -> int:
        
        while(num > 9):       
            sum = 0
            while(num > 0):
                sum += num % 10
                num //= 10
            num = sum
            
        return num

# Method 2: Mathematical Approach
class Solution:
    def addDigits(self, num: int) -> int:
        return 0 if num == 0 else 1 + (num - 1) % 9
```
