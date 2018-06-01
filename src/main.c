/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:29:07 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/04 16:02:17 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"
#include "../libft/include/libft.h"
#include <unistd.h>

static void		parse_ants(int fd, t_maze *maze)
{
	int		ants;

	if (ft_getline(fd, &maze->line) < 0)
		ft_error("Error while reading file");
	ants = ft_atoi(str);
	if (ants < 0 || ft_numlen(ants) != ft_strlen(str))
		ft_error("Error in number of ants");
	maze->number_of_ants = (unsigned)ants;
}

static void		parse(int fd, t_maze *maze)
{
	parse_ants(fd, maze);
	parse_rooms(fd, maze);
	parse_links(fd, maze);
}

int				main(void)
{
	t_maze	maze;

	ft_bzero(&maze, sizeof(t_maze));
	parse(STDIN_FILENO, &maze);
	return (0);
}
