/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:30:02 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/05 19:23:52 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/lemin.h"
#include <limits.h>

static void		parse_links(t_maze *maze, t_data *data)
{
	char	**split;
	t_link	*link;

	while (data)
	{
		if (*data->line != '#')
		{
			if (!(split = ft_strsplit(str, '-')))
				ft_error("Error while allocating memory");
			else if (!split[0] || !split[1] || split [2])
				ft_error("Error in block of links");
			else if (ft_strchr(split[0], ' ') || ft_strchr(split[1], ' '))
				ft_error("Space in link name");
			else if (*(split[0]) == 'L' || *(split[1]) == 'L')
				ft_error("Room name begin with \"L\"");
			if (!(link = ft_memalloc(sizeof(t_link))))
				ft_error("Error while allocating memory");
			link->name1 = split[0];	
			link->name2 = split[1];
			link->next = maze->links;
			maze->links = link;
			ft_memdel((void **)&split);
		}
		data = data->next;
	}
}

static void		create_room(t_maze *maze, char *line, int flag)
{
	char	**split;
	t_room	*room;

	if (!(split = ft_strsplit(str, ' ')))
		ft_error("Error while allocating memory");
	if (!split[0] || !split[1] || !split[2] || split [3])
		ft_error("Error in block of rooms");
	if (!(room = ft_memalloc(sizeof(t_room))) || /
		!(room->name = ft_strdup(split[0])))
		ft_error("Error while allocating memory");
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	if (room->x < 0 || room->y < 0 || \
		ft_numlen(room->x) != ft_strlen(split[1]) || \
		ft_numlen(room->y) != ft_strlen(split[2]))
		ft_error("Error in room coords");
	ft_splitdel(&split);
	room->cost = UINT_MAX;
	room->next = maze->rooms;
	maze->rooms = room;
	if (flag == START)
		maze->start = room->room;
	else if (flag == FINISH)
		maze->finish = room->room;
}

void			parse_rooms(t_maze *maze)
{
	int		flag;

	while (maze->data)
	{
		if (*maze->data->line == 'L')
			ft_error("Room name begin with \"L\"");
		if (*maze->data->line != '#' && ft_strchr(maze->data->line, '-'))
			return (parse_links(maze));
		if (!ft_strcmp(maze->data->line, "##start"))
			flag = START;
		else if (!ft_strcmp(maze->data->line, "##end"))
			flag = FINISH;
		else if (*maze->data->line != '#')
			create_room(maze, data->line, flag);
		maze->data = maze->data->next;
	}
}
