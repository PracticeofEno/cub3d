/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_test_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <sanghpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:11:18 by sanghpar          #+#    #+#             */
/*   Updated: 2021/01/04 14:11:20 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int      get_content_width(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == '\t')
            i = i + 3;
        i++;
    }
    return (i);
}

static int      get_map_width(t_list *lst)
{
    int max;
    int size;
    
    max = 0;
    size = 0;
    while (lst)
    {
        size = get_content_width((char *)lst->content);
        if (max < size)
            max = size;
        lst = lst->next;
    }
    if (max == 0)
        return (-1);
    return (max);
}

static int      get_map_height(t_list *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        i++;
        lst = lst->next;
    }
    if (i == 0)
        return (-1);
    return (i);
}

char **map_valid_test(t_list *lst)
{
    int     i;
    
    i = 0;
    map_width = get_map_width(lst);
    map_height = get_map_height(lst);
    if(map_width == -1 && map_height == -1)
        return (0);
    if (!(map = (char**)malloc(sizeof(char *) * map_height)))
        return (0);
    while (i < map_height)
    {
        if (!(map[i] = (char*)malloc(sizeof(char) * map_width)))
            return (0);
        i++;
    }
    copy_map(map, lst);
    if (check_valid_map(map_width, map_height) == -1)
        return (0);
    return (map);
}

int is_wall(int x, int y)
{
    if (x < 0 || x > map_width * tile_size)
        return (1);
    if (y < 0 || y > map_height * tile_size)
        return (1);
    int x1 = floor(x / tile_size);
    int y1 = floor(y / tile_size);
    if (map[y1][x1] == '1')
        return (1);
    else
        return (0);
}
