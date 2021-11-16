/*
Author: pointnotfoe
Leetcode: https://leetcode.com/problems/linked-list-cycle/

141. Linked List Cycle
Easy

5973

680

Add to List

Share
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
Runtime: 16 ms, faster than 30.11% of C++ online submissions for Linked List Cycle.
Memory Usage: 10.6 MB, less than 13.64% of C++ online submissions for Linked List Cycle.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    bool hasCycle(ListNode *head) {
        if (NULL == head)
        {
            return false;
        }
        unordered_set<ListNode*> unique;
        unique.insert(head);
        head = head->next;
        while(head)
        {
            if(unique.find(head) != unique.end())
            {
                return true;
            }
            unique.insert(head);
            head = head->next;
        }
        return false;
    }
};

/*
Runtime: 12 ms, faster than 71.69% of C++ online submissions for Linked List Cycle.
Memory Usage: 8 MB, less than 81.46% of C++ online submissions for Linked List Cycle.
*/
bool hasCycle(ListNode *head) {
        if (NULL == head)
        {
            return false;
        }
        ListNode *slow = head;        
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            if (slow == fast)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }