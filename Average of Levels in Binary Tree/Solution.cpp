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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> rst;
        if(root == NULL)
        return rst;
        else{
            rst.push_back(root->val);
            vector<TreeNode*> thisLayer;
            if(root->left != NULL)
                thisLayer.push_back(root->left);
            if(root->right != NULL)
                thisLayer.push_back(root->right);
            while(thisLayer.size()!= 0){
                vector<TreeNode*> nextLayer;
                int s = thisLayer.size();
                double sum = 0;
                for(int i = 0;i<s;i++){
                    sum += thisLayer[i]->val;
                    if(thisLayer[i]->left != NULL)
                        nextLayer.push_back(thisLayer[i]->left);
                    if(thisLayer[i]->right != NULL)
                        nextLayer.push_back(thisLayer[i]->right);
                }
                sum /= s;
                rst.push_back(sum);
                
                thisLayer = nextLayer;
            }
            
            return rst;
        }
    }
};
