/**
Autor: pointnotfoe
Leetcode:https://leetcode.com/problems/same-tree/
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
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
 /*
 Runtime: 5 ms, faster than 26.89% of C++ online submissions for Same Tree.
Memory Usage: 10.5 MB, less than 7.14% of C++ online submissions for Same Tree.
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> flat_p;
        traverse(p, flat_p);  
        
        vector<int> flat_q;
        traverse(q, flat_q);
        if (flat_p.size() != flat_q.size())
            return false;
        for (int i = 0; i < flat_p.size(); i++)
        {
            if (flat_p[i] != flat_q[i])
                return false;
        }
        return true;
    }
    void traverse(TreeNode *node, vector<int> &arr)
    {
        if (node == nullptr)
        {
            arr.push_back(-100);
            return;
        }
        arr.push_back(node->val);
        traverse(node->left, arr);
        traverse(node->right, arr);
    }
};

/*
Runtime: 10 ms, faster than 5.79% of C++ online submissions for Same Tree.
Memory Usage: 10 MB, less than 45.30% of C++ online submissions for Same Tree.
*/
//from platform's Java
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // p and q are both null
        if (p == nullptr && q == nullptr) return true;
        // one of p and q is null
        if (q == nullptr || p == nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->right, q->right) &&
                isSameTree(p->left, q->left);
    }

};