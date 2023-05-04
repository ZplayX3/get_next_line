#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	static int	index = 0;
	ssize_t		ret;
	char		*dest;

	ret = read(fd, buffer, BUFFER_SIZE);

}
