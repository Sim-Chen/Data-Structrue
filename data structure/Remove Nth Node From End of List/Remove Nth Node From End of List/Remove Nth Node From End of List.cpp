/*
*Given a linked list, remove the nth node from the end of list and return its head.
*For example:
*Given linked list: 1->2->3->4->5, and n = 2.
*After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

#include<iostream>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode** t1 = &head, *t2 = head;
		for (int i = 1; i < n; ++i)
		{
			t2 = t2->next;
		}
		while (t2->next != NULL)
		{
			t1 = &((*t1)->next);
			t2 = t2->next;
		}
		*t1 = (*t1)->next;
		return head;
	}
};



int main()
{
	
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	ListNode *p = head;
	head->val = 1;
	head->next = NULL;
	for (size_t i = 0; i < 1; i++)
	{
		ListNode *node = (ListNode *)malloc(sizeof(ListNode));
		node->val = i+1;
		node->next = NULL;
		p->next = node;
		p = p->next;

		
	}
	Solution s;
	ListNode *newhead= s.removeNthFromEnd(head, 1);


	cout << "OK" << endl;
	return 0;
}