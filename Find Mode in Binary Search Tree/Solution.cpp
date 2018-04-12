/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
using namespace std;
class Solution {
public:

   vector<int> findMode(TreeNode* root) {
        vector<int> rst;
        if(root == NULL)
            return rst;
        
        stack<TreeNode*> stk;
        map<int, int> m;
       
       stk.push(root);
       // rst.push_back(root->val);
       // max = 1;
        while(!stk.empty()){
            auto p = stk.top();
            stk.pop();
            //cout << p->val << endl;
            if(m.find(p->val) != m.end()){
                m[p->val]++;
            }
            else{
                m.insert(pair<int, int>(p->val, 1));
            }
            if(p->left != NULL)
                stk.push(p->left);
            if(p->right != NULL)
                stk.push(p->right);
        }
        
        int max = 0;
        for(auto i = m.begin();i!= m.end();i++){
            if((*i).second > max){
                rst.clear();
                rst.push_back((*i).first);
                max = (*i).second;
            }
            else if((*i).second == max){
                rst.push_back((*i).first);
            }
            
            
        }
        return rst;
    }
};
