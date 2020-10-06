# Problem Description
```
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

# Explanation
```
Two Pointer Method:
-Two pointers are used one points to the first element and other to the last element
- while(front < back)
    Swap elements 
    increase the front pointer
    decrease the back pointer
```

# Code

## C++
```c++
// Method 1: Two Pointer
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j){
            swap(s[i++], s[j--]);
        }
    }
};

// Method 2: 
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            swap(s[i], s[n-1-i]);
        }
    }
};

```

## Python
```py
# Method 1:
class Solution:
    def reverseString(self, s: List[str]) -> None:
        s[:] = s[::-1] # s != s[:]

# Method 2:
class Solution:
    def reverseString(self, s: List[str]) -> None:
        s.reverse()
   
```
