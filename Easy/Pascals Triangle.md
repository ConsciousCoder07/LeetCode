# Problem Description
```
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

Example:
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

# Explanation
```
1. Iterate through rows.
2. Resize columns equals to rows.
3. Set first and last element to be 1.
4. Calculate second to second last element for each row.
5. return the 2-D triangle array.
```

# Code

## C++
```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> triangle(numRows);
        for(int i = 0; i < numRows; i++){
            
            triangle[i].resize(i+1); //making columns and rows same
            triangle[i][0] = triangle[i][i] = 1; //first and last element is 1
            
            //iterate from second to second last element
            for(int j = 1; j < triangle[i].size()-1; j++)
                triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
        }
        return triangle;   
    }
};
```

## Python
```py
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        triangle = []
        for numRow in range(numRows):
            row = [0 for _ in range(numRow+1)]
            # first and last element of the each row is 1 
            row[0], row[-1] = 1, 1
            
            # iterate from second to second last element of each row
            for i in range(1, len(row)-1):
                row[i] = triangle[numRow-1][i] + triangle[numRow-1][i-1]
            triangle.append(row)
            
        return triangle
```
