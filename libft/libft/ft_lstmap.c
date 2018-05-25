/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:32:51 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/29 16:58:29 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	list = f(lst);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
		{
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
