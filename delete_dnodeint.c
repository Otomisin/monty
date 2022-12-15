#include "monty.h"
#include <unistd.h>

/**
 * delete_dnodeint_at_index - insert new node with
 * information in position 'index'
 * @head: pointer the init of doubly linked list
 * @index: Position get
 * Return: new node inserted
 */
void delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *copyNode = NULL, *temp = NULL;
	unsigned int countIndex = 0;

	if (*head == NULL)
		return;
	copyNode = *head;
	if (index == 0)
	{
		if ((*head)->next != NULL)
		{
			*head = copyNode->next,	(*head)->prev = NULL, free(copyNode);
		}
		else
		{
			(*head) = NULL;
			free(copyNode);
		}
		return;
	}
	while (copyNode->next)
	{
		if (countIndex + 1 == index)
		{
			if (copyNode->next->next)
			{
				temp = copyNode->next, copyNode->next = copyNode->next->next;
				free(temp), temp = copyNode->next;
				temp->prev = copyNode;
				return;
			}
			else
			{
				temp = copyNode->next, free(temp);
				copyNode->next = NULL;
				return;
			}
		}
		countIndex++, copyNode = copyNode->next;
	}
}
