/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:50:40 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/25 01:50:53 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	needle_len;
	int		len;

	if (!(needle_len = ft_strlen(s2)))
		return ((char *)s1);
	len = (int)(n - needle_len);
	while (*s1 && len-- >= 0)
	{
		if (!ft_memcmp(s1, s2, needle_len))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
