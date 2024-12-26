/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:27:03 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 13:43:02 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 8

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	int		min;
	int		max;
}	t_stack;

typedef struct s_movement
{
	int	cost;
	int	direction_a;
	int	moves_a;
	int	direction_b;
	int	moves_b;
}	t_movement;

void	ini_top(t_stack *stack, t_node *node);
int		init_stacks(t_stack **stack_a, t_stack **stack_b, char **input,
			int size);
void	do_sa(t_stack *stack);
void	do_sb(t_stack *stack);
void	do_ss(t_stack *stack_a, t_stack *stack_b);
void	do_pa(t_stack *stack_a, t_stack *stack_b);
void	do_pb(t_stack *stack_a, t_stack *stack_b);
void	do_ra(t_stack *stack);
void	do_rb(t_stack *stack);
void	do_rr(t_stack *stack_a, t_stack *stack_b);
void	do_rra(t_stack *stack);
void	do_rrb(t_stack *stack);
void	do_rrr(t_stack *stack_a, t_stack *stack_b);
int		verify_number(const char *nptr, int *verify);
int		verify_input(int argc, char **argv);
int		is_sorted(t_stack *stack);
int		is_final_sorted(t_stack *stack);
void	stack_free(t_stack *stack);
char	*get_next_line(int fd);

#endif
