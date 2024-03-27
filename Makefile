# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 13:36:07 by snegi             #+#    #+#              #
#    Updated: 2023/02/14 13:36:09 by snegi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror -I .

SRCS	=	main.c ft_sort.c ft_split.c list.c instruction.c radix_sort.c sort_utl.c main_utl.c ft_strlcpy.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	push_swap

HEADER	=	ft_sort.h

all:		$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
