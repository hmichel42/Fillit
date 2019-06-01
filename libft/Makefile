# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: hmichel <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 11:29:25 by hmichel      #+#   ##    ##    #+#        #
#    Updated: 2018/12/12 13:42:43 by hmichel     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all re fclean clean

NAME		=	libft.a

FILES		=	ft_atoi\
				ft_bzero\
				ft_isalnum\
				ft_isalpha\
				ft_isascii\
				ft_isdigit\
				ft_isprint\
				ft_itoa\
				ft_lstadd\
				ft_lstdel\
				ft_lstdelone\
				ft_lstiter\
				ft_lstmap\
				ft_lstnew\
				ft_memalloc\
				ft_memccpy\
				ft_memchr\
				ft_memcmp\
				ft_memcpy\
				ft_memdel\
				ft_memmove\
				ft_memset\
				ft_putchar\
				ft_putchar_fd\
				ft_putendl\
				ft_putendl_fd\
				ft_putnbr\
				ft_putnbr_fd\
				ft_putstr\
				ft_putstr_fd\
				ft_str_is_numeric\
				ft_str_is_printable\
				ft_strcat\
				ft_strchr\
				ft_strclr\
				ft_strcmp\
				ft_strcpy\
				ft_strdel\
				ft_strdup\
				ft_strequ\
				ft_striter\
				ft_striteri\
				ft_strjoin\
				ft_strlcat\
				ft_strlen\
				ft_strmap\
				ft_strmapi\
				ft_strncat\
				ft_strncmp\
				ft_strncpy\
				ft_strnequ\
				ft_strnew\
				ft_strnstr\
				ft_strrchr\
				ft_strsplit\
				ft_strstr\
				ft_strsub\
				ft_strtrim\
				ft_tolower\
				ft_toupper\
				ft_strtrimv2\
				ft_strlowcase\
				ft_strupcase\
				ft_foreach\
				ft_power\
				ft_swap\
				ft_strrev\
				ft_strchri\
				ft_intsqrt

FLAGS		+=	-Wall -Wextra -Werror -g

HEADER		=	includes/libft.h

RM			=	rm -f

CC			=	gcc

SRC			=	$(addsuffix .c, $(FILES))

OBJ			= 	$(addsuffix .o, $(FILES))

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				@ar rcs  $(NAME) $(OBJ)

%.o			:	%.c $(HEADER)
				@$(CC) -g -o $@ -c $< -I $(HEADER)

clean		:
				@$(RM) $(OBJ)

fclean		:	clean
				@$(RM) $(NAME)

re			:	fclean all
