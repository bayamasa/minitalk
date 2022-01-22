# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:21:26 by mhirabay          #+#    #+#              #
#    Updated: 2022/01/22 12:10:14 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus

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
DEBUG_FLAGS = -g -fsanitize=address
LDFLAGS = -Llib/ft_printf -Llib/libft
LIBS = -lftprintf -lft

all: lmake ${CLIENT_NAME} ${SERVER_NAME}

lmake:
	make -C lib/ft_printf
	make -C lib/libft

$(CLIENT_NAME) : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) ${LDFLAGS} ${LIBS} -o $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_SRCS) ${LDFLAGS} ${LIBS} -o $(SERVER_NAME)

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

bonus: ${CLIENT_BONUS_NAME} ${SERVER_BONUS_NAME}

$(CLIENT_BONUS_NAME) : $(CLIENT_BONUS_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_SRCS) ${LDFLAGS} ${LIBS} -o $(CLIENT_BONUS_NAME)

$(SERVER_BONUS_NAME) : $(SERVER_BONUS_OBJS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_SRCS) ${LDFLAGS} ${LIBS} -o $(SERVER_BONUS_NAME)

clean: 
	make clean -C lib/ft_printf
	make clean -C lib/libft
	${RM} ${SERVER_OBJS} ${CLIENT_OBJS} ${SERVER_BONUS_OBJS} ${CLIENT_BONUS_OBJS}

fclean: clean
	make fclean -C lib/ft_printf
	make fclean -C lib/libft
	${RM} ${SERVER_NAME} ${CLIENT_NAME} ${SERVER_BONUS_NAME} ${CLIENT_BONUS_NAME}
re:		fclean all

.PHONY: all clean fclean re .c.o 
