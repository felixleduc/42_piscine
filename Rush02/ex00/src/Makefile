NAME = rush-02

SRCS = main.c ft_atoi.c ReadDict.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

${NAME}:
	@${CC} ${CFLAGS} -o ${NAME} ${SRCS}

all: ${NAME}

fclean:
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
