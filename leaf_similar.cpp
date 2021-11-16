/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/interview/2/
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
Example 2:

Input: root1 = [1], root2 = [1]
Output: true
Example 3:

Input: root1 = [1], root2 = [2]
Output: false
Example 4:

Input: root1 = [1,2], root2 = [2,2]
Output: true
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> leafs1;
        find_leafs(root1, leafs1);
        vector <int> leafs2;
        find_leafs(root2, leafs2);
        if (leafs2.size() != leafs1.size())
        {
            return false;
        }
        for (int i = 0; i < leafs1.size(); i++)
        {
            if (leafs1[i] != leafs2[i])
            {
                return false;
            }
        }
        return true;
        
        
    }
    
    void find_leafs(TreeNode *node, vector<int> &leafs)
    {
        if (node->right == nullptr && node->left == nullptr)
        {
            leafs.push_back(node->val);
            return;
        }
        if (node->left != nullptr)
        {
            find_leafs(node->left, leafs);
        }
        if (node->right != nullptr)
        {
            find_leafs(node->right, leafs);
        }

    }
};