# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouline <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 22:18:47 by tbouline          #+#    #+#              #
#    Updated: 2017/04/13 22:44:03 by tbouline         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = fdf

SRC = main.c \
	  init.c \
	  parse.c \
	  error.c \
	  seg.c \
	  draw.c \
	  map.c \
	  put_string.c \
	  color.c

CC = gcc

HEADER = fdf.h

OBJ = main.o \
	  init.o \
	  parse.o \
	  error.o \
	  seg.o \
	  draw.o \
	  map.o \
	  put_string.o \
	  color.o

FLAG = -Wall -Wextra -Werror

OP = -c -I $(HEADER)

all: $(EXEC)

$(EXEC): $(OBJ) $(HEADER)
	make -C libft/
	$(CC) $(FLAG) $(OP) $(SRC)
	$(CC) -o $(EXEC) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework Appkit

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
