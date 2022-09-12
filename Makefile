# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 18:51:51 by gsimonas          #+#    #+#              #
#    Updated: 2022/09/12 15:18:16 by gsimonas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	server.c client.c

NAME	=	minitalk.a

SERVER	=	server

CLIENT	=	client

OBJS	=	$(SRCS:.c=.o)	

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

LIBS	=	-L./libft -lft

LIBFT	=	libft.a

all:	$(NAME)

$(LIBFT):
	@make -C libft

$(NAME):	$(OBJS) $(SERVER) $(CLIENT)	

$(SERVER): $(LIBFT)
	$(CC) -o server server.o -Llibft -lft

$(CLIENT):	$(LIBFT)
	$(CC) $(CFLAGS) client.c $(LIBS) -o $(CLIENT)

%.o : %.c
	@$(CC) $(CFLAGS) $<-c

clean:
	@make clean -C libft
	@rm -rf *.o
	$(RM) $(SERVER) $(CLIENT)

fclean:	$(clean)
		$(RM) $(NAME) $(SERVER) $(CLIENT)

re:	fclean all

.PHONY:	all clean fclean re server client
