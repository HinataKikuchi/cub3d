NAME		=	libgnl.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	get_next_line.c \
				get_next_line_utils.c
OBJS	:=	$(SRCS:.c=.o)

LIBFT_DIR	=	../libft
LIBFT		=	${LIBFT_DIR}/libft.a

INCLUDE		=	-I./ -I./${LIBFT_DIR}

LIBS		=	-L${LIBFT_DIR} -lft

.c.o:
			${CC} ${CFLAGS} ${INCLUDE} -o $@ -c $<

all:		$(NAME)

${LIBFT}:	${LIBFT_DIR}/*.c
			make -C ${LIBFT_DIR}

$(NAME):$(OBJS) $(LIBFT)
			cp $(LIBFT) $(NAME)
			ar rcs $(NAME) $(OBJS)


clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

