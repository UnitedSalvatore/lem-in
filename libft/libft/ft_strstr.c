/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:49:29 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/25 01:50:31 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t needle_len;

	if (!(needle_len = ft_strlen(s2)))
		return ((char *)s1);
	while ((s1 = ft_strchr(s1, *s2)) != NULL)
	{
		if (!ft_memcmp(s1, s2, needle_len))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
