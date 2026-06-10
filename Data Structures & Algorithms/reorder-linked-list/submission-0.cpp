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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }        
        

        ListNode* temp1 = slow->next; 
        slow->next = NULL; 
        ListNode* prev = NULL;
        
        while(temp1){
            ListNode* front = temp1->next;
            temp1 ->next = prev;
            prev = temp1;
            temp1 = front; 
        }

        ListNode* sec = prev;
        ListNode* fir = head;

        while(sec){
            ListNode* firnext = fir->next;
            ListNode* secnext = sec->next;
            
            fir->next = sec;
            sec->next = firnext;

            fir = firnext;
            sec = secnext;
        }
    }
};
