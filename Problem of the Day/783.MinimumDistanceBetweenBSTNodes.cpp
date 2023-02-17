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
    vector<int> v;

    void helper(TreeNode* root) {
        if(root == NULL) return;

        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    } 

    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        helper(root);

        int n = v.size();

        reverse(v.begin(), v.end());


        for(int i=0; i<n-1; i++) {
            minDiff = min(minDiff, v[i] - v[i+1]);
        }
        
        return minDiff;
    }
};