/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:54:15 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:33 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*case_p_zero(char *dest)
{
	int		len;

	len = ft_strlen(dest);
	if (g_pre >= 0)
		dest = ft_strjoin_free(get_str_zero(g_pre - len), dest);
	else
	{
		if (g_zero == 1)
			dest = ft_strjoin_free(get_str_zero(g_wth - len - 2), dest);
	}
	return (dest);
}

char		*case_p_space(char *dest)
{
	int		len;

	len = ft_strlen(dest);
	if (g_minus == 1)
		dest = ft_strjoin_free(dest, get_str_space(g_wth - len));
	else
		dest = ft_strjoin_free(get_str_space(g_wth - len), dest);
	return (dest);
}

char		*malloc_zero_p(void)
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

char		*malloc_zero_xp(void)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * 3)))
		return (NULL);
	dest[0] = '0';
	dest[1] = 'x';
	dest[2] = '\0';
	return (dest);
}

char		*get_str_p(void)
{
	unsigned long	n;
	char			*dest;

	n = (unsigned long)va_arg(g_ap, void *);
	if (n == 0)
		dest = malloc_zero_p();
	else
		dest = hexademical_toa(n);
	dest = case_p_zero(dest);
	dest = ft_strjoin_free(malloc_zero_xp(), dest);
	dest = case_p_space(dest);
	return (dest);
}
