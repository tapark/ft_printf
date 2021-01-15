/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:53:44 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:30 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		utoa_len(unsigned int n)
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

char	*ft_utoa(unsigned int n)
{
	char	*dest;
	int		len;
	int		i;

	len = utoa_len(n);
	i = 1;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	while (len - i != -1)
	{
		dest[len - i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	return (dest);
}
