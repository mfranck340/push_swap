/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:50:41 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/25 23:50:45 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	modify_movement(t_stack *stack_a, t_stack *stack_b,
	t_movement **movements)
{
	int		mov_aux;

	if (movements[1]->moves_a > movements[1]->moves_b)
	{
		mov_aux = stack_a->size - movements[1]->moves_a - movements[1]->moves_b;
		if (movements[1]->direction_b == 0)
			modify_movement_a(stack_a, movements, mov_aux, 0);
		else
			modify_movement_a(stack_a, movements, mov_aux, 1);
	}
	else
	{
		mov_aux = stack_b->size - movements[1]->moves_a - movements[1]->moves_b;
		if (movements[1]->direction_a == 0)
			modify_movement_b(stack_b, movements, mov_aux, 0);
		else
			modify_movement_b(stack_b, movements, mov_aux, 1);
	}
}

static void	optimize_movement(t_stack *stack_a, t_stack *stack_b,
	t_movement **movements)
{
	if (movements[1]->direction_a == movements[1]->direction_b)
	{
		if (movements[1]->moves_a > movements[1]->moves_b)
			movements[1]->cost = movements[1]->moves_a;
		else
			movements[1]->cost = movements[1]->moves_b;
	}
	else
		modify_movement(stack_a, stack_b, movements);
}

static void	update_movement(t_stack *stack_b, t_movement **movements, int j,
	int n_stack)
{
	int	*moves;
	int	*direction;

	if (n_stack == 0)
	{
		moves = &movements[1]->moves_a;
		direction = &movements[1]->direction_a;
	}
	else
	{
		moves = &movements[1]->moves_b;
		direction = &movements[1]->direction_b;
	}
	if (j <= stack_b->size - j)
	{
		*moves = j;
		*direction = 0;
	}
	else
	{
		*moves = stack_b->size - j;
		*direction = 1;
	}
}

void	search_position(t_stack *stack_b, t_node *node, t_movement **movements,
	int n_stack)
{
	t_node	*node_b;
	int		j;

	j = -1;
	node_b = stack_b->top;
	while (j++ < stack_b->size)
	{
		if (n_stack == 0)
		{
			if (node->data < node_b->data && node->data > node_b->prev->data)
			{
				update_movement(stack_b, movements, j, n_stack);
				break ;
			}
		}
		else
		{
			if (node->data > node_b->data && node->data < node_b->prev->data)
			{
				update_movement(stack_b, movements, j, n_stack);
				break ;
			}
		}
		node_b = node_b->next;
	}
}

void	select_best_move(t_stack *stack_a, t_stack *stack_b,
	t_movement **movements)
{
	t_node	*node;
	t_node	*node_b;
	int		i;

	i = -1;
	node = stack_a->top;
	restart_best_movement(movements[0]);
	while (i++ < stack_a->size - 1)
	{
		restart_movement(movements[1]);
		select_mov_dir(stack_a, movements[1], i, 0);
		if (node->data > stack_b->max || node->data < stack_b->min)
		{
			node_b = stack_b->top;
			if (node_b->data != stack_b->max)
				calculate_moves(stack_b, movements[1], stack_b->max, 1);
		}
		else
			search_position(stack_b, node, movements, 1);
		optimize_movement(stack_a, stack_b, movements);
		change_best_move(movements);
		node = node->next;
	}
}
