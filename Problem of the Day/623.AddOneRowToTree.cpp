class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1 || depth == 0)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        int count = 0;
        while(!q.empty())
        {
            int n = q.size();
            count++;
            while(n--)
            {
                TreeNode *currNode = q.front();
                q.pop(); 

                if(count != depth - 1)
                {
                    if(currNode->left)
                        q.push(currNode->left);
                    if(currNode->right)
                        q.push(currNode->right);
                }

                else
                {
                    TreeNode *newLeft = new TreeNode(val);
                    newLeft->left = currNode->left;
                    currNode->left = newLeft;

                    TreeNode *newRight = new TreeNode(val);
                    newRight->right = currNode->right;
                    currNode->right = newRight;
                }
            }   
        }

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