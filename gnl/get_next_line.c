// char    *get_next_line(int fd)

#include "get_next_line.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <time.h>
// #include <type_traits>

static char *find_next_line(int fd, char *storage, char *buffer)
{
	char *str;
	ssize_t read_value;

	read_value = 1;
	while (read_value > 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value < 0)
		{
			free(storage);
			return (NULL);
		}
		else if(read_value == 0)
			break ;
		buffer[read_value] = 0;
		if (!storage)
			storage = ft_strdup("");
		str = storage;
		storage = ft_strjoin(str, buffer);
		free (str);
		str = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (storage);
}

static char *check_line(char *buffer)
{
	char *storage;
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != 0)
		i++;
	if (buffer[i] == 0 || buffer[1] == 0)
		return (NULL);
	storage = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (!storage)
	{
		free(storage);
		storage = NULL;
	}
	buffer[i + 1] = 0;
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char *buffer;
	char *next_line;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(storage);
		free(buffer);
		storage = NULL;
		buffer = NULL;
		return (NULL);
	}
	next_line = find_next_line(fd, storage, buffer);
	free(buffer);
	if (!next_line)
		return (NULL);
	storage = check_line(next_line);
	return (next_line);
}




