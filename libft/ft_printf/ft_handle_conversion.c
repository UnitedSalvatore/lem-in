/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:32:20 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/05 15:35:14 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_.h"
#include "libft.h"

static t_handler	ft_get_handler(t_handler handlers[], int num)
{
	handlers[0] = &ft_handle_string;
	handlers[1] = &ft_handle_wstring;
	handlers[2] = &ft_handle_p;
	handlers[3] = &ft_handle_int;
	handlers[4] = &ft_handle_int;
	handlers[5] = &ft_handle_int;
	handlers[6] = &ft_handle_o;
	handlers[7] = &ft_handle_o;
	handlers[8] = &ft_handle_u;
	handlers[9] = &ft_handle_u;
	handlers[10] = &ft_handle_x;
	handlers[11] = &ft_handle_x;
	handlers[12] = &ft_handle_char;
	handlers[13] = &ft_handle_wchar;
	handlers[14] = &ft_handle_char;
	return (handlers[num]);
}

const char			*ft_handle_conversion(
	const char *format,
	va_list *arg,
	t_arg *spec
)
{
	const char	conversion_str[] = "sSpdDioOuUxXcC%";
	const char	*conversion_chr;
	t_handler	handlers[15];
	t_handler	handler;

	if (*format)
	{
		if ((conversion_chr = ft_strchr(conversion_str, *format)))
		{
			if (ft_strchr("DOUCS", *format))
				spec->size = L;
			handler = ft_get_handler(handlers, conversion_chr - conversion_str);
			handler(format, arg, spec);
		}
		else
		{
			if (spec->min_width && !spec->minus)
				ft_put_width(sizeof(char), spec);
			ft_add_to_buf(*format, &spec->buffer);
			if (spec->min_width && spec->minus)
				ft_put_width(sizeof(char), spec);
		}
		++format;
	}
	return (format);
}
