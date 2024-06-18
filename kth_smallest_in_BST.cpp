/*230. Kth Smallest Element in a BST
Solved
Medium
Topics
Companies
Hint
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
*/
/*
Runtime
12
ms
Beats
65.27%
of users with C++
Memory
22.48
MB
Beats
85.72%
of users with C++
*/
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
    int result;
    int _k;
    void dfs(TreeNode *root)
    {
        if (result >= 0 || !root)
            return;
        dfs(root->left);
        _k--;
        if (_k == 0)
        {
            result = root->val;
            return;
        }
        if (result >= 0)
            return;
        dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        result = -1;
        _k = k;
        dfs(root);
        return result;
        
    }
};