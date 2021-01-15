/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:54:05 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:32 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*case_d_zero(char *dest, int sign)
{
	int		len;

	len = ft_strlen(dest);
	if (g_pre >= 0)
		dest = ft_strjoin_free(get_str_zero(g_pre - len), dest);
	else
	{
		if (g_zero == 1)
			dest = ft_strjoin_free(get_str_zero(g_wth - len - sign), dest);
	}
	return (dest);
}

char		*case_d_space(char *dest)
{
	int		len;

	len = ft_strlen(dest);
	if (g_minus == 1)
		dest = ft_strjoin_free(dest, get_str_space(g_wth - len));
	else
		dest = ft_strjoin_free(get_str_space(g_wth - len), dest);
	return (dest);
}

char		*malloc_zero(void)
{
	char	*dest;
	int		len;

	if (g_pre < 0)
		len = 2;
	else
		len = 1;
	if (!(dest = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	if (g_pre < 0)
		dest[0] = '0';
	dest[len - 1] = '\0';
	return (dest);
}

char		*get_str_d(void)
{
	int		n;
	char	*dest;
	int		sign;

	n = va_arg(g_ap, int);
	sign = 0;
	if (n > 0)
		dest = ft_itoa(n);
	else if (n == 0)
		dest = malloc_zero();
	else
	{
		dest = ft_itoa(n * -1);
		sign = 1;
	}
	dest = case_d_zero(dest, sign);
	if (sign == 1)
		dest = ft_strjoin_free(get_str_minus(), dest);
	dest = case_d_space(dest);
	return (dest);
}
