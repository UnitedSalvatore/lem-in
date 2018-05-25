/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:41:15 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/11 18:32:14 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_.h"

void		ft_add_to_buf(const char c, struct s_buffer *buffer)
{
	buffer->buf[buffer->size++] = c;
	if (buffer->size == BUFF_SIZE)
	{
		write(buffer->fd, buffer->buf, buffer->size);
		buffer->written += buffer->size;
		buffer->size = 0;
	}
}
