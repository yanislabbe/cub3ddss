#include "cub3d.h"

int	check_file_readability(char *str, int i)
{
	int	fd;

	fd = open(str + i, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (3);
	}
	close(fd);
	return (1);
}

int	validate_color_string(char *str, int i)
{
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if (str[i] == '\0')
	{
		return (1);
	}
	return (3);
}

int	validate_rgb_color(char *str, int i)
{
	if (str && str[i])
	{
		if (ft_patoi(str + i) >= 0 && ft_patoi(str + i) <= 255)
		{
			while (str[i] && str[i] >= '0' && str[i] <= '9')
			{
				i++;
			}
			if (str[i] && str[i] == ',')
			{
				i++;
				if (ft_patoi(str + i) >= 0 && ft_patoi(str + i) <= 255)
				{
					while (str[i] && str[i] >= '0' && str[i] <= '9')
					{
						i++;
					}
					if (str[i] && str[i] == ',')
					{
						i++;
						if (ft_patoi(str + i) >= 0 && ft_patoi(str + i) < 255)
						{
							return (validate_color_string(str, i));
						}
					}
				}
			}
		}
	}
	return (3);
}