/*
863. All Nodes Distance K in Binary Tree
Solved
Medium
Topics
Companies
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000
*/

/*
Runtime
15
ms
Beats
11.43%
of users with C++
Memory
19.90
MB
Beats
5.70%
of users with C++
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
    unordered_map<TreeNode*,unordered_set<TreeNode*>> neighbors;
    void dfs(TreeNode* root)
    {
        if (NULL == root)
        {
            return;
        }
        if (NULL != root->left)
        {
            neighbors[root].insert(root->left);
            neighbors[root->left].insert(root);
            dfs(root->left);
        }
        if (NULL != root->right)
        {
            neighbors[root].insert(root->right);
            neighbors[root->right].insert(root);
            dfs(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root || !target)
        {
            return {};
        }
        if (0 == k)
        {
            return {target->val};
        }
        dfs(root);
        queue<TreeNode*> fifo;
        fifo.push(target);
        int distance = 0;
        unordered_set<TreeNode *> visited;
        while (fifo.size() && distance < k)
        {
            // cout <<distance << " " << fifo.size() << endl;
            int level_size = fifo.size();
            distance++;
            while (level_size)
            {
                TreeNode * node = fifo.front();
                // cout << "   " << node->val << endl;
                visited.insert(node);
                fifo.pop();
                auto adj = neighbors[node];
                for (auto &links : adj)
                {
                    if (visited.find(links) == visited.end())
                    {
                        fifo.push(links);
                    }
                }
                level_size--;
            }
        }
        if (distance != k)
        {
            return {};
        }
        // cout <<distance << " " << fifo.size() << endl;
        vector<int> result;
        while (fifo.size())
        {
            result.push_back(fifo.front()->val);
            fifo.pop();
        }
        return result;
    }
};

/*https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/solutions/143775/very-easy-to-understand-c-solution/
very easy to understand c++ solution.

chejianchao
2151
24805
Jun 30, 2018
Using recursion to find all of the son=>parent pair into a map.
Using dfs to find K distance node, visited nodes will be recorded.
*/
class Solution {
public:
    vector<int> ans;   
    map<TreeNode*, TreeNode*> parent;  // son=>parent  
    set<TreeNode*> visit;    //record visied node
    
    void findParent(TreeNode* node){
        if(!node ) return;
        if( node->left ){
            parent[node->left] = node;
            findParent(node->left);
        }
        if( node->right){
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if( !root ) return {};
        
        findParent(root);
        dfs(target, K );
        return ans;
    }
    void dfs( TreeNode* node, int K){
        if( visit.find(node) != visit.end() )
            return;
        visit.insert(node);
        if( K == 0 ){
            ans.push_back(node->val);
            return;
        }
        if( node->left ){
            dfs(node->left, K-1);
        }
        if( node->right){
            dfs(node->right, K-1);
        }
        TreeNode* p = parent[node];
        if( p )
            dfs(p, K-1);
    }
};