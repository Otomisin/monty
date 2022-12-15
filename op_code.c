#include "monty.h"

/**
 * op_push - add new node to linked list
 * @stack: double pointer to a double linked list
 * @line_number: Counter of FILE lines.
 * Return: Returnless
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	if (dataStruct.valDataToSave)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}

	add_dnodeint(stack, dataStruct.dataToSave);
	dataStruct.valDataToSave = 0;
}

/**
 * op_pall - print a linked list
 * @stack: double pointer to a double linked list
 * @line_number: Counter of FILE lines.
 * Return: Returnless
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *copyHead = NULL;
	(void)line_number;
	dataStruct.valDataToSave = 0;

	if (*stack)
	{
		copyHead = *stack;
		while (copyHead)
		{
			printf("%d\n", copyHead->n);
			copyHead = copyHead->next;
		}
	}
}

/**
 * op_pint - print node in top
 * @stack: double pointer to a double linked list
 * @line_number: Counter of FILE lines.
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *copyHead = NULL;

	dataStruct.valDataToSave = 0;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}
	copyHead = *stack;
	while (copyHead)
	{
		printf("%d\n", copyHead->n);
		break;
	}
}

/**
 * op_pop - delete node in top
 * @stack: double pointer to a double linked list
 * @line_number: Counter of FILE lines.
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	dataStruct.valDataToSave = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
 * op_swap - swap the 2 nodes in top
 * @stack: double pointer to a double linked list
 * @line_number: Counter of FILE lines.
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *copyHead = NULL;
	stack_t *temp = NULL;

	dataStruct.valDataToSave = 0;
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(1);
	}

	copyHead = *stack;
	temp = copyHead->next;

	copyHead->next = copyHead->next->next;
	copyHead->prev = copyHead->next->prev;
	temp->next = copyHead;
	temp->prev = NULL;
	*stack = temp;
}
