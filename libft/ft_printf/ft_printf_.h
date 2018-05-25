/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 04:02:14 by ypikul            #+#    #+#             */
/*   Updated: 2018/03/11 18:27:52 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF__H
# define FT_PRINTF__H

# include <stdarg.h>
# include <stdint.h>
# include <string.h>

# define BUFF_SIZE 64

enum				e_size
{
	NONE, HH, H, LL, L, J, Z
};

struct				s_buffer
{
	char			buf[BUFF_SIZE];
	size_t			size;
	size_t			written;
	int				fd;
};

typedef struct		s_num
{
	char			sign;
	char			*prefix;
	const char		*digits;
	unsigned int	base;
}					t_num;

typedef struct		s_arg
{
	unsigned int	minus : 1;
	unsigned int	zero : 1;
	unsigned int	plus : 1;
	unsigned int	space : 1;
	unsigned int	hash : 1;
	\
	int				min_width;
	int				precision;
	enum e_size		size;
	\
	struct s_buffer	buffer;
}					t_arg;

typedef void		(*t_handler)(const char *, va_list*, t_arg*);

int					ft_printf(const char *format, ...);
void				ft_add_to_buf(const char c, struct s_buffer *buffer);
void				ft_put_width(int data_size, t_arg *spec);

const char			*
ft_parse_flags(const char *format, t_arg *spec);
const char			*
ft_parse_min_width(const char *format, va_list *arg, t_arg *spec);
const char			*
ft_parse_precision(const char *format, va_list *arg, t_arg *spec);
const char			*
ft_parse_size(const char *format, t_arg *spec);
const char			*
ft_handle_conversion(const char *format, va_list *arg, t_arg *spec);

void				ft_handle_char(
						const char *format, va_list *arg, t_arg *spec);
void				ft_handle_wchar(
						const char *format, va_list *arg, t_arg *spec);
void				ft_handle_string(
						const char *format, va_list *arg, t_arg *spec);
void				ft_handle_wstring(
						const char *format, va_list *arg, t_arg *spec);
void				ft_handle_int(
						const char *format, va_list *arg, t_arg *spec);
void				ft_handle_o(
						const char *format, va_list *arg, t_arg *spec);
void				ft_handle_u(
						const char *format, va_list *arg, t_arg *spec);
void				ft_handle_x(
						const char *format, va_list *arg, t_arg *spec);
void				ft_handle_p(
						const char *format, va_list *arg, t_arg *spec);
void				ft_handle_num(
						t_arg *spec, uintmax_t num, t_num *prop);

#endif
