/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 21:54:19 by swofferh       #+#    #+#                */
/*   Updated: 2020/01/10 21:51:50 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef enum			e_state
{
	line_read = 1,
	end_read = 0,
	error = -1,
	loop = 2
}						t_state;

typedef struct			s_list
{
	char				*content;
	size_t				size;
	int					fd;
	struct s_list		*next;
}						t_list;

t_list			*get_buffer(t_list **lst, int fd);
int				get_next_line(int fd, char **line);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*copy_buffer(char *old, char *new, size_t n);
size_t			scan_index(char *s, char c);

#endif