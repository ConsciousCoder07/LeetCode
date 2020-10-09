# Problem Description
```
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
```

# Explanation
```
Brute approach would be to count each number's occurence and return the one having occured only once. But the better way is to use xor operator.
e.g. : [2,2,1], res=0
res ^ 2 ^ 2 ^ 1 = 1
It removes duplicates.
```

# Code

## C++
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto num : nums)
            res ^= num;
        return res;
    }
};
```

## Python
```py
# Method 1:
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(lambda x,y : x^y, nums)

# Method 2:
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(operator.xor, nums) #operator.xor(a,b) = a^b
```

## Java
```java
class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for(int num : nums)
        {
            res ^= num;
        }
        return res;
    }
}
```