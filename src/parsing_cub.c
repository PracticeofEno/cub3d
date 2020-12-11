#include "cub3d.h"

int cub_parse(int fd)
{
    int     i;
    char    *line = 0;
    
    ft_putnbr(100);
    while ((i = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free_buffer(&line);
    }
    return (0);
}