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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *head = new ListNode(0);
            ListNode *cur = head;
            int carry = 0;
            int sum = 0;
            while (l1 || l2 || carry == 1) {
                
                int l1_val = (l1) ? l1->val : 0; 
                int l2_val = (l2) ? l2->val : 0;
                
                sum = l1_val + l2_val + carry; 
                
                carry = sum / 10;
                
                std::cout << "Sum: " << sum << std::endl;
                
                cur->next = new ListNode(sum % 10);
                
                cur = cur->next;
                
                l1 = (l1) ? l1->next: NULL; 
                l2 = (l2) ? l2->next: NULL;
                
            }
        
        return head->next;
    }
};