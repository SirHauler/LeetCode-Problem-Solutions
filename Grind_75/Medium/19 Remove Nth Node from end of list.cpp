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
    ListNode* removeNthFromEnd(ListNode* head, int n) {


        ListNode* tempHead = new ListNode(-1, head); 
        
        ListNode* curr = tempHead; 

        int ahead = n;

        ListNode* front = nullptr;

        for (int i = 0; i < ahead; i++) {
            if (curr->next == nullptr) {
                return nullptr;
            }
            curr = curr->next;
        }  

        front = curr; 
        ListNode* back = tempHead;

        while (front != nullptr) {
            if (front->next == nullptr) {
                ListNode* helper = back; 
                helper = back->next;
                back->next = helper->next;
                return tempHead->next;
            }
            back = back->next; 
            front = front->next;
        }
        
        return tempHead->next;
    }
};