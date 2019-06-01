# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/20 17:58:54 by hmichel      #+#   ##    ##    #+#        #
#    Updated: 2019/01/20 17:59:43 by hmichel     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	=	fillit

SRC		=	src/test_map.c src/util.c src/resolve.c src/resolve2.c src/fillit.c

OBJ		=	src/test_map.o src/util.o src/resolve.o src/resolve2.o src/fillit.o

FLAGS	+=	-Wall -Wextra -Werror -g

$(NAME) : libft/libft.a $(OBJ)
		  gcc -g $(OBJ) libft/libft.a -I libft -o $(NAME)

all:	$(NAME)

%.o: %.c	src/fillit.h
			gcc -c $(FLAGS) -o $@ $<

clean:
		rm -f $(OBJ)
		make clean -C libft

fclean: clean
		rm -f $(NAME)
		rm -f libft/libft.a

re : fclean all

libft/libft.a:
		make -C libft