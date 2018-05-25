/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 02:24:04 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/25 02:24:05 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_whitespaces(const char c)
{
	return ((c == ' ' || c == '\t' || c == '\n') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	char const *tmp;
	char const *found;

	if (!s)
		return (NULL);
	while (is_whitespaces(*s))
		s++;
	tmp = s;
	found = tmp;
	while (*tmp)
		if (!is_whitespaces(*tmp++) && (is_whitespaces(*tmp) || *tmp == '\0'))
			found = tmp;
	return (ft_strsub(s, 0, (size_t)(found - s)));
}
