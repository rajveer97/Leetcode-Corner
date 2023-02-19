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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        // ans.push(root->val);
        queue<TreeNode*> q;
        q.push(root);
        int c = 1;
        
        while(!q.empty())
        {            
            int len =  q.size();
            
            vector<int> v;
            for(int i=0; i<len; i++)
            {
                auto curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }
            
            if(c%2 == 0)           
                reverse(v.begin(), v.end());     
            
            c++;
            ans.push_back(v);  
        }
        
        return ans;
    }
};