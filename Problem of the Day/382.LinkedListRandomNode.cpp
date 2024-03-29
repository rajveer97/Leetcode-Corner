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
    ListNode* head = NULL;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode* p = head;
        int i = 1;
        int ans;

        while(p) {
            if(rand() % i == 0) {
                ans = p->val;
            } 
            i++;
            p = p->next;
        }

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */