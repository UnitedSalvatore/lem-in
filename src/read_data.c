/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:16:25 by ypikul            #+#    #+#             */
/*   Updated: 2018/06/05 19:14:44 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_getline.h"
#include "../include/lemin.h"
#include <string.h>

static	void	add_to_end(t_data **data, t_data *new)
{
	t_data	*head;

	if (*data)
	{
		head = *data;
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		*data = new;
}

void	read_data(int fd, t_maze *maze)
{
	char	*str;
	t_link	*data;

	while (ft_getline(fd, &str) > 0)
	{
		if (!(data = ft_memalloc(sizeof(t_data))))
			ft_error("Error while allocating memory");
		data->line = str;
		add_to_end(maze->data, data);
		str = NULL;
	}
	maze->data_copy = maze->data;
}
