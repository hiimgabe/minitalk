/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:35:56 by gamoreir          #+#    #+#             */
/*   Updated: 2023/04/18 21:27:47 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *point, int c, unsigned int n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = point;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (ptr);
}
