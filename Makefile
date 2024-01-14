# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momrane <momrane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 09:27:46 by momrane           #+#    #+#              #
#    Updated: 2024/01/14 14:01:15 by momrane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME 			:= fdf
SRC_DIR			:= ./src
OBJ_DIR 		:= ./obj
INC_DIR 		:= ./inc
LIB_DIR 		:= ./lib
CC				:= gcc
CFLAGS			:= -g -O3 -Wall -Werror -Wextra
FT_PRINTF_DIR	:= $(LIB_DIR)/ft_printf
FT_PRINTF		:= $(FT_PRINTF_DIR)/libftprintf.a
MINILIBX_DIR	:= $(LIB_DIR)/mlx_linux
MINILIBX		:= $(MINILIBX_DIR)/libmlx.a
MINILIBX_FLAGS	:= -Lmlx_linux -L/$(LIB_DIR) -Imlx_linux -lXext -lX11 -lm -lz
LIBFT_DIR		:= $(LIB_DIR)/libft
LIBFT			:= $(LIBFT_DIR)/libft.a
LIBS 			:= $(FT_PRINTF) $(LIBFT) $(MINILIBX)
HEADER			:= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(MINILIBX_DIR)

# Colors
DEF_COLOR		= \033[0;39m
GREEN 			= \033[0;92m
CYAN 			= \033[0;96m

#Sources
SRC_FILES 		= errors free ft_gnl gnl_utils main parsing point
SRC 			= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ				= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

#Rules
all: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	@$(CC) $(HEADER) $(OBJ) $(LIBS) $(MINILIBX_FLAGS) -o $(NAME)
			
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADER) -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	@make -sC $(LIBFT_DIR)
	@echo "$(GREEN)libft compiled!$(DEF_COLOR)"

$(FT_PRINTF):
	@make -sC $(FT_PRINTF_DIR)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(MINILIBX):
	@make -sC $(MINILIBX_DIR)
	@echo "$(GREEN)Minilibx compiled!$(DEF_COLOR)"

clean:
	@make -sC $(FT_PRINTF_DIR) clean
	@echo "$(CYAN)ft_printf object and dependency files cleaned.$(DEF_COLOR)"
	@make -sC $(LIBFT_DIR) clean
	@echo "$(CYAN)Libft object files cleaned.$(DEF_COLOR)"
	@make -sC $(MINILIBX_DIR) clean
	@echo "$(CYAN)Minilibx object files cleaned.$(DEF_COLOR)"	
	@rm -rf $(OBJ_DIR)
	@echo "$(CYAN)Fdf object files cleaned!$(DEF_COLOR)"

fclean: clean
	@make -sC $(FT_PRINTF_DIR) fclean
	@echo "$(CYAN)libftprintf.a LIB_DIR cleaned!$(DEF_COLOR)"
	@make -sC $(LIBFT_DIR) fclean
	@echo "$(CYAN)libft.a LIB_DIR cleaned!$(DEF_COLOR)"
	@rm -f $(NAME)
	@echo "$(CYAN)Fdf executable files cleaned!$(DEF_COLOR)"

re: fclean $(NAME)
	@echo "$(GREEN)Cleaned and rebuilt everything for Fdf!$(DEF_COLOR)"

norm:
	@norminette $(SRC) $(INC_DIR)/*.h

.PHONY:	all clean fclean re norm
