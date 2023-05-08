#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("Error! *main return*\n");
		return (FAIL);
	}
	if (ft_parse(argv) != SUCCESS)
	{
		printf("Error! *main return*\n");
		return (FAIL);
	}
	return (SUCCESS);
}