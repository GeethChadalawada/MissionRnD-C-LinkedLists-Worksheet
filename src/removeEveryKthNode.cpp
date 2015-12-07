/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K)
{
	if (head == NULL || K <= 0)
		return NULL;

	if (K == 1)
		return NULL;

	struct node *temp = head;
	struct node *temp1 = temp->next;
	int i = 0;

	while (temp1 != NULL)
	{
		i++;

		if (i == K - 1)
		{
			i = 0;
			temp->next = temp1->next;

			if (temp1->next != NULL)
			{
				temp = temp1->next;
				temp1 = temp->next;
			}
			else
				temp1 = NULL;
		}
		else
		{
			temp = temp1;
			temp1 = temp1->next;
		}
	}

	return head;
}