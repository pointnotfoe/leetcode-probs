/*

Autor: pointnotfoe 
Leetcode: https://leetcode.com/problems/binary-tree-level-order-traversal/
102. Binary Tree Level Order Traversal
Medium

10173

197

Add to List

Share
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

/*
Runtime: 3 ms, faster than 88.67% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 12.6 MB, less than 63.12% of C++ online submissions for Binary Tree Level Order Traversal.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode*> fifo;
        fifo.push(root);
        while(fifo.size())
        {
            vector<int> level;
            size_t level_count = fifo.size();
            while(level_count)
            {
                TreeNode * temp = fifo.front();
                fifo.pop();
                level.push_back(temp->val);
                if (temp->left)
                {
                    fifo.push(temp->left);
                }
                if (temp->right)
                {
                    fifo.push(temp->right);
                }
                level_count--;
            }
            result.push_back(level);
        }
        return result;
    }
};