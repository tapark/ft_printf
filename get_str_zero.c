/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:54:41 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:37 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_str_zero(int n)
{
	char	*zero;
	int		i;

	i = 0;
	if (n < 0)
		n = 0;
	if (!(zero = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n)
		zero[i++] = '0';
	zero[n] = '\0';
	return (zero);
}
