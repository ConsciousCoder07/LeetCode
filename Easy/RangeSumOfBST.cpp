/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private: 
    int sum=0;
public:
            
    void dfs(TreeNode* root, int L, int R)
    {
        if(!root)    //root is null
            return;
        if(root->val >= L && root->val <= R) //If values are in range >= L and <= R then add
            sum+=root->val;
        if(root->val > L) // Traverse left node only if value is in permissible range
            dfs(root->left, L, R);
        if(root->val < R) // Traverse right node only if value is permissible range
            dfs(root->right, L, R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
    
        dfs(root, L, R);
        return sum;
    }
};


