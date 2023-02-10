/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:20:53 by hmeftah           #+#    #+#             */
/*   Updated: 2023/01/10 20:19:26 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase_fd(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n < 16)
	{
		counter += ft_putchar_fd("0123456789ABCDEF"[n % 16]);
	}
	else if (n <= 9)
		counter += ft_putnbr_fd(n);
	else
	{
		counter += ft_putbase_fd(n / 16);
		counter += ft_putbase_fd(n % 16);
	}
	return (counter);
}
