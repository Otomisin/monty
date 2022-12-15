#include "monty.h"

/**
 * add_dnodeint - Create new node of struct stack_t.
 * @head: double pointer
 * @n: number a save in new node.
 * Return: Pointer a new node.
 */
void add_dnodeint(stack_t **head, int n)
{
	stack_t *newNode;

	if (!head)
		return;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed");
		free_dlistint(*head);
		exit(1);
	}
	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;

	if (*head)
		(*head)->prev = newNode;

	*head = newNode;
}
