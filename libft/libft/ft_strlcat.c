/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:48:35 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/25 01:48:36 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	int		n;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if ((n = (int)size - (int)dstlen) <= 0)
		return (srclen + size);
	dst += dstlen;
	while (*src && n-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (dstlen + srclen);
}
