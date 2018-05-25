/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:29:40 by ypikul            #+#    #+#             */
/*   Updated: 2018/05/29 15:39:42 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

typedef struct s_room t_room;
typedef struct s_rooms t_rooms;

struct				s_room
{
	char			*name;
	int				x;
	int				y;
	unsigned int	cost;
	t_rooms			*links;	
};

struct				s_rooms;
{
	t_room			*room;
	t_rooms			*next;
};

typedef struct		s_maze
{
	unsigned int	number_of_ants;
	t_rooms			*rooms;
	t_room			*start;
	t_room			*finish;
}					t_maze;

t_maze		*parse(int fd);
void		ft_error(char *str);

#endif
