#include "get_next_line.h"

int	ft_is_in(char c, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	static int	index = 0;
	ssize_t		ret;
	char		*dest;

	dest = NULL;

	ret = read(fd, buffer, BUFFER_SIZE);
	while (!ft_is_in('\n', buffer))
	{
		dest = ft_strjoin(dest, buffer);
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	dest = ft_strnjoin(dest, buffer, ft_is_in('\n', buffer));
	return(dest)
}
