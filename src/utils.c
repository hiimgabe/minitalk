/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:56:53 by gabe              #+#    #+#             */
/*   Updated: 2024/01/11 09:14:40 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strappend(char *message, char c)
{
	char	*new;
	int		i = 0;

	if (!message)
	{
		new = malloc(2);
		new[0] = c;
		new[1] = '\0';
		return (new);
	}
	else
		new = malloc(ft_strlen(message) + 2);
	while (message[i])
	{
		new[i] = message[i];
		i++;
	}
	new[i] = c;
	new[++i] = '\0';
	free(message);
	return (new);
}

void	ft_error(int pid, char *message)
{
	if (message)
		free(message);
	ft_printf("Unexpected error.\n");
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

int	send_null(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if(kill(pid, SIGUSR1) == -1)
			ft_error(pid, str);
		return (0);
	}
	return (1);
}
