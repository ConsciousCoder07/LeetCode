# Problem Description
```

Given a collection of intervals, merge all overlapping intervals.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

# Explanation
```
1. Take a temp interval initialized to intervals[0]
2. for interval in intervals
        if current interval merges within temp
            change temp to merged interval
        else
            append temp in mergedintervals and 
            change temp to current interval
3. Last interval remains unadded so add it.
4. Return the mergedIntervals.
```

# Code

## C++
```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
                
        if(intervals.size() <= 1)
            return intervals;
        
        vector<vector<int>> mergedIntervals;
        
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];
        
        for(auto iter : intervals){
            
            if(iter[0] <= tempInterval[1]) // if merging
                tempInterval[1] = max(iter[1], tempInterval[1]);
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval = iter;
            }
        }
        mergedIntervals.push_back(tempInterval); // last interval is unadded so add it
        
        return mergedIntervals;
    }
};
```

## Python
```py
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        if(len(intervals) <= 1):
            return intervals
        
        intervals.sort()
        mergedIntervals = []
        
        tempInterval = intervals[0]
        
        for c, d in intervals[1:]:
            
            if(c <= tempInterval[1]):
                tempInterval[1] = max(d, tempInterval[1])
            else:
                mergedIntervals.append(tempInterval)
                tempInterval = [c,d]
                
        mergedIntervals.append(tempInterval)
        return mergedIntervals
```

