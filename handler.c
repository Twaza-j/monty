#include "monty.h"

/**
 * err - Custom error handling function
 * @error_code: Error code to determine the type of error
 * @line: Line from opcode file
 * @stack: The stack
 * @file: The file containing the opcode
 * @reason: Used for print error
 * @ln: Line number
 *
 * Return: Nothing (exits with EXIT_FAILURE)
 */
void err(int error_code, char *line, stack_t *stack,
		FILE *file, char *reason, int ln)
{
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", reason);
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, reason);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
			break;
		case 8:
			fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
			break;
		case 9:
			fprintf(stderr, "L%d: can't add, stack too short\n", ln);
			break;
		case 10:
			fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
			break;
		case  11:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
			break;
		default:
			break;
	}
	clean(line, stack, file);
	exit(EXIT_FAILURE);
}

/**
 * arr_handle_more - Handles more errors
 * @error_code: Error code to determine the type of error
 * @line: Line from opcode file
 * @stack: The stack
 * @file: The file containing the opcode
 * @reason: Used for print error
 * @ln: Line number
 *
 * Return: Nothing (exits with EXIT_FAILURE)
 */
void err_handle_more(int error_code, char *line, stack_t *stack,
		FILE *file, char *reason, int ln)
{
	(void)reason;

	switch (error_code)
	{
		case 11:
			fprintf(stderr, "L%d: can't div, stack too short\n", ln);
			break;
		case 12:
			fprintf(stderr, "L%d: division by zero\n", ln);
			break;
		case 13:
			fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
			break;
		case 14:
			fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
			break;
		case 15:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
			break;
		case 16:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
			break;
		default:
			break;
	}
	clean(line, stack, file);
	exit(EXIT_FAILURE);
}

/**
* clean - Handles memory leak and file closing
* @line: Line of opcode
* @stack: The stack
* @file: The file
*
* Return: Nothing
*/
void clean(char *line, stack_t *stack, FILE *file)
{
	if (line != NULL)
		free(line), line = NULL;

	if (stack != NULL)
		free_stack(stack);

	if (file != NULL)
		fclose(file), file = NULL;
}

/**
 * free_stack - Frees the stack
 * @stack: A pointer to a pointer to the stack
 *
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
