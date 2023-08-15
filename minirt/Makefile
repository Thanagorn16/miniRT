### Executable ###
NAME	= minirt

### Directory ###
DIR_LIBFT	= libft
DIR_SRCS	= srcs
DIR_OBJS	= objs
DIR_SUBS	= main math geometry create light

SRCS_DIRS	= $(foreach dir, $(DIR_SUBS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(DIR_SUBS), $(addprefix $(DIR_OBJS)/, $(dir)))

### Compilation ###
CC			= cc
RM			= rm -f
HEAD_MAN	= -Iincludes
CFLAGS		= #-Wall -Wextra -Werror -g -fsanitize=address

### Libft Flags ###
HEAD_FT		= -Ilibft
FLAGS_FT	= -Llibft -lft

### mlx Flags ###
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	DIR_MLX		= mlx_linux
	FLAGS_MLX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	HEAD_MLX	= -Imlx_linux
else
	DIR_MLX		= mlx_mac
	FLAGS_MLX	= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit
	HEAD_MLX	= -Imlx_mac
endif

### Source Files ###
SRCS		=	$(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))

### Object Files ###
OBJS		=	$(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

### Compilation Rule ###
$(DIR_OBJS)/%.o:$(DIR_SRCS)/%.c
	@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
	$(CC) $(CFLAGS) $(HEAD_MAN) $(HEAD_MLX) $(HEAD_FT) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS_MLX) $(FLAGS_FT) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(DIR_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
