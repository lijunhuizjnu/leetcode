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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        TreeNode *r =root;
        int M=max(p->val,q->val),m=min(q->val,p->val);
        while(r->val>M||r->val<m){
            if(r->val<m)r=r->right;
            else r=r->left;
        }
        return r;
    }
};
