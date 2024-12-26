# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 17:42:15 by ffierro-          #+#    #+#              #
#    Updated: 2024/12/26 17:42:16 by ffierro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
LIB = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
HEADER = include/push_swap.h
HEADER_BONUS = include/push_swap_bonus.h
SRCS = src/push_swap.c src/display.c src/init_stacks.c src/rotate.c \
		src/reverse_rotate.c src/swap.c src/push.c src/do_movement.c \
		src/verify_input.c src/verify_input_aux.c src/select_movement.c \
		src/select_movement_aux.c src/swap_utils.c src/sort_functions.c 
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = src_bonus/checker_bonus.c src_bonus/push_bonus.c \
			src_bonus/swap_bonus.c src_bonus/rotate_bonus.c \
			src_bonus/reverse_rotate_bonus.c src_bonus/init_stacks_bonus.c \
			src_bonus/swap_utils_bonus.c src_bonus/verify_input_bonus.c \
			src_bonus/verify_input_aux_bonus.c \
			src_bonus/get_next_line_bonus.c
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

src/%.o: src/%.c $(HEADER)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

src_bonus/%.o: src_bonus/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) libft.a
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
