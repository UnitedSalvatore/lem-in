/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:11:49 by ypikul            #+#    #+#             */
/*   Updated: 2017/12/16 21:50:17 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memjoin(void const *ptr1, size_t n1, void const *ptr2, size_t n2)
{
	void *ptr;

	if (ptr1 == NULL || ptr2 == NULL)
		return (NULL);
	ptr = malloc(n1 + n2);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, ptr1, n1);
	ft_memcpy(ptr + n1, ptr2, n2);
	return (ptr);
}
