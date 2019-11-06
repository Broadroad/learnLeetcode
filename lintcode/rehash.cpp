/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int size = hashTable.size();
        if (size <= 0) {
            return hashTable;   
        }
        
        int newSize = size * 2;
        vector<ListNode*> newHash(newSize);
        for (int i = 0; i < size; i++) {
            ListNode* node = hashTable[i];
            while (node) {
                int val = node->val;
                ListNode *o = newHash[(val % newSize + newSize) % newSize];
                if (o) {
                    while (o->next) {
                        o = o->next;
                    }
                    ListNode *newNode = new ListNode(node->val);
                    o->next = newNode;
                    
                } else {
                    ListNode *newNode = new ListNode(node->val);
                    newHash[(val % newSize + newSize) % newSize] = newNode;
                }
                node = node->next;
            }
        }
        return newHash;
    }
};
