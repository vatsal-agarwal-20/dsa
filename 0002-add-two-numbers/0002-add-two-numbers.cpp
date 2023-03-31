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
        ListNode* ansHead = new ListNode();
        ListNode* temp = ansHead;
        int carry=0;
        while(l1!=NULL && l2!=NULL)
        {
            int sum=l1->val+l2->val+carry;
            carry = sum/10;
            sum=sum%10;
            
            ListNode* newSum = new ListNode(sum);
            temp->next=newSum;
            temp=temp->next;
            
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int sum=l1->val+carry;
            carry = sum/10;
            sum=sum%10;
            
            ListNode* newSum = new ListNode(sum);
            temp->next=newSum;
            temp=temp->next;
            
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int sum=l2->val+carry;
            carry = sum/10;
            sum=sum%10;
            
            ListNode* newSum = new ListNode(sum);
            temp->next=newSum;
            temp=temp->next;
            
            l2=l2->next;
        }
        if(carry > 0)
        {
            ListNode* newSum = new ListNode(carry);
            temp->next=newSum;
            temp=temp->next;
        }
        return ansHead->next;
    }
};