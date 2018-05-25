/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ouxp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 04:09:11 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/05 15:35:04 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_.h"

static uintmax_t	ft_get_size(va_list *arg, enum e_size *size)
{
	uintmax_t	num;

	num = va_arg(*arg, uintmax_t);
	if (*size == HH)
		return ((unsigned char)num);
	if (*size == H)
		return ((unsigned short)num);
	if (*size == LL)
		return ((unsigned long)num);
	if (*size == L)
		return ((unsigned long long)num);
	if (*size == J)
		return (num);
	if (*size == Z)
		return ((size_t)num);
	else
		return ((unsigned int)num);
}

void				ft_handle_o(const char *format, va_list *arg, t_arg *spec)
{
	uintmax_t	unbr;
	t_num		prop;

	(void)format;
	unbr = ft_get_size(arg, &spec->size);
	prop.sign = '\0';
	prop.prefix = "";
	prop.base = 8;
	prop.digits = "01234567";
	ft_handle_num(spec, unbr, &prop);
}

void				ft_handle_u(const char *format, va_list *arg, t_arg *spec)
{
	uintmax_t	unbr;
	t_num		prop;

	(void)format;
	unbr = ft_get_size(arg, &spec->size);
	prop.sign = '\0';
	prop.prefix = "";
	prop.base = 10;
	prop.digits = "0123456789";
	ft_handle_num(spec, unbr, &prop);
}

void				ft_handle_x(const char *format, va_list *arg, t_arg *spec)
{
	uintmax_t	unbr;
	t_num		prop;

	unbr = ft_get_size(arg, &spec->size);
	prop.sign = '\0';
	if (unbr && spec->hash)
	{
		if (*format == 'X')
			prop.prefix = "0X";
		else
			prop.prefix = "0x";
	}
	else
		prop.prefix = "";
	if (*format == 'X')
		prop.digits = "0123456789ABCDEF";
	else
		prop.digits = "0123456789abcdef";
	prop.base = 16;
	ft_handle_num(spec, unbr, &prop);
}

void				ft_handle_p(const char *format, va_list *arg, t_arg *spec)
{
	uintmax_t	unbr;
	t_num		prop;

	(void)format;
	unbr = (uintmax_t)va_arg(*arg, void *);
	prop.sign = '\0';
	prop.prefix = "0x";
	prop.digits = "0123456789abcdef";
	prop.base = 16;
	ft_handle_num(spec, unbr, &prop);
}
