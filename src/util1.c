#include "cub3d.h"

char **get_img_data(int width, int height)
{
    int i;
    int size;
    char **tmp;

    i = 0;
    size = height * tile_size;
    if (!(tmp = (char**)malloc((height * tile_size) * sizeof(char*))))
        return (0);
    while (i < size)
    {
        if (!(tmp[i] = (char*)malloc(sizeof(char) * width * tile_size)))
            return (0);
        i++;
    }
    return (tmp);
}

void parse_map(int fd, t_list **lst)
{
    int i;
    char    *line;

    while ((i = get_next_line(fd, &line)) > 0)
    {
        ft_lstadd_back(lst, ft_lstnew((void *)line));
    }
}

int jump_to_map(int fd, t_list **lst)
{
    int     i;
    bool    tf;
    char    *line = 0;

    tf = false;
    while ((i = get_next_line(fd, &line)) > 0)
    {
        if (*line != 0)
        {
            tf = true;
            break ;
        }
        free_buffer(&line);
    }
    if (tf == false)
        return (-1);
    ft_lstadd_back(lst, ft_lstnew((void *)line));
    parse_map(fd, lst);
    return (1);
}

void free_arrs(char **splits)
{
    int i;

    i = 0;
    while (splits[i])
    {
        free_buffer(&splits[i]);
        i++;
    }
    free_buffer(&splits[i]);
    free_buffer(splits);
}

int make_color(char *color, t_color **location)
{
    char **splits;
    int r;
    int g;
    int b;
    t_color *tmp;

    r = 0;
    splits = ft_split(color, ',');
    while (splits[r])
        r++;
    if (r != 3)
        return (-1);
    tmp = (t_color *)malloc(sizeof(struct s_color) * sizeof(char));
    if (!tmp)
        return (-1);
    *location = tmp;
    r = ft_atoi(splits[0]);
    g = ft_atoi(splits[1]);
    b = ft_atoi(splits[2]);
    (*location)->r = r;
    (*location)->g = g;
    (*location)->b = b;
    return (0);
}