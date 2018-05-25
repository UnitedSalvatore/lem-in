/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:49:13 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/25 01:49:14 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *found;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	found = NULL;
	while ((s = ft_strchr(s, c)) != NULL)
		found = s++;
	return ((char *)found);
}
