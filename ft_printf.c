/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:52:33 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:24 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list	g_ap;

int				write_format(void)
{
	char	*dest;
	int		len;

	if (g_type == 'd' || g_type == 'i')
		dest = get_str_d();
	else if (g_type == 'u')
		dest = get_str_u();
	else if (g_type == 'x' || g_type == 'X')
		dest = get_str_xx();
	else if (g_type == 's')
		dest = get_str_s();
	else if (g_type == 'p')
		dest = get_str_p();
	else
		len = get_str_c();
	if (g_type == 'd' || g_type == 'i' || g_type == 'u' || g_type == 'x' ||
		g_type == 'X' || g_type == 's' || g_type == 'p')
	{
		ft_putstr_fd(dest, 1);
		len = ft_strlen(dest);
		free(dest);
	}
	return (len);
}

static void		default_format(void)
{
	g_zero = 0;
	g_minus = 0;
	g_wth = 0;
	g_pre = -1;
	g_type = 0;
}

int				ft_printf(const char *str, ...)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(g_ap, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i++], 1);
			len++;
		}
		else if (str[i++] == '%')
		{
			default_format();
			i = i + get_format(&str[i]);
			len = len + write_format();
		}
	}
	va_end(g_ap);
	return (len);
}
