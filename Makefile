FLAGS = -Wall -Wextra -Werror

NAME = miniRT

LIBFT_PATH = libft/
LIBFT_FLAG = -Llibft -lmylib
LIBFT_HD = -Ilibft

GNL_PATH = get_next_line/
GNL_FLAG = -get_next_line -lgnl
GNL_HD = -Iget_next_line

LIBFT_SRCS = ft_strlen.c ft_split.c ft_atoi.c

GNL_SRCS = get_next_line.c get_next_line_utils.c

MINIRT_SRCS = main.c utils.c

SRCS = $(MINIRT_SRCS) \
						$(addprefix $(LIBFT_PATH), $(LIBFT_SRCS)) \
						$(addprefix $(GNL_PATH), $(GNL_SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o:%.c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@make -C $(GNL_PATH)
	gcc $(OBJS) $(FLAGS) -o $(NAME)

clean:
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(GNL_PATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: clean fclean re all bonus