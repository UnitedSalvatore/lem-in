/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:32:55 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/09 16:23:37 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"
#include "../libft/include/libft.h"
#include <string.h>

static t_room	*get_next_from_queue(t_edge **queue)
{
	t_room	*room;
	t_edge	*tmp;

	tmp = *queue;
	if (!tmp)
		return (NULL);
	room = tmp->room;
	*queue = (*queue)->next;
	ft_memdel((void **)&tmp);
	return (room);
}

static void		add_to_queue(t_edge **queue, t_room *room)
{
	t_edge	*tmp;
	t_edge	*new;

	tmp = *queue;
	while (tmp)
	{
		if (tmp->room == room)
			return ;
		tmp = tmp->next;
	}
	if (!(new = ft_memalloc(sizeof(t_edge))))
		ft_error("Error while allocating memory");
	new->room = room;
	if (!*queue)
		*queue = new;
	else
	{
		tmp = *queue;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void			find_path(t_maze *maze)
{
	t_room	*room;
	t_edge	*room_edge;

	add_to_queue(&maze->queue, maze->start);
	while (!maze->finish->visited && maze->queue)
	{
		room = get_next_from_queue(&maze->queue);
		room->visited = 1;
		room_edge = room->edges;
		while (room_edge)
		{
			if (!room_edge->room->visited)
			{
				add_to_queue(&maze->queue, room_edge->room);
				room_edge->room->root = room;
			}
			room_edge = room_edge->next;
		}
	}
	if (!maze->finish->visited)
		ft_error("ERROR: There is no connection between start and finish");
}
