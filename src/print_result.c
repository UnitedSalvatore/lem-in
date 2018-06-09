/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:44:12 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/09 16:16:04 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"
#include "../libft/include/ft_printf.h"

static void	print_data(t_data *data)
{
	while (data)
	{
		ft_printf("%s\n", data->line);
		data = data->next;
	}
	ft_printf("\n");
}

void		print_result(t_maze *maze, unsigned short flag)
{
	t_room			*rooms;
	unsigned int	i;

	print_data(maze->data_copy);
	maze->start->ant = maze->number_of_ants;
	while (maze->finish->ant != maze->number_of_ants)
	{
		rooms = maze->finish;
		i = maze->finish->ant;
		while (rooms != maze->start)
		{
			if (rooms->root->ant)
			{
				rooms->root->ant -= 1;
				rooms->ant += 1;
				ft_printf("L%u-%s", ++i, rooms->name);
				if (!flag)
					flag = 1;
				else
					ft_printf(" ");
			}
			rooms = rooms->root;
		}
		ft_printf("\n");
	}
}
