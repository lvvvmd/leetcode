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
    pair<int, int> find2(TreeNode* root, int layer){
        if(root == NULL)
            return pair<int, int>(0, -1);
        else if(root->left == NULL && root->right == NULL)
            return pair<int, int>(root->val, layer);
        else{
            auto left = find2(root->left, layer+1);
            auto right = find2(root->right, layer+1);
            if(left.second < right.second)
                return right;
            else
                return left;

        }
    }
    
    int findBottomLeftValue(TreeNode* root) {
        return find2(root, 0).first;
    }
};
