/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 01:58:26 by rchoquet          #+#    #+#             */
/*   Updated: 2018/12/11 10:38:21 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	init_signal(void)
{
	signal(SIGWINCH, sig_winch);
	signal(SIGINT, sig_end);
	signal(SIGABRT, sig_end);
	signal(SIGBUS, sig_end);
	signal(SIGCHLD, sig_end);
	signal(SIGCONT, sig_restart);
	signal(SIGTSTP, sig_suspend);
	signal(SIGFPE, sig_end);
	signal(SIGHUP, sig_end);
	signal(SIGILL, sig_end);
	signal(SIGPIPE, sig_end);
	signal(SIGQUIT, sig_end);
	signal(SIGSEGV, sig_end);
	signal(SIGTERM, sig_end);
	signal(SIGTTIN, sig_end);
	signal(SIGTTOU, sig_end);
	signal(SIGUSR1, sig_end);
	signal(SIGUSR2, sig_end);
	signal(SIGSYS, sig_end);
	signal(SIGTRAP, sig_end);
	signal(SIGURG, sig_end);
	signal(SIGVTALRM, sig_end);
	signal(SIGXCPU, sig_end);
	signal(SIGXFSZ, sig_end);
}

int			init_all(t_argv **begin, t_argv **end, t_maxinfo **max)
{
	char			*name_term;
	struct termios	term;

	save_begin(begin);
	save_end(end);
	save_max(max);
	init_signal();
	if (!(name_term = getenv("TERM")))
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}
