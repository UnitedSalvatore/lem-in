/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:45:03 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/13 20:51:43 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_splitdel(char ***as)
{
	char	**ptr;

	if (as && *as)
	{
		ptr = *as;
		while (*ptr)
		{
			free(*ptr);
			*ptr = NULL;
			++ptr;
		}
		free(*as);
		*as = NULL;
	}
}
