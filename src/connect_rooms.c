/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:52:11 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/08 15:21:22 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"
#include "../libft/include/libft.h"
#include <string.h>

static void		create_edge(t_room *root, t_room *child)
{
	t_edge	*root_edge;

	root_edge = root->edges;
	while (root_edge)
	{
		if (root_edge->room == child)
			return ;
		root_edge = root_edge->next;
	}
	root_edge = ft_memalloc(sizeof(t_edge));
	root_edge->room = child;
	root_edge->next = root->edges;
	root->edges = root_edge;
}

static t_room	*find_room(t_room *rooms, char *name)
{
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, name))
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

void			connect_rooms(t_maze *maze)
{
	t_link	*links;
	t_room	*room_1;
	t_room	*room_2;

	links = maze->links;
	while (links)
	{
		room_1 = find_room(maze->rooms, links->name_1);
		room_2 = find_room(maze->rooms, links->name_2);
		create_edge(room_1, room_2);
		create_edge(room_2, room_1);
		links = links->next;
	}
}
