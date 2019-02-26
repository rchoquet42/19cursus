/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:14:05 by rchoquet          #+#    #+#             */
/*   Updated: 2018/12/17 19:20:38 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	sig_end(int sig_num)
{
	char			*name_term;
	struct termios	term;

	sig_num = 0;
	if (!(name_term = getenv("TERM")) && (env_not_found()))
		return ;
	if (tgetent(NULL, name_term) == ERR)
		return (ft_putstr_fd("tgetent failed (sig_end)\n", 2));
	if (tcgetattr(0, &term) == -1)
		return (ft_putstr_fd("tcgetattr failed (sig_end)\n", 2));
	term.c_lflag |= (ICANON);
	term.c_lflag |= (ECHO);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (ft_putstr_fd("tcstattr failed (sig_end)\n", 2));
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	exit(0);
}
