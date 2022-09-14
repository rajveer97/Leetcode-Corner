class Solution {
public:
    void pseudo_count(TreeNode* root, vector<int> &n, int &count)
    {
        if(root==NULL) return ;
        n[root->val]++;
        
        if(root->left) pseudo_count(root->left, n, count);
        if(root->right) pseudo_count(root->right, n, count);
        
        if(root->left==NULL && root->right==NULL)
        {
            int flag = 0;
            
            for(int i=1; i<=9; i++)
            {
                if(n[i] % 2 != 0)
                    flag++;
            }
            
            if(flag==0 || flag==1)
                count++;
        }
        
        n[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        vector<int> n(10, 0);
        pseudo_count(root, n, count);
        
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