# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbutter <mbutter@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 15:40:50 by mbutter           #+#    #+#              #
#    Updated: 2022/02/15 19:00:02 by mbutter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	so_long.c \
				create_game.c \
				create_map.c \
				check_map.c \
				render_map.c \
				open_image.c \
				movement.c \
				event.c \
				utils.c 

#TEST
#SRCS		=	main.c

OBJS		=	$(patsubst %.c,%.o,$(SRCS)) 

BONUS		=	

BONUS_OBJS	=	$(patsubst %.c,%.o,$(BONUS))

D_FILES		=	$(patsubst %.c,%.d,$(SRCS) $(BONUS)) 

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

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
