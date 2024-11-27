#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
# ifndef MAX_FD
#  define MAX_FD 256
# endif
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char *get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif