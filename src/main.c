/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:29:07 by ypikul            #+#    #+#             */
/*   Updated: 2018/05/29 15:46:51 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"
#include "../libft/include/libft.h"

int main(void)
{
	t_maze	maze;

	ft_bzero(&maze, sizeof(t_maze));
	parse(0, &maze);
	return (0);
}
