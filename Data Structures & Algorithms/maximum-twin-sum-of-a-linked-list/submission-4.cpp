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
    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        if(!head) return 0;
        if(!fast->next) return fast->val;
        if(!fast->next->next) return fast->val + fast->next->val;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow;
        // slow->next = NULL;
        ListNode* prev = NULL;

        while(temp){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
        }

        int sum = 0;
        int maxSum = 0;
        ListNode* sec = prev;
        ListNode* fir = head;

        while(sec){
        ListNode* secNext = sec->next;
        ListNode* firNext = fir->next;
        
        sum = fir->val + sec->val;
        maxSum = max(sum, maxSum);

        fir = firNext;
        sec = secNext;
        }
        return maxSum;
    }
};