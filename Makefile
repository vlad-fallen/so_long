# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 15:40:50 by mbutter           #+#    #+#              #
#    Updated: 2022/02/17 12:01:34 by mbutter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	src/so_long.c \
				src/create_game.c \
				src/create_map.c \
				src/check_map.c \
				src/render_map.c \
				src/open_image.c \
				src/movement.c \
				src/event.c \
				src/utils.c 

OBJS		=	$(patsubst %.c,%.o,$(SRCS)) 

BONUS		=	

BONUS_OBJS	=	$(patsubst %.c,%.o,$(BONUS))

D_FILES		=	$(patsubst %.c,%.d,$(SRCS) $(BONUS)) 

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g -I ./includes -I ./libft

MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit

BONUS_NAME	=	

all:		$(NAME)

$(NAME):	$(OBJS) Makefile 
			@make -C ./libft
			@make -C ./mlx
			$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) ./libft/libft.a -o $(NAME) -MMD

%.o:		%.c
			$(CC) $(CFLAGS) -I ./mlx -c $< -o $@ -MMD

clean:
			$(RM) $(OBJS) $(D_FILES) $(BONUS_OBJS) $(D_FILES_B)
			@make clean -C ./libft
			@make clean -C ./mlx

fclean:		clean
			$(RM) $(NAME) $(BONUS_NAME)
			@make fclean -C ./libft

re:			fclean $(NAME)

bonus:		$(BONUS_OBJS)
			@make -C ./libft
			$(CC) $(CFLAGS) $(BONUS_OBJS) ./libft/libft.a -o $(BONUS_NAME) -MMD


.PHONY:		all clean fclean re bonus

include $(wildcard $(D_FILES))
