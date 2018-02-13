/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect2(TreeLinkNode *child){
        if(child -> left == NULL)
            return;
        else{
            child->left->next = child->right;
            child->right->next = child->next == NULL?NULL:child->next->left;
            connect2( child->left);
            connect2( child->right);
            return;
        }
            
        
        
    }
    
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return;
        else
            root->next = NULL;
        
        connect2(root);
    }
};
