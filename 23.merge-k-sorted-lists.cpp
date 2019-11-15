/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (36.82%)
 * Likes:    3189
 * Dislikes: 210
 * Total Accepted:    485.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */

// @lc code=start
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
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }

        priority_queue<ListNode*, vector<ListNode*> , cmp> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            if (!cur) {
                continue;
            }
            if (cur && cur->next) {
                pq.push(cur->next);
            }

            prev->next = cur;
            prev = cur;
        }
        return dummy->next;
    }
};
// @lc code=end

