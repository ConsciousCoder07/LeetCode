
# Problem Description
```
Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.
We repeatedly make duplicate removals on S until we no longer can.
Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
```

# Explanation
```
1. Add element only if stack is empty or last element is not same as current one.
2. If first condition is not true which means last element is same as the current then pop last element of the stack.
This makes the stack duplicate free
```

# Code

## C++
```c++
// Method 1: Considering append condtion first

class Solution {
public:
    string removeDuplicates(string S) {
        
        string temp;
        for(auto ch : S)
        {   // append condition
            if(temp.empty() or temp.back()!=ch)
                temp.push_back(ch);
            else
                temp.pop_back();
        }
        return temp;
    }
};

// Method 2: Considering pop condition first
class Solution {
public:
    string removeDuplicates(string S) {
        
        string temp;
        for(auto ch : S)
        {
            if(!temp.empty() && temp.back() == ch)
                temp.pop_back();
            else
                temp.push_back(ch);
        }
        return temp;
    }
};
```

## Python
```py
# Method 1: Considering append condition

class Solution:
    def removeDuplicates(self, S: str) -> str:
        
        strList = []
        for ch in S:
            # append conditon
            if not strList or strList[-1] != ch:
                strList.append(ch)
            else:
                strList.pop()
        return ''.join(strList)
            
# Method 2: Considering pop condition

class Solution:
    def removeDuplicates(self, S: str) -> str:
        
        strList = []
        for ch in S:
            if strList and strList[-1] == ch:
                strList.pop()
            else:
                strList.append(ch)
        return ''.join(strList)
```

## Java
```java

```