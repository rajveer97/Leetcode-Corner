
class Solution {
public:
    TreeNode* bst(int left, int right, vector<int> &nums)
    {
        
        if(left > right)
        {
            return NULL;
        }
        
        int mid = left + (right-left)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = bst(left, mid-1, nums);
        root->right = bst(mid+1, right, nums);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return NULL;
        
        return bst(0, n-1, nums);
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