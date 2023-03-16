class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() != inorder.size()) return NULL;

        map<int, int> inMap;

        for(int i=0; i<inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return helper(inorder, 0, inorder.size()-1, 
                        postorder, 0, postorder.size()-1, inMap);
    }


    TreeNode* helper(vector<int> &inorder, int inStart, int inEnd,
                    vector<int> &postorder, int postStart, int postEnd,
                    map<int, int> &inMap) 
    {
        if(inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[postorder[postEnd]];
        int numLeft = inRoot - inStart;

        root->left = helper(inorder, inStart, inRoot - 1, 
                            postorder, postStart, postStart+numLeft-1, inMap);
        
        root->right = helper(inorder, inRoot+1, inEnd, 
                            postorder, postStart+numLeft, postEnd-1, inMap);

        return root;
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