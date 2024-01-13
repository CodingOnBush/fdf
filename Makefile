# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momrane <momrane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 09:27:46 by momrane           #+#    #+#              #
#    Updated: 2024/01/13 13:54:13 by momrane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			cc
WFLAGS =		-Wall -Wextra -g #-Werror
MFLAGS =		$(WFLAGS) -Lmlx_linux -L/lib -Imlx_linux -lXext -lX11 -lm -lz

NAME = 			fdf

BINDIR = 		./bin
INCDIR = 		./inc
SRCDIR = 		./src

PRINTF =		./lib/ft_printf/libftprintf.a
LIBFT =			./lib/libft/libft.a
MLX =			./lib/mlx/libmlx.a
LIBS =			$(PRINTF) $(LIBFT) $(MLX)

SRC =			$(SRCDIR)/main.c $(SRCDIR)/parsing.c $(SRCDIR)/gnl/ft_gnl.c \
				$(SRCDIR)/gnl/gnl_utils.c $(SRCDIR)/errors.c $(SRCDIR)/point.c \
				$(SRCDIR)/free.c

OBJ =			$(SRC:$(SRCDIR)/%.c=$(BINDIR)/%.o)

all: $(NAME)

run: $(NAME)
	@echo "Running..."
	@./$(NAME)

$(NAME): $(LIBS) $(OBJ)
	@echo "Compiling..."
	@$(CC) $(MFLAGS) -I$(INCDIR) $(OBJ) $(LIBS) -o $(NAME)

$(BINDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(WFLAGS) -I$(INCDIR) -Imlx_linux -O3 -c $< -o $@

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