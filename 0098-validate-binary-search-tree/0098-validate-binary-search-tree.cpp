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
    bool solve(TreeNode* root, long long lb, long long ub){
        if(root == NULL) return true;

        bool inRange = root->val > lb && root->val < ub;

        bool left = solve(root->left, lb, root->val);
        bool right = solve(root->right, root->val, ub);

        return inRange && left && right;
    }
    bool isValidBST(TreeNode* root) {
        long long lb = LONG_MIN;
        long long ub = LONG_MAX;
        bool ans = solve(root, lb, ub);
        return ans;
    }
};