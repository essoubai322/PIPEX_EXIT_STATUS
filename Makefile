NAME = pipex
CC = cc 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SOURCE = pipex.c ft_utils.c ft_split.c ft_error_fr.c ft_check.c ft_check1.c
OBJ = ${SOURCE:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all 