/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:53:13 by tapark            #+#    #+#             */
/*   Updated: 2020/12/15 21:59:27 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_char_null(void)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * 7)))
		return (NULL);
	dest[0] = '(';
	dest[1] = 'n';
	dest[2] = 'u';
	dest[3] = 'l';
	dest[4] = 'l';
	dest[5] = ')';
	dest[6] = '\0';
	return (dest);
}

char	*ft_strdup_null(const char *s1)
{
	char	*dest;
	int		s1_len;
	int		i;

	if (s1 == NULL)
		return (get_char_null());
	s1_len = ft_strlen(s1);
	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	while (i < s1_len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
