#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd;
    char *line;
    int lines;
    lines = 1;
    fd = open("text.txt", O_RDONLY);

    while ((line = get_next_line(fd)))
        printf("%d->%s", lines++, line);
    return 0;
}