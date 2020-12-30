#include "cub3d.h"

void set_t_point(double x1, double y1, double x2, double y2)
{
    p1.x = x1;
    p1.y = y1;
    p2.x = x2;
    p2.y = y2;
}

int get_color(int r, int g, int b)
{
    int color;
    int color2;

    color = (b) + (r<<16) + (g<<8);
    color2 = mlx_get_color_value(game.mlx,color);
    return (color2);
}

void set_color(unsigned char *dp, int color)
{
    int i;

    i = 4;
    while (i--)
        *(dp + i) = ((unsigned char *)(&color))[i];
}

int get_calc_index(int x, int y)
{
    int index;

    index = 0;
    index = (y) * game.img->size_line;
    index = index + (x * (game.img->bpp / 8));
    return (index);
}

void draw_line(t_game game, t_point *p1, t_point *p2, int color)
{
    double dx;
    double dy;
    double step;

    dx = p2->x - p1->x;
    dy = p2->y - p1->y;
    if (fabs(dx) > fabs(dy))
        step = abs(dx);
    else
        step = abs(dy);
    dx = dx / step;
    dy = dy / step;
    while (fabs(p2->x - p1->x) > 0.0001 || fabs(p2->y - p1->y) > 0.0001)
    {
        set_color((unsigned char *)&game.img->data[get_calc_index((int)(p1->x), (int)(p1->y))], color);
        p1->x = p1->x + dx;
        p1->y = p1->y + dy;
    }
}

