// Method 1:
class Solution {
public:
    int solve(TreeNode* root, int targetSum)
    {
        if(targetSum == 0 && !root->left && !root->right)
            return 1;

        if(root->left)
            if(solve(root->left, targetSum - root->left->val))
                return 1;
        
        if(root->right)
            if(solve(root->right, targetSum - root->right->val))
                return 1;

        return 0;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;

        if(solve(root, targetSum-root->val))
            return 1;
    
        return  0;
    }
};

//---------------------------------------------------------------

// Method 2:
class Solution {
public:
    bool solve(TreeNode* root, int targetSum)
    {
        if(root==NULL)
            return false;

        targetSum -= root->val;

        if(!root->left  && !root->right && targetSum==0) return true;

        return solve(root->left, targetSum) || solve(root->right, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
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