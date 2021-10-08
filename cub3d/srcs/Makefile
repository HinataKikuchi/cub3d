NAME		=	cub3d
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LIBFT_DIR	=	../libft
GNL_DIR		=	../gnl
MLX_DIR		=	../minilibx-linux
UTILS_DIR	=	./utils
MAP_VALUE_DIR	=./map_value
SRCS		=	main.c \
				cub_calc.c \
				cub_key.c \
				pos_calc.c \
				tex_calc.c \
				cub_draw.c \
				utils/cub_key_hook.c \
				utils/cub_utils.c \
				utils/error_hundling.c \
				utils/pos_initiarize.c \
				utils/cub_color.c \
				map_value/cub_map.c \
				map_value/cub_value.c \
				map_value/cub_texture.c \
				map_value/cub_check.c


OBJS		=	${SRCS:.c=.o}

LIBFT		=	${LIBFT_DIR}/libft.a
GNL			=	${GNL_DIR}/libgnl.a
MLX			=	${MLX_DIR}/libmlx.a

INCLUDE = -I./include -I./${LIBFT_DIR} -I./${GNL_DIR} -I./
LIBS  = -L${LIBFT_DIR} -lft -L${GNL_DIR} -lgnl -L $(MLX_DIR) -lmlx -lX11 -lXext -lm

%.o:%.c
				@${CC} ${INCLUDE} -o $@ -c $<
				@printf ">"

all:			$(NAME)

${LIBFT}:		${LIBFT_DIR}/*.c
				@${MAKE} -C ${LIBFT_DIR}

$(GNL):			$(GNL_DIR)/*.c
				@$(MAKE) -C $(GNL_DIR)

$(MLX):			$(MLX_DIR)/*.c
				@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(MLX)
				@$(CC) $(INCLUDE) -o $@ $(OBJS) $(LIBS) $(INCLUDE)

clean:;			@$(RM) ${OBJS}
				@${MAKE} -C ${LIBFT_DIR} clean
				@$(MAKE) -C $(GNL_DIR) clean
				@$(MAKE) -C $(MLX_DIR) clean

fclean:clean;	@$(RM) $(NAME)
				@${MAKE} -C ${LIBFT_DIR} fclean
				@$(MAKE) -C $(GNL_DIR) fclean

re:				fclean $(NAME)

test:$(NAME)
				./$(NAME) ../test_maps/test2.cub

MODEL_SRC = test_4.c
MODEL_OBJ = $(MODEL_SRC:.c=.o)
model:	$(MODEL_OBJ) $(MLX)
		@$(CC) -I$(MLX_DIR) $(MODEL_OBJ) -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
		@./a.out

model_clean:;	$(RM) $(MODEL_OBJ)
				@$(RM) ./a.out
				@$(MAKE) -C $(MLX_DIR) clean

.PHONY:			re clean fclean all