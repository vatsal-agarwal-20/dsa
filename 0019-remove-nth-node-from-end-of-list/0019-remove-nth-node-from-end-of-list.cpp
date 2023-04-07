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
    int findLen(ListNode* head)
    {
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL) return NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        int length=findLen(head);
        if(length == n) 
        {
            head=head->next;
            return head;
        }
        int target = length - n;
        while(target > 0 && curr!=NULL)
        {
            prev=curr;
            curr=curr->next;
            target--;
        }
        prev->next=curr->next;
        curr->next=NULL;
        return head;
    }
};