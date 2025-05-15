#include "get_next_line.h"
#include <stdio.h>   // printf()
#include <fcntl.h>    // open()
#include <unistd.h>   // read(), write(), close()


int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return (1);
    }

    line = get_next_line(fd);
    while (line)
    {
        printf("=>%s\n", line);
        free(line);
        line = get_next_line(fd);
    }

    close(fd);
    return (0);
}
