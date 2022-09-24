class Solution {
private:
    void pathSum_helper(TreeNode* root, int target, int curr_Sum, vector<int> temp, vector< vector<int> >& ans)
    {
		
        temp.push_back(root->val);
		
        curr_Sum += root->val;
		
        if(curr_Sum == target && (!root->left && !root->right))
        {
            ans.push_back(temp);
            return;
        }
        if(!root->left && !root->right)
        {
            return;
        }
        
        if(root->left) pathSum_helper(root->left, target, curr_Sum, temp, ans);
        if(root->right) pathSum_helper(root->right, target, curr_Sum, temp, ans);
		
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> temp;
        pathSum_helper(root, targetSum, 0, temp, ans);
        return ans;
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