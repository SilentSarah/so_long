/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:25:59 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/12 12:07:00 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

int		ft_printf(const char *format, ...);
int		ft_putbase_fd_lower(unsigned int n);
int		ft_putnbr_fd_unsigned(unsigned int n);
int		ft_putbase_fd(unsigned int n);
int		ft_putadress(void *ptr);
int		ft_putstr_fd(char *s);
int		ft_putnbr_fd(int n);
int		ft_putchar_fd(char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	countdelims(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
#endif