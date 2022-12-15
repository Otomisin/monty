#include "monty.h"

/**
 * free_dlistint - free mallocs
 * @head: const with header of linked list.
 * Return: Without Return.
 */
void free_dlistint(stack_t *head)
{
	stack_t *nextNode, *copyHead;

	copyHead = head;
	while (copyHead)
	{
		nextNode = copyHead->next;
		free(copyHead);
		copyHead = nextNode;
	}
}
