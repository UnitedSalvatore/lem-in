/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:29:07 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/08 03:18:23 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"
#include "../libft/include/libft.h"
#include <unistd.h>

static void		parse_ants(t_maze *maze)
{
	int		ants;

	maze->data_copy = maze->data;
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
	read_data(STDIN_FILENO, &maze);
	parse_ants(&maze);
	parse_rooms(&maze);
	parse_links(&maze);
	validate(&maze);
	return (0);
}
