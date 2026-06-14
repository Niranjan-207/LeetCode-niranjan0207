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
        deque<int> dq;
        ListNode* p=head;
        while(p){
            dq.push_back(p->val);
            p=p->next;
        }

        int ans=0;
        while(!dq.empty()){
            int f=dq.front();
            int l=dq.back();
            dq.pop_back();dq.pop_front();
            ans=max(ans,f+l);
        }
        return ans;
    }
};