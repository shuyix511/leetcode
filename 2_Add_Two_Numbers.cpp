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
		int cap = 0;
		ListNode* fakehead = new ListNode(-1);
		ListNode* cur = fakehead;
		while (l1 || l2 || cap) {
			int tmp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + cap;
			cap = tmp / 10;
			cur->next = new ListNode(tmp % 10);
			cur = cur->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return fakehead->next;
	}
};