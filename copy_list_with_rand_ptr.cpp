/*
https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=problem-list-v2&envId=7p5x763&sorting=W3sic29ydE9yZGVyIjoiREVTQ0VORElORyIsIm9yZGVyQnkiOiJGUkVRVUVOQ1kifV0%3D&page=1
138. Copy List with Random Pointer
Solved
Medium
Topics
premium lock icon
Companies
Hint
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,625,338/2.7M
Acceptance Rate
60.5%
Topics
icon
Companies
Hint 1
Hint 2
Hint 3
Hint 4
Similar Questions
Discussion (237)

Accepted
19 / 19 testcases passed
pointnotfoe
pointnotfoe
submitted at Jun 16, 2025 18:30

Editorial

Solution
Runtime
9
ms
Beats
20.90%
Analyze Complexity
Memory
15.28
MB
Beats
27.93%
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *new_head = NULL;
        if (NULL == head)
        {
            return new_head;
        }
        new_head = new Node(head->val);
        Node *cur = head->next;
        Node *new_cur = new_head;
        Node *new_prev = new_head;
        unordered_map<Node*, Node*> old_new_map;
        old_new_map[NULL] = NULL;
        old_new_map[head] = new_head;
        //cout << head << " = [val: " << head->val << ", next: " << head->next << ", random: "<<head->random << "]\n";
        while(cur)
        {
            //cout << cur << " = [val: " << cur->val << ", next: " << cur->next << ", random: "<<cur->random << "]\n";
            new_cur = new Node(cur->val);
            old_new_map[cur] = new_cur;
            new_prev->next = new_cur;
            //cout << new_prev << " = [val: " << new_prev->val << ", next: " << new_prev->next << ", random: "<<new_prev->random << "]\n";
            cur = cur->next;
            new_prev = new_cur;
        }
        cur = head;
        new_cur = new_head;
        //cout << "========random mapping=========\n";
        while (cur)
        {
            //cout << cur << " = [val: " << cur->val << ", next: " << cur->next << ", random: "<<cur->random << "]\n";
            new_cur->random = old_new_map[cur->random];
            cur = cur->next;
            new_cur = new_cur->next;
        }
        return new_head;
    }
};