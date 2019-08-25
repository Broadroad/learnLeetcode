/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (37.56%)
 * Likes:    1334
 * Dislikes: 269
 * Total Accepted:    200.8K
 * Total Submissions: 534.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        dummy -> next = head;
        int len = length(head);
        for(int i = 0; i < len / k; i++) {
            for (int j = 1; j < k; j++) {
                ListNode *tmp = pre->next;
                pre->next = head->next;
                head->next = head->next->next;
                pre->next->next = tmp;
            }
            pre = head;
            head = head->next;
        }
        return dummy->next;
    }
private:
    ListNode *dummy = new ListNode(0), *pre = dummy;
    int length(ListNode *head) {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
};

