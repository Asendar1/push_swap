SRC_FILES = main.c exit_utils.c stack.c stack_utils.c utils.c operationes.c rotate.c rrotate.c swap.c radix.c

SRC_DIR = sources
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = objects
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

CC = cc
CFLAGS =  -I./libft -Iincludes -g

NAME = push_swap

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

$(LIBFT) :
	make -C libft

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all

.PHONY = all clean fclean re
