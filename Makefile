SRC_FILES = main.c

SRC_DIR = sources
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = objects
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

NAME = push_swap

LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

$(LIBFT) :
	make -C libft

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY = all clean fclean re
