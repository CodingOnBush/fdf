# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momrane <momrane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 09:27:46 by momrane           #+#    #+#              #
#    Updated: 2024/01/15 14:38:35 by momrane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME 			:= fdf
SRC_DIR			:= ./src
OBJ_DIR 		:= ./obj
INC_DIR 		:= ./inc
LIB_DIR 		:= ./lib
CC				:= gcc
CFLAGS			:= -g -O3 -Wall -Wextra #-Werror
FT_PRINTF_DIR	:= $(LIB_DIR)/ft_printf
FT_PRINTF		:= $(FT_PRINTF_DIR)/libftprintf.a
MINILIBX_DIR	:= $(LIB_DIR)/mlx
MINILIBX		:= $(MINILIBX_DIR)/libmlx.a
MLX_LINUX		:= -Lmlx -L/$(LIB_DIR) -Imlx -lXext -lX11 -lm -lz
LIBFT_DIR		:= $(LIB_DIR)/libft
LIBFT			:= $(LIBFT_DIR)/libft.a
LIBS 			:= $(FT_PRINTF) $(LIBFT) $(MINILIBX)
HEADER			:= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(MINILIBX_DIR)

# Colors
DEF_COLOR		= \033[0;39m
GREEN 			= \033[0;92m
CYAN 			= \033[0;96m

#Sources
SRC_FILES 		= errors free ft_gnl gnl_utils main parsing point hook
SRC 			= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ				= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

#Rules
all: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	@$(CC) $(HEADER) $(OBJ) $(LIBS) $(MLX_LINUX) -o $(NAME)
	@echo "$(GREEN)Fdf compiled!$(DEF_COLOR)"
			
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADER) -Imlx -O3 -c $< -o $@

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
	@rm -rf $(OBJ_DIR)
	@make -sC $(FT_PRINTF_DIR) clean
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(MINILIBX_DIR) clean
	@echo "$(CYAN)Fdf, Minilibx, Libft and ft_printf object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(FT_PRINTF_DIR) fclean
	@make -sC $(LIBFT_DIR) fclean
	@echo "$(CYAN)libftprintf.a, libft.a and fdf cleaned!$(DEF_COLOR)"

re: fclean $(NAME)
	@echo "$(GREEN)Cleaned and rebuilt everything for Fdf!$(DEF_COLOR)"

norm:
	@norminette $(SRC) $(INC_DIR)/*.h

.PHONY:	all clean fclean re norm
