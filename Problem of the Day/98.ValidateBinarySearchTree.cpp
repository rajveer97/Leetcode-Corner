// Method 1: Inorder Traversal 
class Solution {
public:
    void inOrder(TreeNode* root, vector<int> &ans)
    {
        if(root==NULL)
            return ;
        
        
        if(root->left) inOrder(root->left, ans);
        ans.push_back(root->val);
        if(root->right) inOrder(root->right, ans);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inOrder(root, ans);
        
        for(int i=1; i<ans.size(); i++)
        {
            if(ans[i] <= ans[i-1])
                return false;
        }
        
        return true;
    }
};

//------------------------------------------------------------------------------

// Method 2: 

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
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
