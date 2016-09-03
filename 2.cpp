/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = l1->val + l2->val;
        int r = c / 10;
        ListNode *ans = new ListNode(c % 10);
        ListNode *p1 = l1->next, *p2 = l2->next, *pans = ans;
        while(p1 != nullptr || p2 != nullptr)
        {
			if(p1 != nullptr && p2 != nullptr)
            {
				c = p1->val + p2->val + r;
            	r = c / 10;
				p1 = p1->next;
	            p2 = p2->next;
			}
			else if(p1 != nullptr)
			{
				c = p1->val + r;
	            r = c / 10;
				p1 = p1->next;
			}
			else
			{
				c = p2->val + r;
	            r = c / 10;
				p2 = p2->next;
			}
            pans->next = new ListNode(c % 10);
            pans = pans->next;
        }
        if(r)
            pans->next = new ListNode(r);
        return ans;
    }
};
