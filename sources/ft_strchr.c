/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:23:11 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/11 16:34:27 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] || (!s[i] && !c))
	{		
		if ((unsigned char )s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		if (s[i] == '\0')
			return (NULL);
	}
	return (NULL);
}
