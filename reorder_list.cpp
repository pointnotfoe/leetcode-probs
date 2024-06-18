/*https://leetcode.com/problems/reorder-list/description/
143. Reorder List
Solved
Medium
Topics
Companies
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
*/

/*
Runtime
12
ms
Beats
99.28%
of users with C++
Memory
21.17
MB
Beats
90.06%
of users with C++
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
class Solution {
public:
    //based on https://leetcode.com/problems/reorder-list/solutions/1640556/c-easy-to-solve-beginner-friendly-with-detailed-explanation-and-dry-run/
    void reorderList(ListNode* head) {
        if (!head)
            return;
        ListNode* slow = head;//, *prev_slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            //prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //prev_slow->next = nullptr;//disconnect the two halves
        //slow points to midway. reverse the last half
        ListNode *prev = nullptr, *next;
        while (slow)
        {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        //interleave first and reversed second half
        ListNode *first = head, *second = prev, *f_next, *s_next;
        while (first && second)
        {
            f_next = first->next;
            s_next = second->next;
            first->next = second;
            first = f_next;
            second->next = f_next;
            second = s_next;
        }
    }
};