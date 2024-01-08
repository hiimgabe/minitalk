/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:45:13 by gamoreir          #+#    #+#             */
/*   Updated: 2023/04/23 14:49:43 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*new;
	char	*original;

	if (!str)
		return (NULL);
	if (len > (unsigned int)ft_strlen(str) - start)
		len = (ft_strlen(str) - start);
	if (start >= (unsigned int)ft_strlen(str))
	{
		new = (char *) malloc(sizeof(*new));
		if (!new)
			return (NULL);
		*new = '\0';
		return (new);
	}
	new = (char *) malloc(sizeof(*new) * (len + 1));
	if (!new)
		return (NULL);
	original = new;
	while (str[start] && len--)
		*new++ = str[start++];
	*new = '\0';
	return (original);
}
