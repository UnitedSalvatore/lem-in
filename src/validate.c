/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:41:39 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/09 16:25:04 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/lemin.h"

static void	validate_links(t_maze *maze)
{
	unsigned short	flag_1;
	unsigned short	flag_2;
	t_link			*link;
	t_room			*room;

	link = maze->links;
	while (link)
	{
		flag_1 = 0;
		flag_2 = 0;
		room = maze->rooms;
		while (room && (!flag_1 || !flag_2))
		{
			if (!ft_strcmp(room->name, link->name_1))
				flag_1 = 1;
			if (!ft_strcmp(room->name, link->name_2))
				flag_2 = 1;
			room = room->next;
		}
		if (!flag_1 || !flag_2)
			ft_error("ERROR: Links: links with a non-existent room");
		link = link->next;
	}
}

static void	validate_rooms(t_maze *maze)
{
	t_room	*room;
	t_room	*next;

	if (!maze->start)
		ft_error("ERROR: No start");
	else if (!maze->finish)
		ft_error("ERROR: No end");
	room = maze->rooms;
	while (room)
	{
		next = room->next;
		while (next)
		{
			if (!ft_strcmp(room->name, next->name))
				ft_error("ERROR: 2 or more rooms with the same name");
			if (room->x == next->x && room->y == next->y)
				ft_error("ERROR: 2 or more rooms with the same coords");
			next = next->next;
		}
		room = room->next;
	}
}

void		validate(t_maze *maze)
{
	validate_rooms(maze);
	validate_links(maze);
}
