# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:21:26 by mhirabay          #+#    #+#              #
#    Updated: 2021/12/02 13:52:17 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus

LIB_NAME = libftprintf 

SERVER_SRCS = server.c ft_perror.c
CLIENT_SRCS = client.c ft_perror.c
SERVER_BONUS_SRCS = server_bonus.c ft_perror.c
CLIENT_BONUS_SRCS = client_bonus.c ft_perror.c

SERVER_OBJS = ${SERVER_SRCS:.c=.o}
CLIENT_OBJS = ${CLIENT_SRCS:.c=.o}
SERVER_BONUS_OBJS = ${SERVER_BONUS_SRCS:.c=.o}
CLIENT_BONUS_OBJS = ${CLIENT_BONUS_SRCS:.c=.o}

CC = gcc 
CFLAGS = -Wall -Werror -Wextra

all: ${LIB_NAME} ${CLIENT_NAME} ${SERVER_NAME}

${LIB_NAME}:
	make -C lib/ft_printf

$(CLIENT_NAME) : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -Llib/ft_printf -lftprintf -o $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -Llib/ft_printf -lftprintf -o $(SERVER_NAME)

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus: ${CLIENT_BONUS_NAME} ${SERVER_BONUS_NAME}

$(CLIENT_BONUS_NAME) : $(CLIENT_BONUS_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_SRCS) -Llib/ft_printf -lftprintf -o $(CLIENT_BONUS_NAME)

$(SERVER_BONUS_NAME) : $(SERVER_BONUS_OBJS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_SRCS) -Llib/ft_printf -lftprintf -o $(SERVER_BONUS_NAME)

clean: 
	make clean -C lib/ft_printf
	${RM} ${SERVER_OBJS} ${CLIENT_OBJS} ${SERVER_BONUS_OBJS} ${CLIENT_BONUS_OBJS}

fclean: clean
	make fclean -C lib/ft_printf
	${RM} ${SERVER_NAME} ${CLIENT_NAME} ${SERVER_BONUS_NAME} ${CLIENT_BONUS_NAME}
re:		fclean all

.PHONY: all clean fclean re .c.o 
