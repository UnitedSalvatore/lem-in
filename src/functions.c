/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:23:07 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/01 13:52:43 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_numlen(unsigned int num)
{
	size_t i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}

void	add_room(t_rooms **rooms, t_rooms *new)
{
	if (rooms == NULL || new == NULL)
		return ;
	new->next = *rooms;
	*rooms = new;
}

size_t	count_char(char *str)
{
	
}
