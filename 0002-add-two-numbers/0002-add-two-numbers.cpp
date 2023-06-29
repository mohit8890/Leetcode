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
     void insertail(ListNode* &head,ListNode* &tail,int digit){
        ListNode* temp=new ListNode(digit);
        if(head==NULL){
            head=temp;
            tail=temp;
        return;
        }else{
            tail->next=temp;
            tail=temp; 
        }
    }
    ListNode* adds(ListNode* l1,ListNode* l2){
        int c=0;
        ListNode* anshead=NULL;
        ListNode* anstail=NULL;

        while(l1!=NULL&&l2!=NULL){
        int sum=c+l1->val+l2->val;
        int digit=sum%10;
        insertail(anshead,anstail,digit);
         c=sum/10;
         l1=l1->next;
         l2=l2->next;
        }
        while(l1!=NULL){
            int sum=c+l1->val;
            int digit=sum%10;
        insertail(anshead,anstail,digit);
        c=sum/10;
        l1=l1->next;
        
        }
        while(l2!=NULL){
            int sum=c+l2->val;
            int digit=sum%10;
        insertail(anshead,anstail,digit);
        c=sum/10;
        
         l2=l2->next;
        }
        while(c!=0){
            int sum=c;
             int digit=sum%10;
        insertail(anshead,anstail,digit);
        c=sum/10;
        }
        return anshead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //rev input linked lis
        ListNode* ans=adds(l1,l2);
        return ans;
    }
};