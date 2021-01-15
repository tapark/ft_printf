/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:53:50 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:31 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flag(const char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			g_minus = 1;
		if (str[i] == '0')
			g_zero = 1;
		i++;
	}
	if (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			g_minus = 1;
		i++;
	}
	return (i);
}

int		get_wth(const char *str)
{
	int		i;

	i = 0;
	if (str[i] == '*')
	{
		g_wth = va_arg(g_ap, int);
		i++;
	}
	else if (ft_isdigit(str[i]))
	{
		g_wth = ft_atoi(&str[i]);
		while (ft_isdigit(str[i]))
			i++;
	}
	if (g_wth < 0)
	{
		g_wth = -1 * g_wth;
		g_minus = 1;
		g_zero = 0;
	}
	return (i);
}

int		get_pre(const char *str)
{
	int		i;

	i = 0;
	if (str[i] != '.')
		return (0);
	else
	{
		i++;
		if (str[i] == '*')
		{
			g_pre = va_arg(g_ap, int);
			i++;
		}
		else if (ft_isdigit(str[i]))
		{
			g_pre = ft_atoi(&str[i]);
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			g_pre = 0;
	}
	return (i);
}

int		skip_format(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		else if (str[i] == '0')
			i++;
		else if (str[i] == '.')
			i++;
		else if (str[i] == '*')
			i++;
		else if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			return (i);
	}
	return (0);
}

int		get_format(const char *str)
{
	int		i;

	i = 0;
	i = i + get_flag(&str[i]);
	i = i + get_wth(&str[i]);
	i = i + get_pre(&str[i]);
	i = i + skip_format(&str[i]);
	if (str[i] == '\0')
		g_type = 0;
	else
		g_type = str[i++];
	return (i);
}
