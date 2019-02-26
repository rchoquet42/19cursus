#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char **line;
	char *temp = NULL;

	argc = 0;

	line = &temp;
//	int fd = open(argv[1], O_RDONLY);

	while (get_next_line(0, line) > 0)
	{
		printf("%s\n", *line);
		free(*line);
	}

	return (0);

}
