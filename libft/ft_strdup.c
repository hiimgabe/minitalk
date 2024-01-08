/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:45:41 by gamoreir          #+#    #+#             */
/*   Updated: 2023/04/19 11:03:45 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *) malloc(sizeof(*new) * ft_strlen((char *)str) + 1);
	if (!new)
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = (char)str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
