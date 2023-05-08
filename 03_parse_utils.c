#include "cub3d.h"

int ft_cub(char *argv)
{
    int i;

    i = 0;
    while (argv && argv[i])
    {
        if (argv[i] == '.' && argv[i + 1] == 'c' && argv[i + 2] == 'u' &&
            argv[i + 3] == 'b' && argv[i + 4] == '\0')
        {
            return (SUCCESS);
        }
        i++;
    }
    printf("The file does not end with .cub\n");
    return (FAIL);
}