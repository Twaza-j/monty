#include "monty.h"

/**
 * push - Adds the integer to the stack
 * @stack: A pointer to a pointer to the stack
 * @line_number: Number of line where the interpreter been
 * @value: Value of integer to push
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	(void)line_number;

	if (new_node == NULL)
		err(4, NULL, NULL, NULL, NULL, 0);
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Print all elements in the stack
 * @stack: A pointer to a pointer to the stack
 * @line_number: Number of line where the interpreter been
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: A pointer to a pointer to the stack
 * @line_number: Number of line
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		err(6, NULL, *stack, NULL, NULL, line_number);

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: A pointer to a pointer to the stack
 * @line_number: Number of line where the interpreter been
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
		err(7, NULL, *stack, NULL, NULL, line_number);

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: The stack
 * @line_number: The line number inside opcode file
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_ptr;
	unsigned int len = 0;
	int temp_n;

	temp_ptr = *stack;
	while (temp_ptr != NULL)
	{
		temp_ptr = temp_ptr->next;
		len++;
	}

	if (len < 2)
		err(8, NULL, *stack, NULL, NULL, line_number);

	temp_n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_n;
}
