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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> rst;
        if(root != NULL)
        stack.push_back(root);
        while(stack.size() != 0){
            TreeNode* tmp = stack.back();
            stack.pop_back();
            rst.push_back(tmp->val);
            
            if(tmp->right!=NULL)
                stack.push_back(tmp->right);
            
            if(tmp->left!=NULL)
                stack.push_back(tmp->left);
        }
        return rst;
    }
};
