### Executable ###
NAME	= libgnl.a

### Compilation ###
CC		= gcc
RM		= rm -f
C_FLAGS	= -Wall -Wextra -Werror

### Source Files ###
SRCS	= get_next_line.c get_next_line_utils.c

### Object Files ###
OBJS	= $(SRCS:.c=.o)

### Rule ###
all: $(NAME)

%o:%c
	$(CC) -arch x86_64 $(C_FLAGS) -c $< -o $@
##$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re