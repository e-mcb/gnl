// char    *get_next_line(int fd)

#include "get_next_line.h"
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <type_traits>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}



char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*cpy;

	i = 0;
	len = ft_strlen(s);
	cpy = (char *)malloc(len + 1);
	if (!cpy)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}



char    *get_next_line(int fd)
{

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) <= 0)
        return (NULL);
    
}

int    fnd_nline(char *str)
{

}

char    *reading(int fd)
{
    char    *storage;
    char    buf[BUFFER_SIZE + 1];

    read(fd, buf, BUFFER_SIZE);
    buf[BUFFER_SIZE] = 0;
    storage = ft_strdup(buf);
    if (!storage)
        return (NULL);
    while (read(fd, buf, BUFFER_SIZE) != 0)
    {
        if (fnd_nline != 0)
            //return the line
            // clean the storage
        storage = ft_strjoin(storage, buf);
    }

}



