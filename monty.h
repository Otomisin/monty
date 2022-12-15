#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct global_s - doubly linked list representation of a stack (or queue)
 * @dataToSave: data to strack or queue
 * *@lineTokenized: Data extract from FILE
 * @valDataToSave: Boolean validator
 * @opCodeNoExist: command no exist
 *
 * Description: struct to save global info
 */
typedef struct global_s
{
	int dataToSave;
	char *lineTokenized;
	int valDataToSave;
	char *opCodeNoExist;
} global_t;

extern global_t dataStruct;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void op_push(stack_t **stack, unsigned int line_number);

void op_pall(stack_t **stack, unsigned int line_number);

void op_pop(stack_t **stack, unsigned int line_number);

void op_pint(stack_t **stack, unsigned int line_number);

void op_swap(stack_t **stack, unsigned int line_number);

void op_add(stack_t **stack, unsigned int line_number);

void op_sub(stack_t **stack, unsigned int line_number);

void op_div(stack_t **stack, unsigned int line_number);

void op_mul(stack_t **stack, unsigned int line_number);

void op_mod(stack_t **stack, unsigned int line_number);

void op_pchar(stack_t **stack, unsigned int line_number);

void op_pstr(stack_t **stack, unsigned int line_number);

void op_none(stack_t **stack, unsigned int line_number);

void op_rotl(stack_t **stack, unsigned int line_number);

void (*get_op_code())(stack_t **stack, unsigned int line);

int digit_check(char *key);

void tokenize_line(char *line, char **tokenize);

void change_last_character(char *valueTokenize);

void add_dnodeint(stack_t **head, int n);

void delete_dnodeint_at_index(stack_t **head, unsigned int index);

void free_dlistint(stack_t *head);

#endif /* MONTY_H */
