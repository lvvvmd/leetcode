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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(root ==NULL)
            return NULL;
        if(d == 1){
            TreeNode* newnode = new TreeNode(v);
            newnode->left = root;
            return newnode;
            
        }
        else if(d == 2){
            if(1){
                TreeNode* newnode = new TreeNode(v);
                 newnode->left = root->left;
                root->left = newnode;
            }
            if(1){
                 TreeNode* newnode = new TreeNode(v);
                 newnode->right = root->right;
                root->right = newnode;
            }
            
            return root;
            
            
        }
        else{
            root->left = addOneRow(root->left, v, d-1);
             root->right = addOneRow(root->right, v, d-1);
            return root;
        }
    }
};
