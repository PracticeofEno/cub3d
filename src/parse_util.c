#include "cub3d.h"

static int splits_length(char **splits)
{
    int i;
    
    i = 0;
    while (splits[i])
        i++;
    return (i);
}

static int try_r(char **splits)
{
    int arr_length;
    int width;
    int height;

    arr_length = splits_length(splits);
    if(arr_length != 3)
        return (-1);
    width = ft_atoi(splits[1]);
    height = ft_atoi(splits[2]);
    if (width == 0 || height == 0)
        return (-1);
    md.width = width;
    md.height = height;
    return (0);
}

static int try_texture(char **splits)
{
    int arr_length;

    arr_length = splits_length(splits);
    if (arr_length != 2)
        return (-1);
    if (ft_strcmp(splits[0], "NO") == 0)
        md.north = ft_strdup(splits[1]);
    else if(ft_strcmp(splits[0], "SO") == 0)
        md.south = ft_strdup(splits[1]);
    else if(ft_strcmp(splits[0], "WE") == 0)
        md.west = ft_strdup(splits[1]);
    else if(ft_strcmp(splits[0], "EA") == 0)
        md.east = ft_strdup(splits[1]);
    else if(ft_strcmp(splits[0], "S") == 0)
        md.sprite = ft_strdup(splits[1]);
    else if(ft_strcmp(splits[0], "F") == 0)
        md.south = ft_strdup(splits[1]);
     else if(ft_strcmp(splits[0], "C") == 0)
        md.south = ft_strdup(splits[1]);
    return (0);
}

static int try_color(char **splits)
{
    int arr_length;

    arr_length = splits_length(splits);
    if (arr_length != 2)
        return (-1);
    
    if(ft_strcmp(splits[0], "F") == 0)
        return (make_color(splits[1], &md.f));
    else if(ft_strcmp(splits[0], "C") == 0)
        return (make_color(splits[1], &md.c));
    return (0);
}

int set_env_data(char **splits)
{
    if(ft_strcmp(splits[0], "R") == 0)
        return (try_r(splits));
    else if(ft_strcmp(splits[0], "NO") == 0)
        return (try_texture(splits));
    else if(ft_strcmp(splits[0], "SO") == 0)
        return (try_texture(splits));
    else if(ft_strcmp(splits[0], "WE") == 0)
        return (try_texture(splits));
    else if(ft_strcmp(splits[0], "EA") == 0)
        return (try_texture(splits));
    else if(ft_strcmp(splits[0], "S") == 0)
        return (try_texture(splits));
    else if(ft_strcmp(splits[0], "F") == 0)
        return (try_color(splits));
    else if(ft_strcmp(splits[0], "C") == 0)
        return (try_color(splits));
    return (0);
}