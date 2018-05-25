/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 02:26:40 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/25 02:26:41 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(int n)
{
	size_t i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	size_t		len;
	char		*str;
	long int	n2;

	len = int_len(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	n2 = n;
	if (n < 0)
	{
		*str = '-';
		n2 = -n2;
	}
	str[--len] = (char)(n2 % 10 + 48);
	while (n2 /= 10)
		str[--len] = (char)(n2 % 10 + 48);
	return (str);
}
