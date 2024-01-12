# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momrane <momrane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 09:27:46 by momrane           #+#    #+#              #
#    Updated: 2024/01/12 09:56:09 by momrane          ###   ########.fr        #
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
LIBS =			$(PRINTF) $(LIBFT)

SRC =			$(SRCDIR)/main.c
OBJ =			$(SRC:$(SRCDIR)/%.c=$(BINDIR)/%.o)

all: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) -I$(INCDIR) $(OBJ) $(LIBS) -o $(NAME)

$(BINDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(LIBS):
	@echo "LIBS compiling..."
	@make -sC ./lib/ft_printf all
	@make -sC ./lib/libft all

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

re: fclean all

.PHONY: all clean fclean re