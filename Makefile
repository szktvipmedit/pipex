SRCS = srcs/main.c \
	   srcs/init.c \
	   srcs/path.c \
	   srcs/childs.c \
	   srcs/clear.c \
	   srcs/error.c \

OBJS = ${patsubst $(SRCS_DIR)%.c,  $(OBJS_DIR)%.o, $(SRCS)}

NAME = pipex
SRCS_DIR = srcs/
OBJS_DIR = objs/
INCS_DIR = incs/
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	mkdir -p ${@D}
	${CC} ${CFLAGS} -I {INCS_DIR} -c $< -o $@ 

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

${LIBFT}:
	make -C libft


.PHONY: all clean fclean re
all: ${NAME};

clean:
	make fclean -C libft
	rm -rf objs

fclean: clean
	rm -rf ${NAME}

re: fclean all;

