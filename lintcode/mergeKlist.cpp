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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }

        return helper(lists, 0, lists.size()-1);
    }

private:
    ListNode* helper(vector<ListNode*> &lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode* left = helper(lists, start, mid);
        ListNode* right = helper(lists, mid+1, end);
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                prev->next = head1;
                prev = head1;
                head1 = head1->next;
            } else {
                prev->next = head2;
                prev = head2;
                head2 = head2->next;
            }
        }
        if (head1) {
            prev->next = head1;
        } else {
            prev->next = head2;
        }
        return dummy->next;
    }
};