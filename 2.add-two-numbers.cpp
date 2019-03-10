/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.66%)
 * Total Accepted:    781.6K
 * Total Submissions: 2.5M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* l3 = head;
        int carry = 0;
        while (l1 || l2) {
            int l =l1? l1->val:0;
            int r =l2? l2->val:0;
            carry = carry + l + r;

            l3->next = new ListNode(carry % 10);
            carry /= 10;
            l3=l3->next;

            if (l1) {
                l1 = l1->next; 
            };
            if (l2) {
                l2 = l2->next;
            };
        } 
        if (carry == 1) {
            l3->next = new ListNode(1);
        }
     
        return head->next;
    };
};

