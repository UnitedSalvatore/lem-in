/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:56:31 by ypikul            #+#    #+#             */
/*   Updated: 2018/05/29 19:39:29 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_getline.h"
#include "../libft/include/libft.h"

t_maze	*parse(int fd, t_maze *maze)
{
	char	*str;

	if (ft_getline(fd, &str) != 1)
		ft_error("ERROR");
	maze->number_of_ants = ft_atoi(str);
	ft_strdel(&str);
	
}
