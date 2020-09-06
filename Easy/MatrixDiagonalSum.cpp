class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int sum = 0;
        int size = mat.size(); //rows and column size would be same
        
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                if(i==j || i+j==size-1)
                    sum += mat[i][j];
        
        return sum;
    }
};