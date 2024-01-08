/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:51:53 by gamoreir          #+#    #+#             */
/*   Updated: 2023/04/23 18:16:02 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*iszero(char *str)
{
	str[0] = '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		nblen;
	long	nb;

	nb = n;
	nblen = ft_nblen(nb);
	res = (char *) malloc(sizeof(*res) * (ft_nblen(nb) + 1));
	if (!res)
		return (NULL);
	res[nblen--] = '\0';
	if (nb == 0)
		return (iszero(res));
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		res[nblen] = (nb % 10) + 48;
		nb /= 10;
		nblen--;
	}
	return (res);
}
