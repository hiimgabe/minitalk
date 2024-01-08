/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:04:00 by gamoreir          #+#    #+#             */
/*   Updated: 2023/04/18 23:37:03 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signs;
	int	n;

	i = 0;
	signs = 0;
	n = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			signs++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n *= 10;
		n = n + (str[i] - 48);
		i++;
	}
	if ((signs % 2) != 0)
		return (-n);
	return (n);
}
