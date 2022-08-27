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


 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// Brute Force Method
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* find = head; 
        int count = 0; 
        
        if (head->next == nullptr) {
            return nullptr; 
        }
        
        while(find) {
            find = find->next;
            count++; 
        }
        
        int diff = count - n; 
        
        ListNode* find2 = head; 
        
        if (diff == 0) {
            head = head->next; 
            return head; 
        }
        
        while (diff > 1) {
            diff--; 
            find2 = find2->next; 
        }
                
        cout << find2->val << endl; 
        
        ListNode* help = find2->next->next; 
        
        find2->next = help;
        
        return head; 
    }
};

// Elegant Method





