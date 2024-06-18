/*https://leetcode.com/problems/minimum-height-trees/description/
310. Minimum Height Trees
Solved
Medium
Topics
Companies
Hint
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
 

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.
*/

/*
https://www.youtube.com/watch?v=wQGQnyv_9hI
Runtime
107
ms
Beats
60.06%
of users with C++
Memory
63.16
MB
Beats
28.35%
of users with C++
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        vector<int> result;
        unordered_map<int, vector<int> > connections;
        // int most_connected = edges[0][0];
        for (auto &edge : edges)
        {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
            // if (connections[edge[0]].size() > connections[most_connected].size())
            // {
            //     most_connected = edge[0];
            // }
            // else if (connections[edge[1]].size() > connections[most_connected].size())
            // {
            //     most_connected = edge[1];
            // }
        }
        vector<int> edge_cnt(n, 0);
        queue<int> leaves_fifo;
        for (auto &[src , adj] : connections)
        {
            int cnt = adj.size();
            if (cnt == 1)
                leaves_fifo.push(src);
            edge_cnt[src] = cnt;
        }
        int layer_size;
        while ((layer_size = leaves_fifo.size()))
        {
            if (n < 3)
            {
                // return {begin(leaves_fifo), end(leaves_fifo)};
                break;
            }
            for (int i = 0; i < layer_size; i++)
            {
                n--;
                int node = leaves_fifo.front();
                leaves_fifo.pop();
                for (auto adj: connections[node])
                {
                    edge_cnt[adj]--;
                    if (edge_cnt[adj] == 1)
                    {
                        leaves_fifo.push(adj);
                    }
                }
            }
        }
        while (leaves_fifo.size())
        {
            result.push_back(leaves_fifo.front());
            leaves_fifo.pop();
        }

        // result.push_back(most_connected);
        // vector<bool> visited(n, false);
        // visited[most_connected] = false;
        // int height = 1;
        // stack<int> fifo;
        // fifo.push(most_connected);
        // while (fifo.size())
        // {
        //     if (visited[edge])
        //         continue;
        //     fifo.push(edge);
        //     // for (auto child : connections[edge])
        //     while (fifo.size())
        //     {
        //         int top = fifo.top();
        //         fifo.pop();
        //         if (visited[top])
        //             continue;
                    
        //         fifo.push(top);
        //         height++
        //     }
            
        // }
        
        return result;
        
    }
};