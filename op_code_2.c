#include "monty.h"

/**
 * op_add - function to add two numbers
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	dataStruct.valDataToSave = 0;
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}
	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * op_sub - function to substract two numbers
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	dataStruct.valDataToSave = 0;
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}
	temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * op_div - function to devide two numbers
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	dataStruct.valDataToSave = 0;
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}
	temp = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * op_mul - function to multiply two numbers
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	dataStruct.valDataToSave = 0;
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}
	temp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * op_mod - function to calculate the module of two numbers
 * @stack: double pointer to a double linked list
 * @line_number: counter of FILE lines.
 * Return: None
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	dataStruct.valDataToSave = 0;
	if (!(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_dlistint(*stack);
		exit(1);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		free_dlistint(*stack);
		exit(1);
	}
	temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
