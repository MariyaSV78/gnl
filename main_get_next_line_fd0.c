#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>


int main (int args, char *argws[])
{
	FILE *file;
	int fd;
	char *line;

	if (args == 1)
		file = fopen("my_file_poeme.txt", "r");
	else
		file = fopen(argws[1], "r");
	if (!file) // открытие файла
	{
		perror("Error occured while opening file");
		return 1;
	}
	
    //fd = fileno(file);
	fd = 0; // файл дескриптор,
	
	int i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf ("\n%d : |%s|\n", i++, line);
	}
	fclose(file);
	return (0);
}
