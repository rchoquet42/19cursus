/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 02:31:18 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/27 10:15:54 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static char		find_type(char *str)
{
	struct stat	s_info;

	if (lstat(str, &s_info) != 0)
		return ('u');
	if (S_ISDIR(s_info.st_mode))
		return ('d');
	if (s_info.st_mode & S_IXUSR)
		return ('x');
	return ('f');
}

static t_argv	*new_node(char *str)
{
	t_argv	*node;

	if (!(node = (t_argv*)malloc(sizeof(t_argv))))
		return (NULL);
	if (!(node->name = ft_strdup(str)))
		return (NULL);
	node->select = 0;
	node->cursor = 0;
	node->next = NULL;
	node->prev = NULL;
	node->type = find_type(str);
	return (node);
}

static void		lst_add(t_argv *node, t_argv **beg, t_argv **e, t_maxinfo *max)
{
	t_argv	*tmp;
	size_t	len;

	max->elem += 1;
	if ((*beg) == NULL)
	{
		(*beg) = node;
		node->cursor = 1;
	}
	else
	{
		tmp = *beg;
		while (tmp->next != (*e))
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
		if ((len = ft_strlen(node->name)) > max->max_len)
			max->max_len = len;
	}
}

t_maxinfo		*create_chain(t_argv **begin, t_argv **end, char **argv)
{
	t_argv		*tmp;
	t_maxinfo	*max_info;
	int			i;

	if (!(max_info = (t_maxinfo*)malloc(sizeof(t_maxinfo))))
		return (NULL);
	max_info->max_len = 0;
	max_info->elem = 0;
	max_info->selected = 0;
	i = 0;
	while (argv[++i])
	{
		if (!(tmp = new_node(argv[i])))
			continue ;
		lst_add(tmp, begin, end, max_info);
	}
	(*end) = tmp;
	(*end)->next = (*begin);
	(*begin)->prev = (*end);
	return (max_info);
}
