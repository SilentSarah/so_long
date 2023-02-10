/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:12:16 by hmeftah           #+#    #+#             */
/*   Updated: 2023/02/07 15:37:33 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf.h"

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_lookforchar(char *str, char c);
char		*ft_joinstring(char *updatedbuffer, char *originalbuffer);

#endif