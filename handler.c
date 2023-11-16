#include "monty.h"

/**
 * err - Custom error handling function
 * @error_code: Error code to determine the type of error
 * @...: Variable arguments depending on the error_code
 *
 * Return: Nothing (exits with EXIT_FAILURE)
 */
void err(int error_code, char *line, stack_t *stack, FILE *file, char *reason, int ln)
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