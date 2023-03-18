# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 11:17:35 by sdiaz-ru          #+#    #+#              #
#    Updated: 2023/03/18 11:24:50 by sdiaz-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER_NAME	=	server
CLIENT_NAME	=	client

CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -fr
INCLUDE		=	minitalk.h

DIR_MAKE_PRINTF	=	./ft_printf

all: $(SERVER_NAME) $(CLIENT_NAME)

make_printf:
			@$(MAKE) -s all -C $(DIR_MAKE_PRINTF)

$(SERVER_NAME):	make_printf
			@gcc $(CFLAGS) server.c -o $(SERVER_NAME) $(DIR_MAKE_PRINTF)/libftprintf.a
			@echo Server compilado

$(CLIENT_NAME):	make_printf
			@gcc $(CFLAGS) client.c -o $(CLIENT_NAME) $(DIR_MAKE_PRINTF)/libftprintf.a
			@echo Client compilado

re:		fclean all

clean:
		@$(MAKE) -s clean -C $(DIR_MAKE_PRINTF)

fclean:		clean
			@$(MAKE) -s fclean -C $(DIR_MAKE_PRINTF)
			@$(RM) $(SERVER_NAME) $(CLIENT_NAME)
			@echo Todo limpio

.PHONY: 	all make_printf re clean fclean
