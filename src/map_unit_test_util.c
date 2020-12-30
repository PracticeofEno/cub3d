#include "cub3d.h"

int up_test(int i, int j)
{
    while (i >= 0)
    {
        if (map[i][j] == '1')
            return (0);
        i--;
    }
    return (-1);
}

int down_test(int i, int j, int height)
{
    while (i < height)
    {
        if (map[i][j] == '1')
            return (0);
        i++;
    }
    return (-1);
}

int left_test(int i, int j)
{
    while (j >= 0)
    {
        if (map[i][j] == '1')
            return (0);
        j--;
    }
    return (-1);
}

int right_test(int i, int j, int width)
{
    while (j <= width)
    {
        if (map[i][j] == '1')
            return (0);
        j++;
    }
    return (-1);
}

int uni_test(int i, int j, int width, int height)
{
    if (up_test(i, j) == -1)
        return (-1);
    if (down_test(i, j, height) == -1)
        return (-1);
    if (left_test(i, j) == -1)
        return (-1);
    if (right_test(i, j, width) == -1)
        return (-1);
    return (0);   
}