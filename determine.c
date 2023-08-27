#include "monty.h"
/**
 *form - will determine the functin t use accrding to the specs
 *@check: character to look for
 * Return: pointer to a functions that does the job
 */
size_t (*form(char *check))(void)
{
	int i;

	mi_funct array[] = {{"pall", print_all},
		{"pint", print_all},
		/*{"pop", remove},
		{"swap", swap},
		{"add", add},
		{"nop", nothing}*/};

	for (i = 0; array[i].spec; i++)
	{
		if (_strcmp(array[i].spec, check) == 0)
		{
			return ((array[i].func));
		}
	}
	return (NULL);
}
