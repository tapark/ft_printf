/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:54:25 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:35 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_str_space(int n)
{
	char	*space;
	int		i;

	i = 0;
	if (n < 0)
		n = 0;
	if (!(space = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n)
		space[i++] = ' ';
	space[i] = '\0';
	return (space);
}
