/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:15:20 by rchoquet          #+#    #+#             */
/*   Updated: 2018/07/08 23:44:06 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 500
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef	struct		s_block
{
	char				*str;
	int					fd;
	int					count;
	struct s_block		*next;
}					t_block;

int					get_next_line(const int fd, char **line);
t_block				*find_fd(t_block *begin, int fd);
int					ft_read_eof(t_block **temp, char **line, t_block **begin);
int					ft_lst_freenode(int fd, t_block **begin);
char				*ft_swiss(t_block **temp, int ret, char **line, int option);

#endif
