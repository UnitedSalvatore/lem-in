/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 02:30:08 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/25 02:30:29 by ypikul           ###   ########.fr       */
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

void		ft_putnbr_fd(int n, int fd)
{
	int len;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	len = ft_numlen(n);
	while (len)
	{
		ft_putchar_fd((char)(n / len + 48), fd);
		n %= len;
		len /= 10;
	}
}
