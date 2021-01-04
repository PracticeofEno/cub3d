#include "cub3d.h"

int get_calc_index2(int x, int y, t_img *img)
{
    int index;

    index = 0;
    index = (y) * img->size_line;
    index = index + (x * (img->bpp / 8));
    return (index);
}

void set_color2(unsigned char *dp, unsigned char *color)
{
    int i;

    i = 4;
    while (i--)
        *(dp + i) = *(color + i);
}

t_img *dl_tex(int x, int y, t_ray ray, int index)
{
    double mx;
    double my;
    double kx;
    double ky;
    t_img *tex;

    mx = fmod(ray.hit.x, tile_size);
    my = fmod(ray.hit.y, tile_size);
    if (mx == 0)
    {
        tex = texture.we;
        ky = tex->height / p2.y;
        kx = tex->width / tile_size;
        ft_memmove(&game.img2->data[index], &tex->data[get_calc_index2(tex->width - my * kx, (y + (x-x)) * ky, tex)], 4);
        ////set_color2((unsigned char*)&game.img2->data[index], (unsigned char *)&tex->data[get_calc_index2(x * kx, y * ky, tex)]);
    }
    else if (my == 0)
    {
        tex = texture.so;
        ky = tex->height / p2.y;
        kx = tex->width / tile_size;
        ft_memmove(&game.img2->data[index], &tex->data[get_calc_index2(tex->width - mx * kx, y * ky, tex)], 4);
        //set_color2((unsigned char*)&game.img2->data[index], (unsigned char *)&tex->data[get_calc_index2(x * kx, y * ky, tex)]);
    }
    return (0);
}

t_img *dr_tex(int x, int y, t_ray ray, int index)
{
    double mx;
    double my;
    double kx;
    double ky;
    t_img *tex;

    mx = fmod(ray.hit.x, tile_size);
    my = fmod(ray.hit.y, tile_size);
    if (mx == 0)
    {
        tex = texture.ea;
        ky = tex->height / p2.y;
        kx = tex->width / tile_size;
        ft_memmove(&game.img2->data[index], &tex->data[get_calc_index2(my * kx, (y + (x - x)) * ky, tex)], 4);
        //set_color2((unsigned char*)&game.img2->data[index], (unsigned char *)&tex->data[get_calc_index2(x * kx, y * ky, tex)]);
    }
    else if (my == 0)
    {
        tex = texture.so;
        ky = tex->height / p2.y;
        kx = tex->width / tile_size;
        ft_memmove(&game.img2->data[index], &tex->data[get_calc_index2(tex->width - mx * kx, y * ky, tex)], 4);
        //set_color2((unsigned char*)&game.img2->data[index], (unsigned char *)&tex->data[get_calc_index2(x * kx, y * ky, tex)]);
    }
    return (0);
}

t_img *ul_tex(int x, int y, t_ray ray, int index)
{
    double mx;
    double my;
    double kx;
    double ky;
    t_img *tex;

    mx = fmod(ray.hit.x, tile_size);
    my = fmod(ray.hit.y, tile_size);
    if (my == 0)
    {
        tex = texture.no;
        ky = tex->height / p2.y;
        kx = tex->width / tile_size;
        ft_memmove(&game.img2->data[index], &tex->data[get_calc_index2(mx * kx, y * ky, tex)], 4);
        //set_color2((unsigned char*)&game.img2->data[index], (unsigned char *)&tex->data[get_calc_index2(x * kx, y * ky, tex)]);
    }
    else if (mx == 0)
    {
        tex = texture.we;
        ky = tex->height / p2.y;
        kx = tex->width / tile_size;
        ft_memmove(&game.img2->data[index], &tex->data[get_calc_index2(tex->width - my * kx, (y + (x-x)) * ky, tex)], 4);
        //set_color2((unsigned char*)&game.img2->data[index], (unsigned char *)&tex->data[get_calc_index2(x * kx, y * ky, tex)]);
    }
    
    return (0);
}

t_img *ur_tex(int x, int y, t_ray ray, int index)
{
    double mx;
    double my;
    double kx;
    double ky;
    t_img *tex;

    mx = fmod(ray.hit.x, tile_size);
    my = fmod(ray.hit.y, tile_size);
    if (my == 0)
    {
        tex = texture.no;
        ky = tex->height / p2.y;
        kx = tex->width / tile_size;
        ft_memmove(&game.img2->data[index], &tex->data[get_calc_index2(mx * kx, y * ky, tex)], 4);
        //set_color2((unsigned char*)&game.img2->data[index], (unsigned char *)&tex->data[get_calc_index2(x * kx, y * ky, tex)]);
    }
    else if (mx == 0)
    {
        tex = texture.ea;
        ky = tex->height / p2.y;
        kx = tex->width / tile_size;
        ft_memmove(&game.img2->data[index], &tex->data[get_calc_index2(my * kx, (y + (x-x)) * ky, tex)], 4);
        //set_color2((unsigned char*)&game.img2->data[index], (unsigned char *)&tex->data[get_calc_index2(x * kx, y * ky, tex)]);
    }
    return (0);
}