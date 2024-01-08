/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:31:51 by gamoreir          #+#    #+#             */
/*   Updated: 2023/05/26 09:38:37 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(char c, va_list args)
{
	int	printlen;

	printlen = 0;
	if (c == 'c')
		printlen = ft_printf_char(va_arg(args, int));
	else if (c == '%')
		printlen = write(1, "%", 1);
	else if (c == 's')
		printlen = ft_printf_string(va_arg(args, char *));
	else if (c == 'p')
		printlen = ft_printf_pointer(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		printlen = ft_printf_number(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		printlen = ft_printf_hexadecimal(va_arg(args, unsigned int), c);
	else if (c == 'u')
		printlen = ft_printf_number(va_arg(args, unsigned int));
	return (printlen);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printlen;

	i = 0;
	printlen = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			printlen += write(1, (str + i), 1);
		else
		{
			i++;
			printlen += ft_format(str[i], args);
		}
		i++;
	}
	va_end(args);
	return (printlen);
}
