/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
}*temp = NULL, *atemp = NULL;

void sll_012_sort(struct node *head)
{
	int *count = (int*)malloc(sizeof(int) * 3);
	int i = 0;

	if (head == NULL)
		return;

	temp = head;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;

	while (temp != NULL)
	{
		count[temp->data] = count[temp->data] + 1;
		temp = temp->next;
	}

	temp = head;

	while (temp != NULL)
	{
		if (count[i] == 0)
			i++;
		else
		{
			temp->data = i;
			count[i]--;
			temp = temp->next;
		}
	}
}