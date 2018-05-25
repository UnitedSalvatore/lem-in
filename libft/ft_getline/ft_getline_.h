/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline_.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 04:42:26 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/05 15:32:33 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETLINE__H
# define FT_GETLINE__H

# include <string.h>

# define BUFF_SIZE 64
# define MALLCHECK(ptr) if (!ptr) return (-1)

typedef struct		s_lst_fd
{
	int				fd;
	size_t			size;
	char			*content;
	struct s_lst_fd	*next;
}					t_lst_fd;

#endif
