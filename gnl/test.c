#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

// int main(void)
// {
//  int  fd;
//  char *line;
//  int  count;

//  count = 0;
//  fd = open("nls.txt", O_RDONLY);
//  if (fd == -1)
//  {
//   printf("Error opening file");
//   return (1);
//  }
//  while (1)
//  {
//   line = get_next_line(fd);
//   if (line == NULL)
//    break ;
//   count++;
//   printf("[%d]:%s\n", count, line);
//   free(line);
//   line = NULL;
//  }
//  close(fd);
//  return (0);
// }

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("1char.txt", O_RDONLY);
	fd2 = open("random.txt", O_RDONLY);
	fd3 = open("text.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}