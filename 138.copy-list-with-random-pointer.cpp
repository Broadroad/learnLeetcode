/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (30.33%)
 * Likes:    2166
 * Dislikes: 531
 * Total Accepted:    311.7K
 * Total Submissions: 1M
 * Testcase Example:  '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 * 
 * Explanation:
 * Node 1's value is 1, both of its next and random pointer points to Node 2.
 * Node 2's value is 2, its next pointer points to null and its random pointer
 * points to itself.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You must return the copy of the given head as a reference to the cloned
 * list.
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
        if (!head) {
            return nullptr;
        }

        unordered_map<Node*, Node*> m;
        Node* l1 = head;
        Node* l2Head = new Node(0, nullptr, nullptr);
        Node* prev = l2Head;

        while (l1) {
            Node* l2 = new Node();
            m[l1] = l2;
            l1 = l1->next;
            l2->random = nullptr;
            l2->next = nullptr;
            prev->next = l2;
            prev = l2;
        }

        l1 = head;
        while (l1) {
            Node* n = m[l1];
            n->random = m[l1->random];
            n->val = l1->val;
            l1 = l1->next;
        }
        return l2Head->next;
        */
       if (!head) {
           return nullptr;
       }

       Node* l1 = head;
       while (l1) {
           Node* next = l1->next;
           Node* l11 = new Node(l1->val, next, nullptr);
           l1->next = l11;
           l1 = next;
       }

       l1 = head;
       Node* l2 = l1->next;
       Node* ans = l2;
       while (l1) {
           l2 = l1->next;
           if (l1->random) {
                l2->random = l1->random->next;
           }
           l1 = l2->next;
       }

       l1 = head;
       while (l1) {
           l2 = l1->next;
           l1->next = l2->next;
           if (l2->next) {
            l2->next = l2->next->next;
           }
           l1 = l1->next;
       }
       return ans;
    }
};
// @lc code=end

