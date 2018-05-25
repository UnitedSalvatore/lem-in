/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:25:51 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/13 20:38:51 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(int n, const unsigned int base)
{
	size_t i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= base)
		i++;
	return (i);
}

static size_t	uint_len(unsigned int n, const unsigned int base)
{
	size_t i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char			*ft_itoa_base(int n, const unsigned int base)
{
	size_t		len;
	char		*str;
	long int	n2;

	if (base < 2 || base > 16)
		return (NULL);
	len = int_len(n, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	n2 = n;
	if (n < 0)
	{
		*str = '-';
		n2 = -n2;
	}
	str[--len] = (char)(n2 % base + 48);
	if (str[len] > '9')
		str[len] += 7;
	while (n2 /= base)
	{
		str[--len] = (char)(n2 % base + 48);
		if (str[len] > '9')
			str[len] += 7;
	}
	return (str);
}

char			*ft_uitoa_base(unsigned int n, const unsigned int base)
{
	size_t				len;
	char				*str;
	long unsigned int	n2;

	if (base < 2 || base > 16)
		return (NULL);
	len = uint_len(n, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	n2 = n;
	str[--len] = (char)(n2 % base + 48);
	if (str[len] > '9')
		str[len] += 7;
	while (n2 /= base)
	{
		str[--len] = (char)(n2 % base + 48);
		if (str[len] > '9')
			str[len] += 7;
	}
	return (str);
}
