/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:34:38 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/29 20:54:25 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <stdbool.h>
# include <sys/acl.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <limits.h>
# include <stdarg.h>
# include "libft.h"

# define OPT_LL 1
# define OPT_LA 2
# define OPT_LR 4
# define OPT_LT 8
# define OPT_UR 16
# define OPT_LU 32
# define OPT_LG 64
# define OPT_LX 128
# define OPT_ATTR 256
# define OPT_US 512

# define SEC_6_MONTH 15778800
# define FLAG "-RSaglrtux@"

int	g_options;

typedef struct		s_max
{
	int				len_u;
	int				len_g;
	int				len_l;
	int				len_s;
	int				len_n;
	int				total;
	int				nb_node;
	bool			device;
	bool			error;
	bool			dir;
}					t_max;

typedef struct		s_error
{
	char			*name;
	int				erno;
	struct s_error	*next;
}					t_error;

typedef	struct		s_info
{
	char			*path;
	char			*name;
	ino_t			inode;
	char			type;
	time_t			time;
	char			*right;
	char			*uid;
	int				len_uid;
	char			*gruid;
	int				len_gruid;
	char			*month;
	char			*day;
	char			*hour;
	char			*name_lnk;
	nlink_t			link;
	int				len_link;
	off_t			size;
	int				len_size;
	quad_t			block;
	int				total;
	char			acl_c;
	char			*acl_list;
	int				acl_len;
	int				acl_size;
	int				major;
	int				minor;
	struct s_info	*next;
	struct s_info	*prev;
	struct s_info	*sub_begin;
	struct s_info	*sub_end;
}					t_info;

typedef struct		s_util
{
	t_info			**begin;
	t_info			**end;
	char			*dir_name;
	int				i;
}					t_util;

/*
** stat.c
*/

int					get_stat(t_info *info, char *file);
char				*ft_right(struct stat *st, t_info *info);
char				*ft_uid(struct stat *st);
char				*ft_gruid(struct stat *st);
char				*ft_month(struct stat *st);
char				*ft_day(struct stat *st);
char				*ft_hour(struct stat *st);
char				ft_type(struct stat *st);
time_t				ft_time(struct stat *st);
char				*ft_name_lnk(struct stat *st, char *path);
char				ft_exec_other(int mode);
char				ft_exec_owner(int mode);
char				ft_exec_group(int mode);
void				get_acl_attr(t_info *info, char *path);

/*
** options.c
*/

int					check_options(char *opt);

/*
** ft_ls.c
*/

void				create_chain_list(char	*dn, t_info **b, t_info **e, int i);
void				ft_ls(char **dirs, t_info **beg, t_info **end, t_max *m);
void				ft_read_dir(DIR *dir, t_util *ut, t_max *max);
void				ft_recursive(t_util *ut, t_max *max);
void				ft_subdir(t_info *info, t_util *ut);

/*
** display_lst.c
*/

void				ft_usage(char illegal);
void				display_node(t_info **be, t_info **end, int i, t_max *max);
void				display_l(t_info *tmp, t_max *max);
void				display_lg(t_info **be, t_info **end, t_max *max, int dir);
void				display_l1(t_info **begin, t_info **end);
void				display_error(t_error *begin);
void				display_attr(t_info *node);

/*
** display_basic.c
*/

void				display_basic(t_info **begin, t_info **end, t_max *max);

/*
** list.c
*/

t_info				*list_new(void);
t_error				*list_error_new(char *str);
void				list_add(t_info *node, t_info **begin, t_info **end);
void				lst_error(char *str, t_error **begin, t_max *max);
int					check_inode(t_info **begin, t_info *info);

/*
** sort_list.c
*/

void				sort_time(t_info *node, t_info **begin, t_info **end);
void				sort_alphanum(t_info *node, t_info **begin, t_info **end);
void				sort_size(t_info *node, t_info **begin, t_info **end);
void				node_swap(t_info **n, t_info **t, t_info **b, t_info **e);

/*
** sort_arg.c
*/

char				**sort_dirs(char **argv, int i);
void				sort_files(char **argv, t_util *ut, t_max *max);

/*
** free.c
*/

void				free_tab(char **tab);
void				free_inside(t_info *tmp);
void				free_list(t_info **begin, t_info **end);
void				free_lst_not_dir(t_info **begin, t_info **end);
void				free_node(t_info **begin, t_info **end, t_info *node);

/*
** free_utils.c
*/

void				unlink_node(t_info *node);
void				set_node_to_null(t_info **node1, t_info **node2);
int					update_head_tail(t_info *tmp, t_info **begin, t_info **end);
int					free_node_alone(t_info *info);

/*
** utils.c
*/

void				init_max(t_max *max);
void				update_max(t_max *max, t_info *info);
void				fts_open_error(t_info **begin, t_info **end);
t_util				*new_util(t_info **begin, t_info **end, int i);
void				fill_stat(struct stat file_stat, t_info *info, char *path);

/*
** display_utils.c
*/

void				display_l_info(t_info *tmp, t_max *max);

#endif
