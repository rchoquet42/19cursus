/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:45:31 by rchoquet          #+#    #+#             */
/*   Updated: 2018/12/17 14:45:33 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char *argv[], char *env[])
{
	pid_t		pid;
	int			pipe_fd[2]; //pipefd[0] = sortie, pipefd[1] = entree
	char		buffer[1024];
	int			ret;
	int			status;

	if (argc < 2)
		return (1);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1) // definis aue l'entree de mon pipe est stdout_fileno i.e. sortie standart
			perror("dup2");
		else if (execve(argv[1], argv + 1, env) == -1)
			perror("execve");
		return (1);
	}
	else
	{
		wait(NULL);
		close(pipe_fd[1]);

		while ((ret = read(pipe_fd[0], buffer, 1023)) != 0)
		{
			buffer[ret] = 0;
			printf("%s\n", buffer);
		}
	}
	return (0);
}
