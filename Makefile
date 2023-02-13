# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 20:22:16 by hmeftah           #+#    #+#              #
#    Updated: 2023/02/13 12:53:20 by hmeftah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

LIB = libft.a

CC = gcc

AR = ar -rcs

LIB_SRC = ./sources/ft_printf.c ./sources/ft_putadress.c ./sources/ft_putbase_fd.c ./sources/ft_putbase_fdLower.c \
		  ./sources/ft_putchar_fd.c ./sources/ft_putnbr_fd.c ./sources/ft_putnbr_fd_unsigned.c ./sources/ft_putstr_fd.c \
		  ./sources/ft_strnstr.c ./sources/ft_split.c ./sources/ft_substr.c ./sources/ft_memset.c \
		  ./sources/ft_bzero.c ./sources/ft_calloc.c ./sources/get_next_line.c ./sources/get_next_line_utils.c \
		  ./sources/ft_strjoin.c ./sources/ft_strncmp.c ./sources/ft_strchr.c ./sources/ft_itoa.c
		  
SL_SRC = main.c map_parser.c map_utils.c general_utils.c texture_load_check.c load_map_textures.c game_hooks.c

SL_B_SRC = main_bonus.c map_parser_bonus.c map_utils_bonus.c general_utils_bonus.c texture_load_check_bonus.c \
		   load_map_textures_bonus.c game_hooks_bonus.c map_parse_support.c game_update_bonus.c bot_path_bonus.c \
		   bot_to_path.c
		   
FLAGS = -Wall -Werror -Wextra

INCLUDES = -I so_long.h -I ./sources/ft_printf.h -I ./sources/get_next_line.h

INCLUDES_B = -I so_long_bonus.h -I ./sources/ft_printf.h -I ./sources/get_next_line.h

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(LIB): $(LIB_SRC) $(LIB_SRC:.c=.o)
	$(AR) $(LIB) $(LIB_SRC:.c=.o)

$(NAME): $(LIB) $(SL_SRC)
	$(CC) $(FLAGS) $(INCLUDES) $(MLX) $(LIB) $(LIB_SRC) $(SL_SRC) -o $@

bonus: $(BONUS)

$(BONUS): $(LIB) $(SL_B_SRC)
	$(CC) $(FLAGS) $(INCLUDES_B) $(MLX) $(LIB) $(LIB_SRC) $(SL_B_SRC) -o $@

./sources/%.o: ./sources/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	
fclean: clean
	@echo "Removing Executables and library"
	@rm -rf so_long
	@rm -rf so_long_bonus
	@rm -rf libft.a

clean:
	@echo "Removing Object Files"
	@rm -rf ./sources/*.o

re : fclean clean all bonus