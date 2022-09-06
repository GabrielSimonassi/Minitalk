# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 18:51:51 by gsimonas          #+#    #+#              #
#    Updated: 2022/09/06 18:58:43 by gsimonas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	client.c server.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	minitalk.a

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

.c.o:
	$(CC) $(CFLAGS)	-c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	ar rc	$(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(NAME) $(OBJS)

fclean:	$(clean)
	$(RM) $(NAME)	$(OBJS)

re:	fclean all

.PHONY:	all clean fclean re
