
class Solution {
public:
    int count = 0;
    void dfs(TreeNode* root, int currMax)
    {
        if(root==NULL)
            return ;
        
        if(root->val >= currMax)
        {
            count++;
            currMax = root->val;
        }
            
        
        if(root->left) dfs(root->left, currMax);
        if(root->right) dfs(root->right, currMax);
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        
        return count;
    }
};

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