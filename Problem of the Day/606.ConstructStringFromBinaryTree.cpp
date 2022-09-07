class Solution {
public:
    void solve(TreeNode* root, string &str)
    {
        if(root == nullptr)
            return ;
        
        str += to_string(root->val);
        
        if(root->left) // left side check
        {
            str += '(';
            solve(root->left, str);
            str += ')';
        }
        
        if(root->right) // right side check
        {
            if(!root->left) str += "()"; // left side not present, but right is present
            str += '(';    
            solve(root->right, str);
            str += ')';
        }
            
    }
    
    string tree2str(TreeNode* root) {
        string str;    
        solve(root, str);
        return str;
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