/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:29:07 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/08 18:36:13 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"
#include "../libft/include/libft.h"
#include <unistd.h>

//
#include "../libft/include/ft_printf.h"
#include <fcntl.h>

static void		print_path(t_room *room)
{
	while (room)
	{
		ft_printf("Room name: |%s|\n", room->name);
		room = room->root;
	}
}

static void		print_rooms(t_room *rooms)
{
	t_edge 	*edge;

	while (rooms)
	{
		edge = rooms->edges;
		ft_printf("Room name: |%s|\n", rooms->name);
		while (edge)
		{
			ft_printf("Edge with room: |%s|\n", edge->room->name);
			edge = edge->next;
		}
		ft_printf("\n");
		rooms = rooms->next;
	}
}

static void		parse_ants(t_maze *maze)
{
	int		ants;

	maze->data = maze->data_copy;
	if (!maze->data)
		ft_error("ERROR: empty input");
	ants = ft_atoi(maze->data->line);
	if (ants < 0 || ft_numlen(ants) != ft_strlen(maze->data->line))
		ft_error("ERROR in number of ants");
	maze->number_of_ants = (unsigned)ants;
	maze->data = maze->data->next;
}

int				main(void)
{
	t_maze	maze;
	ft_bzero(&maze, sizeof(t_maze));
//	read_data(STDIN_FILENO, &maze);
	read_data(open("test", O_RDONLY), &maze);
	parse_ants(&maze);
	parse_rooms(&maze);
	parse_links(&maze);
	validate(&maze);
	connect_rooms(&maze);
	find_path(&maze);
	print_rooms(maze.rooms);
	print_path(maze.finish);
	return (0);
}
