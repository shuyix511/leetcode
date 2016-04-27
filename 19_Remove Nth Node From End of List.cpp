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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || head->next == NULL) {
			return NULL;
		}
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* FakeSlow = dummy;
		ListNode* FakeFast = dummy;

		for (int i = 0; i < n; i++) {
			FakeFast = FakeFast->next;
		}
		while (FakeFast->next) {
			FakeSlow = FakeSlow->next;
			FakeFast = FakeFast->next;
		}
		ListNode* deletenode = FakeSlow->next;
		delete deletenode;
		FakeSlow->next = deletenode->next;
		return dummy->next;
	}
};