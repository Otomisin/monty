#include "monty.h"

/**
 * op_pchar - function to print the character on top of the list
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	dataStruct.valDataToSave = 0;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * op_pstr - function to print a string
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{

	stack_t *copyHead = NULL;
	(void)line_number;
	dataStruct.valDataToSave = 0;

	if ((*stack))
		copyHead = *stack;
	while (copyHead)
	{
		if (copyHead->n >= 0 && copyHead->n <= 127)
		{
			printf("%c", copyHead->n);
		}
		if (!copyHead->next || copyHead->next->n == 0 ||
		copyHead->next->n < 0 || copyHead->next->n > 127)
		{
			break;
		}
		copyHead = copyHead->next;
	}
	printf("\n");
}

/**
 * op_none - Nothing
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_none(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	dataStruct.valDataToSave = 0;
}

/**
 * op_rotl - round the top to a bottom
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *temp2 = NULL;

	if ((*stack)->next)
	{
		dataStruct.valDataToSave = 0;
		(void)line_number;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		temp2 = *stack;

		while (temp2->next)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp;
		temp->prev = temp2;
		temp->next = NULL;
	}
}
