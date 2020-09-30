# Problem Description
```
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

 Example 1: 

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
```

# Explanation
```
1. Create a key value pair using map or dict which records the frequency of occurence of number.
2. Create a set and store the value in it which removes the duplicates.
3. Return the boolean of comparision between the length of set and map/dict
```

# Code

## C++
```c++
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int, int> m;
        set<int> s;
        
        for(auto i : arr) 
            m[i]++;
        for(auto i : m)
            s.insert(i.second);
        
        return size(m) == size(s);
    }
}; 
```

## Python
```py
#Method 1:
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        d=dict(Counter(arr))
        s=set(d.values())
        return len(d.values())==len(s)

#Method 2:
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        s = list(set(arr))
        count = [arr.count(i) for i in s]
        return len(count) == len(set(count))
```

