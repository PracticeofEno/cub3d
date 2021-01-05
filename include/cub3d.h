#ifndef CUB3D_H
# define CUB3D_H
# define PI 3.141592653589

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"

typedef struct s_color
{
    int r;
    int g;
    int b;
}               t_color;

typedef struct s_point
{
    double x;
    double y;
    bool wall_hit;
}               t_point;

typedef struct s_ray
{
    double angle;
    t_point hit;
    double distance;
    bool    hit_tf;

}               t_ray;

typedef struct s_game
{
    void *mlx;
    void *mlx2;
    void *win;
    void *win2;
    t_img *img;
    t_img *img2;
    char **map;
}               t_game;

typedef struct s_direction
{
    t_img *no;
    int no_w;
    int no_h;
    t_img *we;
    int we_w;
    int we_h;
    t_img *so;
    int so_w;
    int so_h;
    t_img *ea;
    int ea_w;
    int ea_h;
    t_img *item;
    int item_w;
    int item_h;
}               t_direction;

typedef struct s_map_data
{
    int width;
    int height;

    char *north;
    char *south;
    char *west;
    char *east;
    char *sprite; 
    struct s_color *f;
    struct s_color *c;
}               t_map_data;

typedef struct s_player
{
    double x;
    double y;
    double radius;
    double turn_direction;
    double walk_direction;
    double rotation_angle;
    double move_speed;
    double rotation_speed;
}               t_player;

t_game game;
t_direction texture;
t_map_data md;
t_player player;
t_point p1;
t_point p2;
t_ray *rays;

char **map;
int map_height;
int map_width;
double fov_angle;
int wall_strip_width;
int num_rays;
int tile_size;

int cub_parse(int fd);
int set_env_data(char **splits);
int make_color(char *color, t_color **location);
void free_arrs(char **splits);
int jump_to_map(int fd, t_list **lst);
void printf_map(void *string);
void copy_map(char **map, t_list *lst);
char **map_valid_test(t_list *lst);
int check_valid_map();
int uni_test(int i, int j, int width, int height);
int get_color(int r, int g, int b);
void draw_rect(t_game * game, int x, int y, int size);
int render_player(char **map_img);
char **get_img_data(int width, int height);
int cub3d_start();
int mlx_setting();
int setting();
void update();
void render();
void player_setting();
void player_update();
int key_pressed(int key, void *p);
int key_released(int key, void *p);
void draw_2d_map();
void set_color(unsigned char *dp, int color);
void draw_player(t_game *game, int x, int y);
int get_calc_index(int x, int y);
void draw_line(t_game game, t_point *p1, t_point *p2, int color);
void set_t_point(double x1, double y1, double x2, double y2);
void *temp(void *p);
void player_render();
int is_wall(int x, int y);
double normalize_angle(double angle);
void calc_ray();
void cast_ray(double angle, int col_id);
double get_distance(double x1, double y1, double x2, double y2);
void draw_2d_ray();
void draw_3d_ray();
void draw_cols(t_point p1, t_point p2, t_ray ray);
int get_calc_index3(int x, int y);
void norminette_bypass(int col_id, t_point hit_p, double hit_dis, bool hit_tf);
void reset_img();
int texture_check();
void draw_sky(t_point p1, t_point p2);
void draw_land(t_point p1, t_point p2);
void draw_texture(t_point p1, t_point p2, t_ray ray);
t_img *dl_tex(int x, int y, t_ray ray, int index);
t_img *dr_tex(int x, int y, t_ray ray, int index);
t_img *ul_tex(int x, int y, t_ray ray, int index);
t_img *ur_tex(int x, int y, t_ray ray, int index);
int set_angle(char angle);
void    cast_ray_sprite(double angle, int col_id);
void calc_ray_sprite();
#endif