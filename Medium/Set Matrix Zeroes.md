# Problem Description
```
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
```

# Explanation
```
-If the constraints were not negative we could've stored negative values in the corresponding rows and cols were 0 in spotted and then replace those negatives by 0.

-In 2nd and 4th method row and col states are stored in first row and first col to avoid extra space
-In 3rd method the col state is not stored but calculated for each iteration using a bool var. 
```

# Code

## C++
```c++
// Method 1: Space: O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rsize = matrix.size(), csize = matrix[0].size();
        vector<int> row(rsize, 1), col(csize, 1);
        
        for(int i=0; i<rsize; i++){
            for(int j=0; j<csize; j++){
                if(matrix[i][j] == 0){
                    row[i] = col[j] = 0;
                }
            }
        }
        
        for(int i=0; i<rsize; i++){
            for(int j=0; j<csize; j++){
                if(row[i]==0 || col[j]==0)
                    matrix[i][j] = 0;
            }
        }
        
    }
};

//Method 2: Space: O(1)
class Solution {
public:
   void setZeroes(vector<vector<int>>& matrix) {
        bool isZeroCol = false;
        bool isZeroRow = false;
        for (int i = 0; i < matrix.size(); i++) { //check the first column
            if (matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            } 
        }
        for (int i = 0; i < matrix[0].size(); i++) { //check the first row
            if (matrix[0][i] == 0) {
                isZeroRow = true;
                break;
            } 
        }
        for (int i = 1; i < matrix.size(); i++) { //check except the first row and column
            for (int j = 1; j < matrix[0].size(); j++) 
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        for (int i = 1; i < matrix.size(); i++) { //process except the first row and column
           for (int j = 1; j < matrix[0].size(); j++) 
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
                   matrix[i][j] = 0;
        }
        if (isZeroCol) { //handle the first column
            for (int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }
        if (isZeroRow) { //handle the first row
            for (int i = 0; i < matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }
   }
};

// Method 3: 
// Same as above except it doesn't store column zeroes and uses boolean var for it.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rsize = matrix.size(), csize = matrix[0].size();
        vector<int> col_zero(csize, 1);
        
        // check for first row
        bool first_row_zero = false;
        for(int c = 0; c < csize; c++){
            if(matrix[0][c] == 0){
                first_row_zero = true;
            }
        }
        
        // checks for zeros 
        for(int r=0; r<rsize; r++){
            for(int c=0;  c<csize; c++){
                if(matrix[r][c] == 0){
                    matrix[0][c] = 0; // denotes which column should be zero
                }
            }
        }
        for(int r=1; r<rsize; r++){
            
            // check if row contains 0
            bool row_contains_zero = false;
            for(int c = 0; c<csize; c++){
                if(matrix[r][c] == 0){
                    row_contains_zero = true;
                    break;
                }
            }
            
            // fill the zeroes
            for(int c=0; c<csize; c++){
                if(row_contains_zero || matrix[0][c]==0){
                    matrix[r][c] = 0;
                }
            }
        }
        
        // if first row contains 0 fill it with 0's
        if(first_row_zero){
            for(int c=0; c<csize; c++){
                matrix[0][c] = 0;
            }
        }
        
    }
};

//Method 4: Space: O(1)
//Quite similar to 2nd method
//the state of row0 and col0 will occupy the same state i.e. a[0][0] so let row0 use it and for col0 use a variable
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}
};
```

## Python
```py
# Method 1: Space: O(m+n)
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows, cols = len(matrix), len(matrix[0]) 
        rowZeroes, colZeroes = [False]*rows, [False]*cols
        
        for r in range(rows):
            for c in range(cols):
                if matrix[r][c] == 0:
                    rowZeroes[r] = True
                    colZeroes[c] = True
        
        for r in range(rows):
            for c in range(cols):
                if rowZeroes[r] or colZeroes[c]:
                    matrix[r][c] = 0       
```

