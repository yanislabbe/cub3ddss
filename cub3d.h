#ifndef CUB3D_H
# define CUB3D_H

# define SUCCESS 0
# define FAIL 1

# define FAIL_FD -1
# define FAIL_CUB -2

# include "get_next_line/get_next_line.h"

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>


typedef struct	s_parse
{
	int north;
	int south;
	int west;
	int east;
	int floor;
	int ceiling;
	int map_wg_char;
	int map_end;
	int map_wall;
	int map_dup;
	int map_no_pos;
	int no_map;
	int wrong_line;

}				t_parse;

typedef struct	s_data
{
	int		x;
	int		y;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	char	**map;
}				t_data;

/*	02_parse.c */
int 			ft_parse(char **argv);

/*	03_parse_utils.c */
int 			ft_cub(char *argv);

/*	04_free.c */
t_data			*ft_free_data(t_data *data);
char			**ft_free_tab(char **tab);

/*	05_add_to_data.c */
char			**ft_add_value_to_data(char **tab, t_parse *parse, char **data, int i);
t_data			*ft_add_to_data(t_data *data, char **tab, int i);
char			**ft_add_to_map(char **tab);
int				ft_space(char *str);

/*	06_error.c */
t_parse			*get_error(t_parse *parse, char **tab, int i);
t_parse			*check_error(char **data, t_parse *parse);
void			print_error(t_parse *parse);
int				ft_error(t_parse *parse);

/*	07_map_utils.c */
int				check_string_position(char *s1, char *s, char *s2);
int				get_screen_resolution(char *str, char c);
int				check_orientation(char *str);
int				is_non_map_char(char c);

/*	08_validation.c  */
int				check_file_readability(char *str, int i);
int				validate_color_string(char *str, int i);
int				validate_rgb_color(char *str, int i);

/*	09_map.c */
t_parse			*ft_parse_map_continue(t_parse *parse, int dup, char *str);
t_parse			*ft_parse_map(char **map, t_parse *parse, int i, int dup);
int				ft_unwanted_character(char *str);

/*	10_parse.c */
t_parse			*init_struct(t_parse *parse);
int				ft_is_a_wall_around(char *str);
int				ft_wall(char *str);
int				tinder(char *str);
int				is_double(int a);
int				ft_parsing(char **tab);

/*	11_libft.c */
int				ft_pstrlen(char *str, char c);
char			*ft_pstrjoin(char *s1, char *s2);
char			*ft_pstrdup(char *buffer, char c);
int				check_new_line(char *str, char c);
char			*ft_pstrcut(char *buffer, char c);
void    		ft_pputchar(char c);
void			ft_pputstr(char *str);
int				ft_patoi(char *str);

#endif
