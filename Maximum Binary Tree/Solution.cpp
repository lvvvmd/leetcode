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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        
        TreeNode* rst = new TreeNode(0);
        auto Max = max_element(nums.begin(), nums.end());
        rst->val = *Max;
        vector<int> left, right;
        vector<int>::iterator tmp;
        for(tmp = nums.begin();tmp < Max;tmp++){
            left.push_back(*tmp);            
        }
        for(tmp = Max+1;tmp < nums.end();tmp++){
            right.push_back(*tmp);            
        }
        
        rst->left = constructMaximumBinaryTree(left);
         rst->right = constructMaximumBinaryTree(right);
        
        return rst;
    }
};
