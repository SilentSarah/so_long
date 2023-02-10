# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 20:22:16 by hmeftah           #+#    #+#              #
#    Updated: 2023/02/10 15:09:12 by hmeftah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIB = libft.a
CC = gcc
AR = ar -rcs
LIB_SRC = ./sources/ft_printf.c ./sources/ft_putadress.c ./sources/ft_putbase_fd.c ./sources/ft_putbase_fdLower.c \
		  ./sources/ft_putchar_fd.c ./sources/ft_putnbr_fd.c ./sources/ft_putnbr_fd_unsigned.c ./sources/ft_putstr_fd.c \
		  ./sources/ft_strnstr.c ./sources/ft_split.c ./sources/ft_substr.c ./sources/ft_memset.c \
		  ./sources/ft_bzero.c ./sources/ft_calloc.c ./sources/get_next_line.c ./sources/get_next_line_utils.c \
		  ./sources/ft_strjoin.c ./sources/ft_strncmp.c ./sources/ft_strchr.c 
SL_SRC = main.c map_parser.c map_utils.c general_utils.c texture_load_check.c load_map_textures.c game_hooks.c
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I so_long.h -I ./sources/ft_printf.h -I ./sources/get_next_line.h
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIB) $(SL_SRC)
	$(CC) $(FLAGS) $(INCLUDES) $(MLX) $(LIB) $(LIB_SRC) $(SL_SRC) -o $@

$(LIB): $(LIB_SRC) $(LIB_SRC:.c=.o)
	$(AR) $(LIB) $(LIB_SRC:.c=.o)

./sources/%.o: ./sources/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	
fclean: clean
	@echo "Removing Executable and library"
	@rm -rf so_long
	@rm -rf libft.a

clean:
	@echo "Removing Object Files"
	@rm -rf ./sources/*.o

re : fclean all