/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 
 1448. Count Good Nodes in Binary Tree
Medium

869

38

Add to List

Share
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 

Example 1:



Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:



Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 

Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
Accepted
56,156
Submissions
77,948

Runtime: 1400 ms, faster than 5.21% of C++ online submissions for Count Good Nodes in Binary Tree.
Memory Usage: 588.1 MB, less than 5.46% of C++ online submissions for Count Good Nodes in Binary Tree.
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int good_nodes = 0;
        if (nullptr == root)
        {
            return good_nodes;
        }
        
        set<int> unique;
        dfs(root, unique, good_nodes);
        return good_nodes;
    }
    void dfs(TreeNode* node, set<int> &unique, int &good_nodes)
    {
        if (nullptr == node)
        {
            return;
        }
        if (unique.end() == unique.upper_bound(node->val))
        {
            unique.insert(node->val);
            good_nodes++;
        }
        set<int> leftunique(unique);
        dfs(node->left, leftunique, good_nodes);
        
        set<int> rightunique(unique);
        dfs(node->right, rightunique, good_nodes);
    }
};
/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/discuss/635203/C%2B%2B-one-liner

Runtime: 116 ms, faster than 77.17% of C++ online submissions for Count Good Nodes in Binary Tree.
Memory Usage: 86.4 MB, less than 8.88% of C++ online submissions for Count Good Nodes in Binary Tree.
*/
int goodNodes(TreeNode* root, int val = INT_MIN) {
    return root == nullptr ? 0 : (val <= root->val) 
        + goodNodes(root->left, max(root->val, val))
            + goodNodes(root->right, max(root->val, val));
}
//Change ^ to 
//Runtime: 120 ms, faster than 67.49% of C++ online submissions for Count Good Nodes in Binary Tree.
//Memory Usage: 86.4 MB, less than 9.36% of C++ online submissions for Count Good Nodes in Binary Tree.
int goodNodes(TreeNode* root) {
        // write your code in C++14 (g++ 6.2.0)
        if (NULL == root)
        {
            return 0;
        }

        int visible_count = 1;//1 for the root
        traverse_with_max(root->left, root->val, visible_count);
        traverse_with_max(root->right, root->val, visible_count);
        return visible_count;
    }
    //traverse each node while keep track of the max in the parent
    void traverse_with_max(TreeNode * T, 
                           int max_val, 
                           int &visible_count)
    {
        if (NULL == T)
        {
            return;
        }
        if (max_val <= T->val)
        {
            visible_count++;
        }
        traverse_with_max(T->left, max(T->val, max_val), visible_count);
        traverse_with_max(T->right, max(T->val, max_val), visible_count);
    }