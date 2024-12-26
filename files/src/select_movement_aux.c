/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_movement_aux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:52:33 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/25 23:52:36 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	change_best_move(t_movement **movements)
{
	if (movements[0]->cost > movements[1]->cost)
	{
		movements[0]->cost = movements[1]->cost;
		movements[0]->direction_a = movements[1]->direction_a;
		movements[0]->direction_b = movements[1]->direction_b;
		movements[0]->moves_a = movements[1]->moves_a;
		movements[0]->moves_b = movements[1]->moves_b;
	}
}

void	select_mov_dir(t_stack *stack, t_movement *movement, int i, int n_stack)
{
	int	*moves;
	int	*direction;

	if (n_stack == 0)
	{
		moves = &movement->moves_a;
		direction = &movement->direction_a;
	}
	else
	{
		moves = &movement->moves_b;
		direction = &movement->direction_b;
	}
	if (stack->size - i < i)
	{
		*moves = stack->size - i;
		*direction = 1;
	}
	else
	{
		*moves = i;
		*direction = 0;
	}
}

void	calculate_moves(t_stack *stack, t_movement *movement, int value,
	int n_stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->top;
	while (node->data != value)
	{
		node = node->next;
		i++;
	}
	select_mov_dir(stack, movement, i, n_stack);
}

void	modify_movement_a(t_stack *stack_a, t_movement **movements, int mov_aux,
	int dir)
{
	if (mov_aux < movements[1]->moves_a)
	{
		movements[1]->moves_a = stack_a->size - movements[1]->moves_a;
		movements[1]->direction_a = dir;
		movements[1]->cost += movements[1]->moves_a;
	}
	else
		movements[1]->cost += movements[1]->moves_a + movements[1]->moves_b;
}

void	modify_movement_b(t_stack *stack_b, t_movement **movements, int mov_aux,
	int dir)
{
	if (mov_aux < movements[1]->moves_b)
	{
		movements[1]->moves_b = stack_b->size - movements[1]->moves_b;
		movements[1]->direction_b = dir;
		movements[1]->cost += movements[1]->moves_b;
	}
	else
		movements[1]->cost += movements[1]->moves_a + movements[1]->moves_b;
}
