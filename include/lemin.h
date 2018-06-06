/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:29:40 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/08 02:45:03 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#ifndef LEMIN_H
# define LEMIN_H

# define ROOM 0
# define START 1
# define FINISH 2

typedef struct s_room	t_room;
typedef struct s_link	t_link;
typedef struct s_data	t_data;

struct				s_room
{
	char			*name;
	int				x;
	int				y;
	unsigned int	ant : 1;
	t_room			*root;
	t_room			*next;
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
	/*
	** data_copy - always points to the first element of the list
	** data - need to equate to the printer before using
	*/
	t_data			*data;
	t_data			*data_copy;
	int				flag;
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
**	errors.c
*/
void				ft_error(char *str);

/*
**	functions.c
*/
size_t				ft_numlen(unsigned int num);

#endif
