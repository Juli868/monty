#include "monty.h"
/**
 * main - is the center of the project
 * @argc: number of arguments passed down
 * @argv: the arguments it's self
 * Return: always 1
 */
int main(int argc, char **argv)
{
	int file, buffer = 1024;
	char *file_name, *commands;
	ssize_t total = 0;
	ssize_t reading;

	if (argc != 2)
	{
		write (2, "USAGE: monty file\n", 30);
			exit(EXIT_FAILURE);
	}
	else
	{
		file_name = malloc(sizeof(char) * strlen(argv[1]));
		file_name = argv[1];
		file = open(file_name, O_RDONLY);
		if (file ==-1)
		{
			write(2,"Error: Can't open file <file>\n",30);
			exit(EXIT_FAILURE);
		}
		else
		{
			while ((reading = read(file, commands + total, buffer - total)) > 0)
			{
				total += reading;
				if (total == buffer)
				{
					buffer *= 2;
					commands = (char *)realloc(commands, buffer);
				}
			}
		}
		close(file);
		free(file_name);
	}
	return (1);
}
