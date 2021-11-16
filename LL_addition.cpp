/**

Autor: pointnotfoe
Leetcode:https://leetcode.com/problems/add-two-numbers/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 2. Add Two Numbers
 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

Runtime: 24 ms, faster than 86.30% of C++ online submissions for Add Two Numbers.
Memory Usage: 71.5 MB, less than 48.26% of C++ online submissions for Add Two Numbers.
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum_head = new ListNode();
        ListNode *cur = sum_head;
        bool carry = false;
        while (l1 != nullptr || l2 != nullptr)
        {
            int first = l1 == nullptr? 0 : l1->val;
            int second = l2 == nullptr? 0 : l2->val;

            cur->val = first + second + (carry ? 1 :0);
            if (cur->val > 9)
            {
                cur->val = cur->val % 10;
                carry = true;
            }
            else
            {
                carry = false;
            }
            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            else
            {
                l1 = nullptr;
            }
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
            else
            {
                l2 = nullptr;
            }
            if (l1 == nullptr && l2 == nullptr)
            {
                break;
            }
            cur->next = new ListNode();
            cur = cur->next;
        }
        if (carry)
        {
            cur->next = new ListNode(1);
        }
        return sum_head;
    }
};