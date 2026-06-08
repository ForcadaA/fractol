# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/16 17:59:28 by aforcada          #+#    #+#              #
#    Updated: 2026/06/08 11:44:05 by aforcada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

DMLX = ./mlx

DLIBFT = ./libft

CC = gcc

CFLAGS = -Werror -Wall -Wextra -I/usr/include -I$(DMLX) -O3 -I$(DLIBFT) -g

LFLAGS = -lX11 -lXext -lm -lz

SOURCES = \
	error_handlers.c\
	event_handlers.c\
	ft_atof.c\
	put_px.c\
	draw.c\
	transforms.c\
	julia.c\
	mandelbrot.c\
	douaby.c\
	fractol.c\

OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

mlx/libmlx_Linux.a:
	@make -C $(dir $@)

libft/libft.a:
	@make -C $(dir $@)

$(NAME): $(OBJECTS) mlx/libmlx_Linux.a libft/libft.a $(LFLAGS)
	@make -C $(DLIBFT)
	@make -C $(DMLX)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -f $(OBJECTS)
	@make clean -C $(DLIBFT)
	@make clean -C $(DMLX)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(DLIBFT)


re: clean all

.PHONY: all clean fclean re
