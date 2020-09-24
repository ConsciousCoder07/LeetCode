# Problem Description
```
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Note:

```

# Explanation
```

```

# Code

## C++
```c++
// Method 1: Brute

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        for(int i=0; i<A.size(); i++)
            A[i] = A[i]*A[i];
        
        sort(A.begin(), A.end());
        
        return A;
    }
};

// Method 2: Two Pointer

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int n = A.size();
        vector<int> temp(n);
        int i = 0, j = n-1, k = n-1;
        while(i<=j)
        {
            if(A[i]*A[i] > A[j]*A[j]){
                temp[k--] = A[i]*A[i];
                i++;
            } else {
                temp[k--] = A[j]*A[j];
                j--;
            }
        }
        
        return temp;
    }
};
```

## Python
```py
# 1. One liner

class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        return sorted([i*i for i in A])

# 2. Using .sort()

class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        a = [i*i for i in A]
        a.sort()
        return a

```

