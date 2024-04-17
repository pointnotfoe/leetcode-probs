/*
Author: pointnotfoe
Leetcode: https://leetcode.com/problems/reverse-linked-list/
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 Runtime: 8 ms, faster than 64.41% of C++ online submissions for Reverse Linked List.
Memory Usage: 8.3 MB, less than 41.66% of C++ online submissions for Reverse Linked List.
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
    ListNode* reverseList(ListNode* head) {
        // if (nullptr == head)
        // {
        //     return head;
        // }
        ListNode *prev = nullptr;
        while(head)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

/**https://leetcode.com/explore/learn/card/recursion-i/251/scenario-i-recurrence-relation/2378/
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
    void recrReverseList(ListNode* head, ListNode** prev) {
        if (nullptr == head)
        {
            return;
        }
        ListNode* next = head->next;
        head->next = *prev;
        *prev = head;
        recrReverseList(next, prev);
    }
    ListNode* reverseList(ListNode* head) {
        ///---------itr
        // if (nullptr == head)
        // {
        //     return head;
        // }
        // ListNode *prev = nullptr;
        // while(head)
        // {
        //     ListNode *next = head->next;
        //     head->next = prev;
        //     prev = head;
        //     head = next;
        // }
        // return prev;
        ///-------------------------
        ///---------recr----------------
        ListNode * prev = nullptr;
        recrReverseList(head, &prev);
        ///-------------------------

        return prev;
    }
};