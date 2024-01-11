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

$(NAME): $(LIBS)
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
	@echo "Remove SERVER and CLIENT files..."
	@rm -f $(SERVER) $(CLIENT) $(B_CLIENT)
	@make -sC ./lib/ft_printf fclean
	@make -sC ./lib/libft fclean

re: fclean all

.PHONY: all clean fclean re