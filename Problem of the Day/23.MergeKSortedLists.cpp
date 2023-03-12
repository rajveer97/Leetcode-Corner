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

    ListNode* mergelists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode* head;
        if(l1->val <= l2->val) head = l1;
        else head = l2;

        if(l1->val <= l2->val) 
            head->next = mergelists(l1->next, l2);
        else
            head->next = mergelists(l1, l2->next);

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        ListNode* head = lists[0];

        for(int i=1; i<lists.size(); i++) {
            head = mergelists(head, lists[i]);
        }
        return head;
    }
};