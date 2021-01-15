/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:54:36 by tapark            #+#    #+#             */
/*   Updated: 2021/01/15 18:16:25 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*case_x_zero(char *dest)
{
	int		len;

	len = ft_strlen(dest);
	if (g_pre >= 0)
		dest = ft_strjoin_free(get_str_zero(g_pre - len), dest);
	else
	{
		if (g_zero == 1)
			dest = ft_strjoin_free(get_str_zero(g_wth - len), dest);
	}
	return (dest);
}

char		*case_x_space(char *dest)
{
	int		len;

	len = ft_strlen(dest);
	if (g_minus == 1)
		dest = ft_strjoin_free(dest, get_str_space(g_wth - len));
	else
		dest = ft_strjoin_free(get_str_space(g_wth - len), dest);
	return (dest);
}

char		*malloc_zero_x(void)
{
	char	*dest;
	int		len;

	if (g_pre < 0)
		len = 2;
	else
		len = 1;
	if (!(dest = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (g_pre < 0)
		dest[0] = '0';
	dest[len - 1] = '\0';
	return (dest);
}

char		*get_str_xx(void)
{
	unsigned int	n;
	char			*dest;

	n = va_arg(g_ap, unsigned int);
	if (n == 0)
		dest = malloc_zero_x();
	else
		dest = hexademical_toa(n);
	dest = case_x_zero(dest);
	dest = case_x_space(dest);
	return (dest);
}
