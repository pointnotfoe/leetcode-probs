/**https://leetcode.com/explore/learn/card/recursion-i/251/scenario-i-recurrence-relation/3233/
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return nullptr;
        if (val == root->val)
            return root;
        if (root->val > val)
            return searchBST(root->left, val);
        else 
            return searchBST(root->right, val);
    }
};