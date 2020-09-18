# Problem Description
```
```

# Explanation
```
```

# Code

## C++
```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        fast = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
```

## Python
```py
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow, fast = nums[0], nums[0]
        
        while(True):
            slow = nums[slow]
            fast = nums[nums[fast]];
            if(slow==fast):
                break
                
        fast = nums[0]
        while(slow!=fast):
            slow = nums[slow]
            fast = nums[fast]
            
        return slow
```

## Java
```java
class Solution {
    public int findDuplicate(int[] nums) {
        
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        fast = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
}
```