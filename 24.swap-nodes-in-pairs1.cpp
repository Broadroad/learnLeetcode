/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (45.95%)
 * Likes:    1329
 * Dislikes: 118
 * Total Accepted:    345.4K
 * Total Submissions: 751.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *res = new ListNode(0);
        ListNode *prev = res, *one = head, *two = head->next;
        while (one && two)
        {
            one->next = two->next;
            two->next = one;
            prev->next = two;
            prev = one;
            one = one->next;
            if (one) two = one->next;
        }
        return res->next;
    }
};

