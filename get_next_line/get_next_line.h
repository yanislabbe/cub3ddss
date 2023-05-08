#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 4096

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

/*	get_next_line */
int		get_next_line(int fd, char **line);
int		read_file(char **buffer, char **line, int fd);
int		read_buffer(char **buffer, char **line, char c);

/*	get_next_line_utils */
int		gnl_strlen(char *str, char c);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(char *buffer, char c);
char	*gnl_strcut(char *buffer, char c);
int		gnl_check_new_line(char *str, char c);

#endif