/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 02:27:56 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/25 02:28:20 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i *= 10;
	return (i);
}

void		ft_putnbr(int n)
{
	int len;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	len = ft_numlen(n);
	while (len)
	{
		ft_putchar((char)(n / len + 48));
		n %= len;
		len /= 10;
	}
}
