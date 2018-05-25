/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 05:06:57 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/05 15:35:01 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf_.h"
#include "libft.h"

static void		ft_putwchar(wchar_t c, struct s_buffer *buffer)
{
	if (c <= 0x7F)
		ft_add_to_buf(c, buffer);
	else if (c <= 0x7FF)
	{
		ft_add_to_buf((c >> 6) | 0xC0, buffer);
		ft_add_to_buf(((c & 0x3F) | 0x80), buffer);
	}
	else if (c <= 0xFFFF)
	{
		ft_add_to_buf((c >> 12) | 0xE0, buffer);
		ft_add_to_buf(((c >> 6) & 0x3F) | 0x80, buffer);
		ft_add_to_buf((c & 0x3F) | 0x80, buffer);
	}
	else if (c <= 0x1FFFFF)
	{
		ft_add_to_buf(((c >> 18) | 0xF0), buffer);
		ft_add_to_buf(((c >> 12) & 0x3F) | 0x80, buffer);
		ft_add_to_buf(((c >> 6) & 0x3F) | 0x80, buffer);
		ft_add_to_buf((c & 0x3F) | 0x80, buffer);
	}
}

static size_t	ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i += 1;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x1FFFFF)
			i += 4;
		++str;
	}
	return (i);
}

static size_t	ft_wcharlen(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x1FFFFF)
		return (4);
	return (0);
}

void			ft_handle_wstring(const char *format, va_list *arg, t_arg *spec)
{
	wchar_t	*str;
	size_t	length;
	size_t	i;

	(void)format;
	i = 0;
	str = va_arg(*arg, wchar_t *);
	if (!str)
		str = L"(null)";
	length = ft_wstrlen(str);
	if (spec->precision >= 0 && (int)length > spec->precision)
		length = spec->precision;
	if (spec->min_width && !spec->minus)
		ft_put_width(length, spec);
	while (*str && (i += ft_wcharlen(*str)) <= length)
		ft_putwchar(*str++, &spec->buffer);
	if (spec->min_width && spec->minus)
		ft_put_width(length, spec);
}

void			ft_handle_string(const char *format, va_list *arg, t_arg *spec)
{
	char	*str;
	size_t	length;
	size_t	i;

	(void)format;
	if (spec->size == L)
		return (ft_handle_wstring(format, arg, spec));
	str = va_arg(*arg, char *);
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (spec->precision >= 0 && (int)length > spec->precision)
		length = spec->precision;
	if (spec->min_width && !spec->minus)
		ft_put_width(length, spec);
	i = 0;
	while (*str && i++ < length)
		ft_add_to_buf(*str++, &spec->buffer);
	if (spec->min_width && spec->minus)
		ft_put_width(length, spec);
}
