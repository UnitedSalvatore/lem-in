/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:34:40 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/25 01:34:41 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((unsigned long int)dst < (unsigned long int)src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			((unsigned char *)dst)[len] = ((const unsigned char *)src)[len];
	return (dst);
}
