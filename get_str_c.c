/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:53:55 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:31 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_null_space(int n)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	write(1, &c, 1);
	while (i < n)
	{
		write(1, " ", 1);
		i++;
	}
	return (1 + i);
}

int		ft_put_space_null(int n)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (i < n)
	{
		write(1, " ", 1);
		i++;
	}
	write(1, &c, 1);
	return (1 + i);
}

int		write_case_c(char *dest)
{
	int		len;

	len = ft_strlen(dest);
	if (g_zero == 1)
		dest = ft_strjoin_free(get_str_zero(g_wth - len), dest);
	len = ft_strlen(dest);
	if (g_minus == 1)
		dest = ft_strjoin_free(dest, get_str_space(g_wth - len));
	else
		dest = ft_strjoin_free(get_str_space(g_wth - len), dest);
	ft_putstr_fd(dest, 1);
	len = ft_strlen(dest);
	free(dest);
	return (len);
}

int		get_str_c(void)
{
	char	c;
	char	*dest;
	int		len;

	if (g_type == 'c')
		c = va_arg(g_ap, int);
	else
		c = g_type;
	if (!(dest = (char *)malloc(sizeof(char *) * 2)))
		return (0);
	dest[0] = c;
	dest[1] = '\0';
	if (c == 0)
	{
		if (g_minus == 1)
			len = ft_put_null_space(g_wth - 1);
		else
			len = ft_put_space_null(g_wth - 1);
	}
	else
		len = write_case_c(dest);
	return (len);
}
