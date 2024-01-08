/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:03:57 by gamoreir          #+#    #+#             */
/*   Updated: 2023/04/18 18:22:09 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			ptr = (char *)str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (ptr);
}
