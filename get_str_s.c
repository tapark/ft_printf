/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:54:21 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:34 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_str_s(void)
{
	char	*dest;
	int		len;

	dest = ft_strdup_null(va_arg(g_ap, char *));
	if (g_pre >= 0)
		dest = ft_substr(dest, 0, g_pre);
	len = ft_strlen(dest);
	if (g_zero == 1)
		dest = ft_strjoin_free(get_str_zero(g_wth - len), dest);
	len = ft_strlen(dest);
	if (g_minus == 1)
		dest = ft_strjoin_free(dest, get_str_space(g_wth - len));
	else
		dest = ft_strjoin_free(get_str_space(g_wth - len), dest);
	return (dest);
}
