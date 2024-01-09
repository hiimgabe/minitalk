/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:46:55 by gabe              #+#    #+#             */
/*   Updated: 2024/01/09 17:06:17 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bit(int pid, char *str)
{
	static char	*message = 0;
	static int	s_pid = 0;
	static int	bits = -1;

	if (str)
		message = ft_strdup(str);
	if (!message)
		ft_error(pid, str);
	if (pid)
		s_pid = pid;
	if (message[++bits / 8])
	{
		if (message[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				ft_error(pid, message);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			ft_error(pid, message);
		return (0);
	}
	if (!send_null(s_pid, message))
		return (0);
	free(message);
	return (1);
}

void	handler_sigusr(int signum)
{
	int	success;

	success = 0;
	if (signum == SIGUSR1)
		success = send_bit(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_printf("Server ended unexpectedly.\n");
		exit (EXIT_FAILURE);
	}
	if (success)
	{
		ft_printf("Operation successful.\n");
		exit (EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Invalid arguments.\n");
		exit (EXIT_FAILURE);
	}
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}