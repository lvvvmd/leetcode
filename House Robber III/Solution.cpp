/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        int rst1 = rob(root->left) + rob(root->right);
        int rst2 = root->val;
        if(root->left){
            rst2+=rob(root->left->left) +rob(root->left->right);  
        }
        if(root->right)
            rst2+=rob(root->right->left) +rob(root->right->right);
        
        return max(rst1, rst2);
        
    }
};
