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
        vector<int>v;
        ListNode * temp = head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
                temp =temp->next;

        }
        for(int i=0;i<(v.size()/2);i++)
        {
            head->val=v[i];
            head= head->next;
            head->val=v[v.size()-i-1];
            head=head->next;

        }
        if(head)
            head->val=v[v.size()/2];
    }
};