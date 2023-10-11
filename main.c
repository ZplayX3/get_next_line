#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	fd;
	char	*res;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	while ((res = get_next_line(fd)))
	{ 
		printf("%s\n", res);
		free(res);
	}
	printf("buffer size =%d", BUFFER_SIZE);
	return (0);
}
