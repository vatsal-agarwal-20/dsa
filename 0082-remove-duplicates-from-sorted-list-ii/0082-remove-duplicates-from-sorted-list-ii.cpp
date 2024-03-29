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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = head->next;
        
        while(next!=NULL)
        {
            if(curr->val == next->val)
            {
                while(next && next->val == curr->val)
                {
                    next = next->next;
                }
                if(prev == NULL) head = next;
                else
                {
                    prev->next = next;
                }
            }
            else
            {
                prev = curr;
            }
            
            curr = next;
            if(next)
            {
                next = curr->next;
            }
        }
        return head;
    }
};