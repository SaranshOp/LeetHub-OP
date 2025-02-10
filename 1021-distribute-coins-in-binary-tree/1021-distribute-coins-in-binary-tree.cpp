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
    int dfs(TreeNode* node,TreeNode* parent = NULL){
        if(node == NULL) return 0;
        int ans1 = dfs(node->left, node);
        int ans2 = dfs(node->right, node);

        int coins = node->val;
        int extra = coins - 1;
        node->val = 1;
        if(parent!=NULL)
        parent->val += extra;
        return ans1 + abs(extra) + ans2;
    }
    int distributeCoins(TreeNode* root) {
        
       return dfs(root);
    }
};