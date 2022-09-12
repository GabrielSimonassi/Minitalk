# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsimonas <gsimonas@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 18:51:51 by gsimonas          #+#    #+#              #
#    Updated: 2022/09/12 15:41:58 by gsimonas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	server.c client.c

NAME	=	minitalk

SERVER	=	server

CLIENT	=	client

OBJS	=	$(SRCS:.c=.o)	

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	libft/libft.a

.c.o:
		@$(CC) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJS) $(SERVER) $(CLIENT)	

$(SERVER): $(LIBFT)
	$(CC) -o server server.o -Llibft -lft

$(CLIENT):	$(LIBFT)
	$(CC) -o client client.o -Llibft -lft

RM 	=	rm -rf
clean:
	@make clean -C libft
	@rm -rf *.o
	$(RM) $(SERVER) $(CLIENT)

fclean:	clean
		$(RM) $(NAME) $(SERVER) $(CLIENT)

re:	fclean all

.PHONY:	all clean fclean re 
