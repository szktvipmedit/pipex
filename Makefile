SRCS = srcs/main.c \
	   srcs/init.c \
	   srcs/path.c \
	   srcs/childs.c \
	   srcs/error.c \

OBJS = ${patsubst ${SRCS_DIR}%.c, ${OBJS_DIR}%.o ,${SRCS}}

NAME = pipex
SRCS_DIR = srcs/
OBJS_DIR = objs/
INCS_DIR = incs/
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	mkdir -p ${@D}
	${CC} ${CFLAGS} -I {INCS_DIR} -c $< -o $@ 

${LIBFT}:
	make -C libft

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}


.PHONY: all clean fclean re
all: ${NAME};

clean:
	make fclean -C libft
	rm -rf ${0BJS_DIR}

fclean: clean
	rm -rf ${NAME}

re: fclean all;

