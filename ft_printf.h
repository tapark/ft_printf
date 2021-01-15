/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tg911022@naver.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:53:01 by tapark            #+#    #+#             */
/*   Updated: 2021/01/14 15:06:38 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

extern va_list	g_ap;

int		g_minus;
int		g_zero;
int		g_wth;
int		g_pre;
char	g_type;

int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strdup_null(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_isdigit(char s);
int		ft_atoi(const char *str);
char	*ft_itoa(unsigned int n);
char	*ft_utoa(unsigned int n);
char	*hexademical_toa(unsigned long n);

int		get_format(const char *str);

char	*get_str_zero(int n);
char	*get_str_space(int n);
char	*get_str_minus(void);
char	*get_str_d(void);
char	*get_str_u(void);
char	*get_str_xx(void);
int		get_str_c(void);
char	*get_str_s(void);
char	*get_str_p(void);

int		ft_printf(const char *str, ...);

#endif
