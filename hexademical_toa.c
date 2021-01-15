/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexademical_toa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:54:51 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:38 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		hexademical_len(unsigned long n)
{
	int		len;

	len = 0;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char		*hexademical_toa(unsigned long n)
{
	char			*dest;
	int				len;
	unsigned long	rest;

	len = hexademical_len(n);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	while (n)
	{
		rest = n % 16;
		if (rest < 10)
			dest[--len] = rest + '0';
		else
		{
			if (g_type == 'x' || g_type == 'p')
				dest[--len] = rest - 10 + 'a';
			else
				dest[--len] = rest - 10 + 'A';
		}
		n = n / 16;
	}
	return (dest);
}
