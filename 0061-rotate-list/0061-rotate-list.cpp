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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next==nullptr)   return head;
        int len=0;
        ListNode* p=head;
        ListNode* last=head;
        while(p!=nullptr){
            p=p->next;
            len++;
            if(last->next!=nullptr) last=last->next;
        }
        k=k%len;
        if(k==0)    return head;
        ListNode* nlast=head;
        for(int i=1;i<(len-k);i++){
            nlast=nlast->next;
            //cout<<nlast->val<<" ";
        }
        ListNode* nhead=nlast->next;
        nlast->next=nullptr;
        last->next=head;

        return nhead;
    }
};