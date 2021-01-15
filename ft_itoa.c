/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:44:55 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:23 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		itoa_len(int n)
{
	int len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(unsigned int n)
{
	char	*dest;
	int		len;
	long	av;
	int		i;

	len = itoa_len(n);
	i = 1;
	av = (long)n;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	dest[len] = '\0';
	while (len - i != -1)
	{
		dest[len - i] = av % 10 + '0';
		av = av / 10;
		i++;
	}
	return (dest);
}
