/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node 
{
	int num;
	struct node *next;
}*newnode = NULL, *head = NULL;

struct node *numberToLinkedList(int N) 
{
	int i = 0;

	head = NULL;

	if (N < 0)
		N = N * (-1);

	if (N == 0)
	{
		head = (struct node*)malloc(sizeof(struct  node));
		head->num = 0;
		head->next = NULL;
	}
	else
	{
		while (N != 0)
		{
			newnode = (struct node*)malloc(sizeof(struct node));

			newnode->num = N % 10;
			newnode->next = NULL;

			N = N / 10;

			if (head == NULL)
				head = newnode;
			else
			{
				newnode->next = head;
				head = newnode;
			}
		}
	}

	return head;
}