/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:54:09 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:33 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_str_minus(void)
{
	char	*minus;

	if (!(minus = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	minus[0] = '-';
	minus[1] = '\0';
	return (minus);
}
