#include "cub3d.h"

int main(int argc, char** argv)
{
    int fd;

    if (argc != 2)
    {
        printf("arg error\n");
        return (-1);
    }
    else
    {
        if (!(fd = open(argv[1], O_RDONLY)))
        {
            printf("\nError in open\n");
            return (-1);
        }
        if(cub_parse(fd) == -1)
        {
            printf("\nError in parsing\n");
            return (-1);
        }
        //cub3d_start();
    }
    return (0);
}