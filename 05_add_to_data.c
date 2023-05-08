#include "cub3d.h"

char	**ft_add_value_to_data(char **tab, t_parse *parse, char **data, int i)
{
	int	k;

	k = 0;
	while (tab[i])
	{
		if (tinder(tab[i]) == 2 && parse->north == 1)
		{
			data[k++] = ft_pstrdup(tab[i], '\0');
		}
		else if (tinder(tab[i]) == 3 && parse->south == 1)
		{
			data[k++] = ft_pstrdup(tab[i], '\0');
		}
		else if (tinder(tab[i]) == 4 && parse->west == 1)
		{
			data[k++] = ft_pstrdup(tab[i], '\0');
		}
		else if (tinder(tab[i]) == 5 && parse->east == 1)
		{
			data[k++] = ft_pstrdup(tab[i], '\0');
		}
		else if (tinder(tab[i]) == 7 && parse->floor == 1)
		{
			data[k++] = ft_pstrdup(tab[i], '\0');
		}
		else if (tinder(tab[i]) == 8 && parse->ceiling == 1)
		{
			data[k++] = ft_pstrdup(tab[i], '\0');
		}
		i++;
	}
	data[k] = 0;
	return (data);
}

int	ft_space(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
	}
	if (str[i] == '1' || str[i] == '0')
		return (1);
	return (0);
}

char	**ft_add_to_map(char **tab)
{
	char	**map;
	int		i;
	int		k;

	i = 0;
	k = 0;
	map = malloc(sizeof(char *) * 100);
	if (!(map))
		return (NULL);
	while (tab && tab[i])
	{
		if (ft_space(tab[i]) == 1)
		{
			while (tab[i])
				map[k++] = ft_pstrdup(tab[i++], '\0');
			break ;
		}
		i++;
	}
	map[k] = 0;
	return (map);
}

t_data	*ft_add_to_data(t_data *data, char **tab, int i)
{
	while (tab && tab[i])
	{
		if (tinder(tab[i]) == 1)
		{
			data->x = get_screen_resolution(tab[i], 'x');
			data->y = get_screen_resolution(tab[i], 'y');
		}
		if (tinder(tab[i]) == 2)
		{
			data->north = ft_pstrdup(tab[i] + 3, '\0');
		}
		if (tinder(tab[i]) == 3)
		{
			data->south = ft_pstrdup(tab[i] + 3, '\0');
		}
		if (tinder(tab[i]) == 4)
		{
			data->west = ft_pstrdup(tab[i] + 3, '\0');
		}
		if (tinder(tab[i]) == 5)
		{
			data->east = ft_pstrdup(tab[i] + 3, '\0');
		}
		if (tinder(tab[i]) == 7)
		{
			data->floor = ft_pstrdup(tab[i] + 2, '\0');
		}
		if (tinder(tab[i]) == 8)
		{
			data->ceiling = ft_pstrdup(tab[i] + 2, '\0');
		}
		i++;
	}
	data->map = ft_add_to_map(tab);
	return (data);
}