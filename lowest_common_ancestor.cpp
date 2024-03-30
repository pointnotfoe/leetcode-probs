
/*

based on platform solution
Runtime: 65 ms, faster than 5.09% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 17.3 MB, less than 9.83% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Next challenges:

*/
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
        unordered_map<TreeNode*,TreeNode*> parents;
        parents.insert({root, NULL});
        queue<TreeNode*> fifo;
        fifo.push(root);
        while(parents.find(p) == parents.end() || 
              parents.find(q) == parents.end())
        {
            auto node = fifo.front();
            fifo.pop();
            if (node->left != NULL)
            {
                parents.insert(make_pair(node->left, node));
                fifo.push(node->left);
            }    
            if (node->right != NULL)
            {
                parents.insert(make_pair(node->right, node));
                fifo.push(node->right);
            }    
        }
        unordered_set<TreeNode*> ancestors;
        while(p != NULL)
        {
            ancestors.insert(p);
            p = parents.find(p)->second;
        }
        
        while (ancestors.find(q) == ancestors.end())
        {
            q = parents.find(q)->second;
        }
        return q;
        // vector<TreeNode*> flat;
        // queue<TreeNode*> fifo;
        // if (root != NULL)
        //     fifo.push(root);
        // int p_index = -1;        
        // int q_index = -1;
        // while (!fifo.empty())
        // {
        //     auto node = fifo.front();
        //     fifo.pop();
        //     flat.push_back(node);
        //     // if (node->left != NULL)
        //     //     fifo.push(node->left);
        //     // if (node->right != NULL)
        //     //     fifo.push(node->right);
        //     if (node != NULL)
        //     {
        //         if (node->val == p->val)
        //             p_index = flat.size() - 1;
        //         if (node->val == q->val)
        //             q_index = flat.size() - 1;
        //         fifo.push(node->left);
        //         fifo.push(node->right);
        //     }
        // }
        // //reverse order
        // int start = -1;
        // int end = -1;
        // if (q_index > p_index)
        // {
        //     start = q_index;
        //     end = p_index;
        // }
        // else
        // {
        //     start = p_index;
        //     end = q_index;
        // }
        // // cout << "start = " << start << "\n";
        // // cout << "end = " << end << "\n";
        // unordered_set<int> short_parents;
        // short_parents.insert(end);
        // while(end != 0)
        // {
        //     end = floor((end-1)/2);
        //     short_parents.insert(end);
        // }
        // while(start != 0)
        // {
        //     start = floor((start-1)/2);
        //     // cout << "start = " << start << "\n";
        //     if (short_parents.find(start) != short_parents.end())
        //         break;
        // }
        // return flat[start];
    }
};
/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/discuss/65225/4-lines-C%2B%2BJavaPythonRuby
StefanPochmann

*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}