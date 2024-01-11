/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:14:19 by gabe              #+#    #+#             */
/*   Updated: 2024/01/11 09:23:59 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*print_message(char *message)
{
	ft_printf("%s\n", message);
	free(message);
	return (NULL);
}
/*
0xFF = 11111111
0x80 = 10000000


1. SIGUSR1

c    = 11111111 
bits = 0

c ^= 0x80 >> bits

0xFF     ^ 0x80     >> 0
11111111 ^ 10000000 >> 0
01111111 >> 0
01111111

2.

c    = 01111111
bits = 1

c ^= 0x80 >> bits

01111111 ^ 10000000 >> 1
11111111 >> 1
01111111

3.

c    = 01111111
bits = 2

01111111 ^ 10000000 >> 2
11111111 >> 2
00111111


*/
void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits = 0;
	static int	pid = 0;
	static char	*message = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			message = ft_strappend(message, c);
		else
			message = print_message(message);
		bits = 0;
		c = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
		ft_error(pid, message);
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = handler_sigusr;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
}
