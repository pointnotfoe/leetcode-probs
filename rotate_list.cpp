/*https://leetcode.com/problems/rotate-list/description/
61. Rotate List
Solved
Medium
Topics
Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 /*
 Runtime
10
ms
Beats
16.25%
of users with C++
Memory
15.22
MB
Beats
25.23%
of users with C++
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k <= 0)
        {
            return head;
        }
        int list_size = 1;
        ListNode * tail = head;
        while (tail->next)
        {
            tail = tail->next;
            list_size++;
        }
        k = k % list_size;
        if (0 == k)
        {
            return head;
        }
        int new_tail_count = list_size - k - 1;
        ListNode * new_tail = head;
        while(new_tail_count)
        {
            new_tail = new_tail->next;
            new_tail_count--;
        }
        tail->next = head;
        ListNode * new_head = new_tail->next;
        new_tail->next = nullptr;
        return new_head;
    }
};