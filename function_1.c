#include "monty.h"
/**
 * add_to_stack - creates a new node at the beginning of the list
 * @head: first node
 * @n: number to add
 * Return: new added node
 */
stack_t *head = NULL;
stack_t *add_to_stack(const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = head;
	new->prev = NULL;
	if (head != NULL)
		(head)->prev = new;
	head = new;
	return (new);
}
/**
 * print_all - prints all elements in the list
 * @h: first node
 * Return: number of printed nodes
 */
size_t print_all(void)
{
	int printed;

	for (printed = 0; head; printed++)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
	return (printed);
}
/**
 *_strcmp - will compare two strings
 *@s1: first string to compare
 *@s2: second string to check
 *Return: 1 if true else 0;
 */
int _strcmp(char *s1, char *s2)
{
	int ret;

	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		ret = 0;
	else
		ret = *s1 - *s2;
	return (ret);
}
/**
 * _realloc - resizes the size of pre allocated pointer
 * @ptr: address to resize
 * @size: size to put the ptr to
 * Return: pointer t newly acated memory
 */
void *_realloc(void *ptr, size_t size)
{
	size_t new_s;
	void *cpy;

	if (size == 0)
		free(ptr);
	else
	{
		cpy = malloc(sizeof(char) * size);
		if (size > malloc_usable_size(ptr))
			new_s = malloc_usable_size(ptr);
		memcpy(cpy, ptr, new_s);
		free(ptr);
	}
	return (cpy);
}
