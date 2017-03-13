/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
#include <iostream>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution 
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{ 
		ListNode* L=new ListNode(0);
		int carry=0;
		ListNode * current=L;
		while (l1||l2)
		{
			int x=(l1!=NULL)?l1->val:0;
			int y=(l2!=NULL)?l2->val:0;
			int sum=x+y+carry;
			carry=sum/10;
			current->next=new ListNode(sum%10);
			current=current->next;
			if(l1!=NULL) l1=l1->next;
			if(l2!=NULL) l2=l2->next;
		
		}
		if (carry>0)
		{
			ListNode *node=new ListNode(carry);
			current->next=node;
		}
			return L->next;

		
	}
};