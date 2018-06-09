/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:23:07 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/09 16:23:28 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include <stdlib.h>
#include <string.h>

size_t	ft_numlen(unsigned int num)
{
	size_t i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}
