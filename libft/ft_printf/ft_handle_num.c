/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:39:18 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/05 15:35:08 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_.h"
#include "libft.h"

static void	ft_handle_num2(t_arg *spec, t_num *prop, const int length)
{
	spec->min_width -= ft_strlen(prop->prefix) + length;
	if (prop->sign)
		--spec->min_width;
	if (spec->precision >= 0 && (spec->precision -= length) >= 0)
		spec->min_width -= spec->precision;
	else
		spec->precision = 0;
	if (spec->min_width > 0 && !spec->minus && !spec->zero)
		ft_put_width(0, spec);
	if (prop->sign)
		ft_add_to_buf(prop->sign, &spec->buffer);
	while (*prop->prefix)
		ft_add_to_buf(*prop->prefix++, &spec->buffer);
	while (spec->precision-- > 0)
		ft_add_to_buf('0', &spec->buffer);
	if (spec->min_width > 0 && spec->zero)
		ft_put_width(0, spec);
}

void		ft_handle_num(t_arg *spec, uintmax_t num, t_num *prop)
{
	char		buf[sizeof(intmax_t) * 8];
	char		*p;
	int			length;

	if (spec->precision >= 0)
		spec->zero = 0;
	p = &buf[sizeof(intmax_t) * 8 - 1];
	*p-- = prop->digits[num % prop->base];
	while (num /= prop->base)
		*p-- = prop->digits[num % prop->base];
	if (*(p + 1) == '0' && spec->precision == 0)
		++p;
	length = &buf[sizeof(intmax_t) * 8 - 1] - p;
	if (prop->base == 8 && spec->hash && \
		*(p + 1) != '0' && spec->precision <= length)
		spec->precision = length + 1;
	ft_handle_num2(spec, prop, length);
	while (++p != &buf[sizeof(intmax_t) * 8])
		ft_add_to_buf(*p, &spec->buffer);
	if (spec->min_width > 0 && spec->minus)
		ft_put_width(0, spec);
}
