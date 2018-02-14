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
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> nums;
        s.push(root);
        while(!s.empty()){
            TreeNode* tmp = s.top();
            s.pop();
            nums.push_back(tmp->val);
            if(tmp->left!=NULL)
                s.push(tmp->left);
            if(tmp->right!=NULL)
                s.push(tmp->right);
        }
        sort(nums.begin(), nums.end());
        int min = 9999;
        for(int i = 0;i<nums.size()-1;i++){
            int tmpmin = nums[i+1] - nums[i];
            if(tmpmin < min)
                min = tmpmin;
            
        }
        return min;
        
    }
};
