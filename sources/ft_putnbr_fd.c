/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:03:22 by hmeftah           #+#    #+#             */
/*   Updated: 2023/01/11 11:16:26 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n)
{
	long	number;
	int		counter;

	counter = 0;
	number = (long)n;
	if (number == -2147483648)
		counter = ft_putstr_fd("-2147483648");
	else if (number < 0)
	{
		counter += ft_putchar_fd('-');
		counter += ft_putnbr_fd(-number);
	}
	else if (number >= 10)
	{
		counter += ft_putnbr_fd(number / 10);
		counter += ft_putnbr_fd(number % 10);
	}
	else
	{
		counter += ft_putchar_fd(number + '0');
	}
	return (counter);
}
