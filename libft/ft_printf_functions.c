/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:31:51 by gamoreir          #+#    #+#             */
/*   Updated: 2023/05/26 09:38:48 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_number(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count += ft_printf_char('-');
	}
	if (nb < 10)
		count += ft_printf_char(nb + 48);
	if (nb >= 10)
	{
		count += ft_printf_number((nb / 10));
		count += ft_printf_number((nb % 10));
	}
	return (count);
}

int	ft_printf_string(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
		write(1, &str[count++], 1);
	return (count);
}

int	ft_printf_hexadecimal(unsigned long nb, char c)
{
	int		count;
	char	*hexa;

	count = 0;
	if (c == 'x')
		hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	if (nb < 16)
		count += write(1, &hexa[nb], 1);
	if (nb >= 16)
	{
		count += ft_printf_hexadecimal((nb / 16), c);
		count += ft_printf_hexadecimal((nb % 16), c);
	}
	return (count);
}

int	ft_printf_pointer(unsigned long nb)
{
	int	count;

	count = 0;
	if (!nb)
		return (write(1, "(nil)", 5));
	else
		write(1, "0x", 2);
	count += ft_printf_hexadecimal(nb, 'x');
	return (count + 2);
}
