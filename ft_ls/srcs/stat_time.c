/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:52:37 by rchoquet          #+#    #+#             */
/*   Updated: 2019/02/10 16:05:21 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_month(struct stat *st)
{
	time_t			time;
	struct timespec ts;
	char			*date;
	char			*temp;

	ts = ((g_options & OPT_LU) == 0 ? st->st_mtimespec : st->st_atimespec);
	time = ts.tv_sec;
	date = ctime(&time);
	temp = ft_strsub(date, 4, 3);
	return (temp);
}

char	*ft_day(struct stat *st)
{
	time_t			time;
	struct timespec ts;
	char			*date;
	char			*temp;

	ts = ((g_options & OPT_LU) == 0 ? st->st_mtimespec : st->st_atimespec);
	time = ts.tv_sec;
	date = ctime(&time);
	temp = ft_strsub(date, 8, 2);
	return (temp);
}

char	*ft_hour(struct stat *st)
{
	time_t			current_time;
	time_t			file_time;
	struct timespec	ts;
	char			*date;
	char			*temp;

	current_time = time(&current_time);
	ts = ((g_options & OPT_LU) == 0 ? st->st_mtimespec : st->st_atimespec);
	file_time = ts.tv_sec;
	date = ctime(&file_time);
	if (ft_strlen(date) == 30)
		return (ft_strdup(" 10000"));
	if ((current_time - file_time > SEC_6_MONTH)
			|| (current_time - file_time) < 0)
		temp = ft_strsub(date, 20, 4);
	else
		temp = ft_strsub(date, 11, 5);
	return (temp);
}

time_t	ft_time(struct stat *st)
{
	time_t			time;
	struct timespec	ts;

	ts = ((g_options & OPT_LU) == 0 ? st->st_mtimespec : st->st_atimespec);
	time = ts.tv_sec;
	return (time);
}
