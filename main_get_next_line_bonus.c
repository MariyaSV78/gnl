#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (int args, char *argws[])
{
	int fd[args-1];
	char *line;
	int N_files = 0;

	if (args == 1)
		fd[N_files++] = open("my_file_poeme.txt", O_RDONLY);
	else
	{
		for (; N_files < args - 1; N_files++)
		{
			fd[N_files] = open(argws[N_files + 1], O_RDONLY);
		}
	}
	for (int i=0; i < N_files; i++)
		if (!fd[i]) // открытие файла
		{
			perror("Error occured while opening file");
			return 1;
		}

	int i_str = 1, ret_all;
	while (1)
	{
		ret_all = 1;
		for(int i=0; i < N_files; i++)
		{
			line = get_next_line(fd[i]);
			if (!line)
				continue;
			printf ("fd=%i (%i): \"%s\"", i, i_str, line);
			printf ("\n");
			ret_all = 0;
		}
		i_str++;
		if (ret_all)
			break;
	}
	for(int i=0; i < N_files; i++)
		close(fd[i]);
	return (0);
}

