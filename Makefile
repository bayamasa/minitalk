SERVER_NAME = server
CLIENT_NAME = client
LIB_NAME = libftprintf 

SERVER_SRCS = server.c ft_perror.c
CLIENT_SRCS = client.c ft_perror.c

SERVER_OBJS = ${SERVER_SRCS:.c=.o}
CLIENT_OBJS = ${CLIENT_SRCS:.c=.o}

CC = gcc 
CFLAGS = -Wall -Werror -Wextra

all: ${LIB_NAME} ${CLIENT_NAME} ${SERVER_NAME}

${LIB_NAME}  : 
	make -C lib/ft_printf
	
$(CLIENT_NAME) : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -Llib/ft_printf -lftprintf -o $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -Llib/ft_printf -lftprintf -o $(SERVER_NAME)

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean: 
		make clean -C lib/ft_printf
		${RM} ${SERVER_OBJS} ${CLIENT_OBJS}

fclean: clean
		make fclean -C lib/ft_printf
		${RM} ${SERVER_NAME} ${CLIENT_NAME}
re:		fclean all

.PHONY: all clean fclean re .c.o 
