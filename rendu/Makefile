# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 21:20:38 by vmalassi          #+#    #+#              #
#    Updated: 2023/03/22 21:33:02 by vmalassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CFLAGS = -Wall -Wextra -Werror

SOURCES = filters.c \
	  find_square.c \
	  ft_basic.c \
	  ft_basic2.c \
	  ft_lib.c \
	  main.c \
	  parser.c \
	  read_inputs.c \
	  solve_file.c \
	  solve_file_func.c \
	  solve_inputs.c \
	  verif_files.c \
	  verif_inputs.c 

OBJECTS = $(SOURCES:.c=.o)

INCLUDE = ft.h

$(NAME) : $(OBJECTS)
	cc $(CFLAGS) $(OBJ) -o $@

%.o:	%.c $(INCLUDE)
	cc $(CFLAGS) -I. -c $< -o $@
