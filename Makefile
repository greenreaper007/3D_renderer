# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:30:13 by flturbou          #+#    #+#              #
#    Updated: 2025/08/25 01:33:08 by flturbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Render_object

CC			=	cc

FLAG		=	-Wall -Wextra -Werror 

LIBFT_PATH	=	./MyLibft/

LIBFT_FILE	=	libft.a

MLX_FILE	=	libmlx.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FLAG	=	-lX11 -lXext

MLX_PATH	=	./minilibx-linux/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		=	main.c end_program.c \
				initialise_values.c copy_file.c \
				parse_object.c parse_vertex.c parse_face.c \
				atof_fast.c

SRC_DIR		=	./sources/

INC_DIR		=	./headers/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ_DIR		=	./sources/object/
OBJ			=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAG) -I$(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJ)
	@echo "\033[0;33m\nCOMPILING Render_object...\n"
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME) -lm
	@echo "\033[1;32m./Render_object created\n"

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(MLX_LIB):
	@make -C $(MLX_PATH)

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting Render_object object...\n"
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting Render_object executable..."
	@rm -f $(NAME)
	@rm -f settings.config
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re