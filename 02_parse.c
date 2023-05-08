#include "cub3d.h"

void    ft_all_data(t_data *data)
{
    printf("\nTous ce que data contient:\n");
    printf("data->x = %d\n", data->x);
    printf("data->y = %d\n", data->y);
    printf("data->north = %s\n", data->north);
    printf("data->south = %s\n", data->south);
    printf("data->west = %s\n", data->west);
    printf("data->east = %s\n", data->east);
    printf("data->floor = %s\n", data->floor);
    printf("data->ceiling = %s\n\n", data->ceiling);
}

void print_map(char **map) {
    int i, j;

    for (i = 0; map[i] != NULL; i++) {
        for (j = 0; map[i][j] != '\0'; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int ft_fd_cub(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        printf("Error! The fd is problematic\n");
        return (-1);
    }
    else if (ft_cub(file) == 1)
        return (-1);
    return (fd);
}

int ft_parse_file(char *filename, char ***tab_ptr)
{
    char    **tab;
    char    *line;
    int     fd;
    int     i;

    line = NULL;
    i = 0;
    fd = ft_fd_cub(filename);
    if (fd == -1)
        return (fd);
    tab = malloc(sizeof(char *) * 100);
    if (!tab)
        return (FAIL);
    while (get_next_line(fd, &line) == 1)
    {
        tab[i] = ft_pstrdup(line, '\0');
        free(line);
        i++;
    }
    tab[i] = 0;
    free(line);
    *tab_ptr = tab;
    close(fd);
    return (SUCCESS);
}

int ft_parse(char **argv)
{
    t_data  *data;
    char    **tab;
    int     ret;

    ret = ft_parse_file(argv[1], &tab);
    if (ret != SUCCESS)
        return (ret);
    if (ft_parsing(tab) == 1)
    {
        tab = ft_free_tab(tab);
        return (FAIL);
    }
    data = malloc(sizeof(t_data));
    if (!data)
    {
        tab = ft_free_tab(tab);
        return (FAIL);
    }
    data = ft_add_to_data(data, tab, 0);
    ft_all_data(data); // print je leak c normal jtun debuguer
    print_map(data->map); // print je leak c normal jtun debuguer
    tab = ft_free_tab(tab);
    ft_free_data(data);
    return (SUCCESS);
}
