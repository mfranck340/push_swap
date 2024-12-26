/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:23:12 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 00:23:16 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h"

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

void	display_stacks(t_stack *stack_a, t_stack *stack_b);
void	ini_top(t_stack *stack, t_node *node);
int		init_stacks(t_stack **stack_a, t_stack **stack_b, char **input,
			int size);
void	do_ra(t_stack *stack);
void	do_rb(t_stack *stack);
void	do_rr(t_stack *stack_a, t_stack *stack_b);
void	do_rra(t_stack *stack);
void	do_rrb(t_stack *stack);
void	do_rrr(t_stack *stack_a, t_stack *stack_b);
void	op_push(t_stack *stack_a, t_stack *stack_b);
void	do_pa(t_stack *stack_a, t_stack *stack_b);
void	do_pb(t_stack *stack_a, t_stack *stack_b);
void	do_sa(t_stack *stack);
void	do_sb(t_stack *stack);
void	do_ss(t_stack *stack_a, t_stack *stack_b);
void	do_move_b(t_stack *stack_b, t_movement *movement);
void	do_movement(t_stack *stack_a, t_stack *stack_b, t_movement *movement);
int		verify_number(const char *nptr, int *verify);
int		verify_input(int argc, char **argv);
void	change_best_move(t_movement **movements);
void	select_mov_dir(t_stack *stack, t_movement *movement, int i,
			int n_stack);
void	calculate_moves(t_stack *stack, t_movement *movement, int value,
			int n_stack);
void	modify_movement_a(t_stack *stack_a, t_movement **movements, int mov_aux,
			int dir);
void	modify_movement_b(t_stack *stack_b, t_movement **movements, int mov_aux,
			int dir);
void	search_position(t_stack *stack_b, t_node *node, t_movement **movements,
			int n_stack);
void	select_best_move(t_stack *stack_a, t_stack *stack_b,
			t_movement **movements);
int		is_sorted(t_stack *stack);
int		is_final_sorted(t_stack *stack);
void	stack_free(t_stack *stack);
void	restart_movement(t_movement *movement);
void	restart_best_movement(t_movement *movement);
void	sort_little_stack(t_stack *stack);

#endif
