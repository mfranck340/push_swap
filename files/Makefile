NAME = push_swap
NAME_BONUS = checker
CC = cc
LIB = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
HEADER = include/push_swap.h
HEADER_BONUS = include/checker_bonus.h
SRCS = src/push_swap.c src/display.c src/init_stacks.c src/rotate.c \
		src/reverse_rotate.c src/swap.c src/push.c src/do_movement.c \
		src/verify_input.c src/verify_input_aux.c src/select_movement.c \
		src/select_movement_aux.c src/swap_utils.c src/sort_functions.c 
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = src_bonus/checker_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft.a

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C libft
	cp libft/libft.a libft.a
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) libft.a


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) libft.a
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re