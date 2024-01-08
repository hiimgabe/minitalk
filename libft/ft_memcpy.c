/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:22:32 by gamoreir          #+#    #+#             */
/*   Updated: 2023/04/13 11:49:00 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*origin_dest;

	if (n == 0 || dest == src)
		return (dest);
	origin_dest = dest;
	while (n--)
		*((char *)dest++) = *((char *)src++);
	return (origin_dest);
}
