NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -fPIC
LDFLAGS	= -L/usr/local/lib
LIBS	= 
SRC		= ft_atoi.c ft_isascii.c ft_memchr.c ft_putchar_fd.c ft_strchr.c\
	ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcmp.c\
	ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_substr.c ft_calloc.c\
	ft_isprint.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c\
	ft_tolower.c ft_isalnum.c ft_itoa.c ft_memmove.c ft_putstr_fd.c\
	ft_strlcat.c ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memccpy.c\
	ft_memset.c ft_split.c ft_strlcpy.c ft_strrchr.c
OBJS	= $(SRC:.c=.o)

%.o:%.c
		@$(CC) $(CFLAGS) -o $@ -c $<
		@printf ">"

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:;	@$(RM) *.o

fclean:clean;		@$(RM) $(NAME)

re:			@fclean $(NAME)

.PHONY: re clean fclean all
