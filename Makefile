# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momrane <momrane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 09:27:46 by momrane           #+#    #+#              #
#    Updated: 2024/01/12 10:30:02 by momrane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			cc
CFLAGS =		-Wall -Wextra -Werror 

NAME = 			fdf

BINDIR = 		./bin
INCDIR = 		./inc
SRCDIR = 		./src

PRINTF =		./lib/ft_printf/libftprintf.a
LIBFT =			./lib/libft/libft.a
MLX =			./lib/mlx/libmlx.a
LIBS =			$(PRINTF) $(LIBFT) $(MLX)

SRC =			$(SRCDIR)/main.c
OBJ =			$(SRC:$(SRCDIR)/%.c=$(BINDIR)/%.o)

all: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) -Lmlx_linux -L/lib -Imlx_linux -lXext -lX11 -lm -lz -I$(INCDIR) $(OBJ) $(LIBS) -o $(NAME)

$(BINDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCDIR) -Imlx_linux -O3 -c $< -o $@

$(LIBS):
	@echo "LIBS compiling..."
	@make -sC ./lib/ft_printf all
	@make -sC ./lib/libft all
	@make -sC ./lib/mlx all

clean:
	@echo "Remove object files..."
	@rm -rf $(BINDIR)
	@make -sC ./lib/ft_printf clean
	@make -sC ./lib/libft clean

fclean: clean
	@echo "Remove everything..."
	@rm -f $(NAME)
	@make -sC ./lib/ft_printf fclean
	@make -sC ./lib/libft fclean
	@make -sC ./lib/mlx clean

re: fclean all

.PHONY: all clean fclean re