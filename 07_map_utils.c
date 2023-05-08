#include "cub3d.h"

int	check_orientation(char *str)
{
	int	error;
	int	i;

	error = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		{
			error++;
		}
		i++;
	}
	return (error);
}

int	check_string_position(char *s1, char *s, char *s2)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	while (s && s[i] != '0' && i > 0)
	{
		i--;
	}
	if (i >= ft_pstrlen(s1, '\0'))
	{
		return (1);
	}
	if (i >= ft_pstrlen(s2, '\0'))
	{
		return (1);
	}
	return (0);
}

int	is_non_map_char(char c)
{
	if (c != '\0' && c != '1' && c != '2' && c != '0' && c != ' ')
	{
		return (1);
	}
	return (0);
}

int	get_screen_resolution(char *str, char c)
{
	int	i;

	i = 2;
	if (c == 'y')
	{
		while (str && str[i] && str[i] >= '0' && str[i] <= '9')
		{
			i++;
		}
		i++;
	}
	return (ft_patoi(str + i));
}