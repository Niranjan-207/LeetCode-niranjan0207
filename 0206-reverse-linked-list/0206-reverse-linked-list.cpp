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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)    return head;

        ListNode* p=nullptr;
        ListNode* cur=head;
        ListNode* n=nullptr;

        while(cur!=nullptr){
            n=cur->next;
            cur->next=p;
            p=cur;
            cur=n;
        }
        return p;
    }
};