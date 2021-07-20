/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *, int> sums;
    int rob(TreeNode* root) {
        sums={};
        return tryRob(root);
    }
    int tryRob(TreeNode* node) {
        if (!node) return 0;
        if (sums.count(node)) return sums[node];
        //偷取该节点
        int res1 = 0;
        if (node->left) {
            res1 += (tryRob(node->left->left) + tryRob(node->left->right));
        }
        if (node->right) {
            res1 += (tryRob(node->right->left) + tryRob(node->right->right));
        }
        res1 += node->val;
        //不偷取该节点
        int res2 = tryRob(node->left) + tryRob(node->right);
        sums[node] = max(res1, res2);
        return sums[node];
    }
};
