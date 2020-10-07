# Problem Description
```
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1.Open brackets must be closed by the same type of brackets.
2.Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
```

# Explanation
```
1. Push the opening parenteses into  the stack.
2. If closing bracket is encountered and stack top is not its opening part then its not valid and return false
3. Else pop 
4. If stack is empty its a valid parentheses as all the opening brackets are removed.
   if something remains which means that bracket hasn't been matched hence an invalid example
```

# Code

## C++
```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s)
        {
            if(ch == '(' or ch == '[' or ch == '{') st.push(ch);
            else if(st.empty()) return false;
            else if(ch == ')' and st.top() != '(') return false;
            else if(ch == ']' and st.top() != '[') return false;
            else if(ch == '}' and st.top() != '{') return false;   
            else st.pop();
        }
        return st.empty();
    }
};
```

## Python
```py
class Solution:
   def isValid(self, s):
    stack, match = [], {')': '(', ']': '[', '}': '{'}
    for ch in s:
        if ch in match:
            if not (stack and stack.pop() == match[ch]):
                return False
        else:
            stack.append(ch)
    return not stack
```
