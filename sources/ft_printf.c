/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:53:20 by hmeftah           #+#    #+#             */
/*   Updated: 2023/01/10 20:19:12 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printassist(const char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'd' || c == 'i')
		i += ft_putnbr_fd(va_arg(args, int));
	else if (c == 'u')
		i += ft_putnbr_fd_unsigned(va_arg(args, unsigned int));
	else if (c == 'c')
		i += ft_putchar_fd(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr_fd(va_arg(args, char *));
	else if (c == '%')
		i += ft_putchar_fd('%');
	else if (c == 'x')
		i += ft_putbase_fd_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		i += ft_putbase_fd(va_arg(args, unsigned int));
	else if (c == 'p')
		i += ft_putadress(va_arg(args, void *));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			i += printassist(*(format + 1), args);
			format ++;
		}
		else
			i += ft_putchar_fd(*format);
		format++;
	}
	va_end(args);
	return (i);
}
