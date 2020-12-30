#include "cub3d.h"

int     check_complete()
{
    if (md.width != 0 && md.height != 0 && md.north != 0 && md.south != 0
    && md.west != 0 && md.east != 0 && md.sprite != 0 && md.f != 0 && md.c != 0)
        return (1);
    return (-1);
}

int    set_data(char *line)
{
    char **splits;

    splits = ft_split(line, ' ');
    if (*splits == 0)
    {
        free_arrs(splits);
        return (0);
    }
    else
    {
        if(set_env_data(splits) == -1)
        {
            free_arrs(splits);
            return (-1);
        }
    }
    free_arrs(splits);
    return (1);
}
/*   
 *    parse_data is parse map data 
 *    and end roop data is end
 *    ex) P, EA, WE, NO, SO, S, F, C ...
 */
int parse_data(int fd)
{
    int     i;
    char    *line = 0;

    while ((i = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        if(set_data(line) == -1)
        {
            free_buffer(&line);
            return (-1);
        }
        if (check_complete() == 1)
        {
            free_buffer(&line);
            return (1);
        }
        free_buffer(&line);
    }
    return (-1);
}

int cub_parse(int fd)
{
    t_list *lst;

    lst = 0;
    if (parse_data(fd) == -1)
        return (-1);
    if (jump_to_map(fd, &lst) == -1)
        return (-1);
    if ((game.map = map_valid_test(lst)) == 0)
        return (-1);
    
    return (0);
}