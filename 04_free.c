#include "cub3d.h"

char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
	return (tab);
}

t_data	*ft_free_data(t_data *data)
{
	free(data->north);
	free(data->south);
	free(data->west);
	free(data->east);
	free(data->floor);
	free(data->ceiling);
	data->map = ft_free_tab(data->map);
	free(data);
	return (data);
}