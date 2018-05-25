/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 02:24:17 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/27 18:32:08 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			i++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (i);
}

static size_t	word_len(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void		ft_strsdel(char **str)
{
	while (*str)
	{
		ft_strdel(str);
		str++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	words;
	size_t	len;
	char	**str;

	if (!s || c == '\0' || !(str = malloc(sizeof(char *) * \
					((words = count_words(s, c)) + 1))))
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		str[i] = ft_strsub(s, 0, len);
		if (!str[i++])
		{
			ft_strsdel(str);
			ft_strdel((char **)&str);
			return (NULL);
		}
		s += len;
	}
	str[i] = 0;
	return (str);
}
