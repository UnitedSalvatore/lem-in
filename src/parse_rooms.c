/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:56:31 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/04 16:18:37 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_getline.h"
#include "../libft/include/libft.h"
#include "../include/lemin.h"
#include <string.h>
#include <limits.h>

static void		create_room(int fd, t_maze *maze, char *str, int flag)
{
	char	**split;
	t_rooms	*new;

	if (!(split = ft_strsplit(str, ' ')))
		ft_error("Error while allocating memory");
	if (!split[0] || !split[1] || !split[2] || split [3])
		ft_error("Error in block of rooms");
	if (!(new = ft_memalloc(sizeof(t_rooms))) || \
		!(new->room = ft_memalloc(sizeof(t_room))) || /
		!(new->room->name = ft_strdup(split[0])))
		ft_error("Error while allocating memory");
	new->room->x = ft_atoi(split[1]);
	new->room->y = ft_atoi(split[2]);
	if (new->room->x < 0 || new->room->x < 0 || \
		ft_numlen(new->room->x) != ft_strlen(split[1]) || \
		ft_numlen(new->room->y) != ft_strlen(split[2]))
		ft_error("Error in room coords");
	ft_splitdel(&split);
	new->room->cost = UINT_MAX;
	add_room(&maze->rooms, new);
	if (flag == START)
		maze->start = new->room;
	else if (flag == FINISH)
		maze->finish = new->room;
}

void			parse_rooms(int fd, t_maze *maze)
{
	int		flag;

	flag = ROOM;
	while (ft_getline(fd, &maze->line) == 1)
	{
		if (*maze->str != '#' && *maze->str != 'L' && ft_strchr(maze->str, '-'))
			return ;
		if (!ft_strcmp(str, "##start"))
			flag = START;
		else if (!ft_strcmp(str, "##end"))
			flag = FINISH;
		if (*str != '#')
		{
			create_room(str, maze, flag);
			if (flag != ROOM)
				flag = ROOM;
		}
		ft_strdel(&str);
	}
}
