/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:29:40 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/09 16:27:35 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <string.h>

# define ROOM 0
# define START 1
# define FINISH 2

typedef struct s_room	t_room;
typedef struct s_link	t_link;
typedef struct s_data	t_data;
typedef struct s_edge	t_edge;

struct				s_room
{
	char			*name;
	int				x;
	int				y;
	unsigned int	ant;

	unsigned short	visited;
	t_room			*root;
	t_edge			*edges;

	t_room			*next;
};

struct				s_edge
{
	t_room			*room;
	t_edge			*next;
};

struct				s_link
{
	char			*name_1;
	char			*name_2;
	t_link			*next;
};

struct				s_data
{
	char			*line;
	t_data			*next;
};

typedef struct		s_maze
{
	unsigned int	number_of_ants;
	t_room			*rooms;
	t_room			*start;
	t_room			*finish;
	t_link			*links;
	t_edge			*queue;
	t_data			*data;
	t_data			*data_copy;
}					t_maze;

/*
**	parse.c
*/
void				parse_rooms(t_maze *maze);
void				parse_links(t_maze *maze);

/*
**	read_data.c
*/
void				read_data(int fd, t_maze *maze);

/*
**	validate.c
*/
void				validate(t_maze *maze);

/*
**	connect_rooms.c
*/
void				connect_rooms(t_maze *maze);

/*
**	find_path.c
*/
void				find_path(t_maze *maze);

/*
**	functions.c
*/
size_t				ft_numlen(unsigned int num);
void				ft_error(char *str);

/*
**	print_result.c
*/
void				print_result(t_maze *maze, unsigned short flag);

#endif
