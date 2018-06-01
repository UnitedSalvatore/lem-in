/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:29:40 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/04 16:17:01 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define ROOM 0;
# define START 1;
# define FINISH 2;

typedef struct s_room	t_room;
typedef struct s_link	t_link;

struct				s_room
{
	char			*name;
	int				x;
	int				y;
	unsigned int	cost;
	t_room			*next;
};

struct				s_link
{
	t_room			*room;
	t_rooms			*next;

};

typedef struct		s_maze
{
	unsigned int	number_of_ants;
	t_room			*rooms;
	t_room			*start;
	t_room			*finish;
	t_link			*links;
	\
	char			*str;
}					t_maze;

/*
**	parse_rooms.c
*/
void				parse_rooms(int fd, t_maze *maze);

/*
**	parse_rooms.c
*/
void				parse_links(int fd, t_maze *maze, char **split);

/*
**	errors.c
*/
void				ft_error(char *str);

/*
**	functions.c
*/
size_t				ft_numlen(unsigned int num);

#endif
