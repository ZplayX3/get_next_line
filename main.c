#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd = open(av[1], O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
