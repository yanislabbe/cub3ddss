#include "cub3d.h"

int	ft_unwanted_character(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] != '1' && str[i] != '0' && str[i] != 'N' &&
			str[i] != 'W' && str[i] != 'E' && str[i] != 'S' && str[i] != ' ')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

t_parse	*ft_parse_map_continue(t_parse *parse, int dup, char *str)
{
	if (dup > 1)
	{
		parse->map_dup = 1;
	}
	if (dup == 0)
	{
		parse->map_no_pos = 1;
	}
	if (str != 0)
	{
		parse->map_end = 1;
	}
	return (parse);
}

t_parse	*ft_parse_map(char **map, t_parse *parse, int i, int dup)
{
	if (map[0] == 0)
	{
		parse->no_map = 1;
	}
	else
	{
		while (map && map[i] && ft_space(map[i]) == 1)
		{
			if ((i == 0 && ft_wall(map[i]) == 1) || ft_is_a_wall_around(map[i]) == 1)
			{
				parse->map_wall = 1;
			}
			if (map[i + 1] == 0)
			{
				if (ft_wall(map[i]) == 1)
				{
					parse->map_wall = 1;
				}
			}
			if (i > 0 && map[i + 1] != 0 && check_string_position(map[i - 1], map[i], map[i + 1]) == 1)
			{
				parse->map_wall = 1;
			}
			if (ft_unwanted_character(map[i]) == 1)
			{
				parse->map_wg_char = 1;
			}
			if (check_orientation(map[i]) > 0)
			{
				dup = dup + check_orientation(map[i]);
			}
			i++;
		}
		parse = ft_parse_map_continue(parse, dup, map[i]);
	}
	return (parse);
}