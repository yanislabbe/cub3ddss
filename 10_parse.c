#include "cub3d.h"

int			tinder(char *str)
{
	int i;

	i = 0;
	if (str && str[i])
	{
		if (str[i] == 'R' && str[i + 1] == ' ')
			return (1);
		else if (str[i] == 'N' && str[i + 1] == 'O')
			return (2);
		else if (str[i] == 'S' && str[i + 1] == 'O')
			return (3);
		else if (str[i] == 'W' && str[i + 1] == 'E')
			return (4);
		else if (str[i] == 'E' && str[i + 1] == 'A')
			return (5);
		else if (str[i] == 'F' && str[i + 1] == ' ')
			return (7);
		else if (str[i] == 'C' && str[i + 1] == ' ')
			return (8);
		else if (is_non_map_char(str[i]) == 1)
			return (9);
	}
	return (0);
}

int			is_double(int a)
{
	if (a == 1 || a == 2)
		return (2);
	return (1);
}

t_parse	*init_struct(t_parse *parse)
{
	parse->north = 0;
	parse->south = 0;
	parse->west = 0;
	parse->east = 0;
	parse->floor = 0;
	parse->ceiling = 0;
	parse->map_wg_char = 0;
	parse->map_end = 0;
	parse->map_wall = 0;
	parse->map_dup = 0;
	parse->map_no_pos = 0;
	parse->no_map = 0;
	parse->wrong_line = 0;
	return (parse);
}

int	ft_wall(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
	{
		i++;
	}
	while (str && str[i] && str[i] == '1')
	{
		i++;
	}
	if (str && str[i] == '\0')
	{
		return (0);
	}
	return (1);
}

int	ft_is_a_wall_around(char *str)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
	{
		i++;
	}
	if (str && str[i] && str[i] != '1')
	{
		return (1);
	}
	while (str && str[i])
	{
		i++;
	}
	i--;
	if (str && str[i] != '1')
	{
		return (1);
	}
	return (0);
}

void    ft_all_parse(t_parse *parse)
{
    printf("\nTous ce que parse contient:\n");
    printf("parse->north = %d\n", parse->north);
    printf("parse->south = %d\n", parse->south);
    printf("parse->west = %d\n", parse->west);
    printf("parse->east = %d\n", parse->east);
    printf("parse->floor = %d\n", parse->floor);
    printf("parse->map_wg_char = %d\n", parse->map_wg_char);
    printf("parse->map_end = %d\n", parse->map_end);
    printf("parse->map_wall = %d\n", parse->map_wall);
    printf("parse->map_dup = %d\n", parse->map_dup);
    printf("parse->map_no_pow = %d\n", parse->map_no_pos);
    printf("parse->no_map = %d\n", parse->no_map);
    printf("parse->wrong_line = %d\n\n", parse->wrong_line);
}

int	ft_parsing(char **tab)
{
	t_parse	*parse;
	char		**data;
	char		**map;

	if (!(parse = malloc(sizeof(t_parse))))
	{
		return (0);
	}
	if (!(data = malloc(sizeof(char *) * 9)))
	{
		return (0);
	}
	parse = init_struct(parse);
	parse = get_error(parse, tab, 0);
	data = ft_add_value_to_data(tab, parse, data, 0);
	map = ft_add_to_map(tab);
	parse = check_error(data, parse);
	parse = ft_parse_map(map, parse, 0, 0);
	print_error(parse);
	map = ft_free_tab(map);
	data = ft_free_tab(data);
	ft_all_parse(parse); 	// sdkjgslgdklshfglsdlgksh sdlkghdlskghdlkshgklsdhghsglksdhlgk
	if (ft_error(parse) == 1)
	{
		free(parse);
		return (1);
	}
	free(parse);
	return (0);
}