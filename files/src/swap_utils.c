/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:03:06 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 00:03:08 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*node;
	t_node	*top;

	node = stack->top;
	top = stack->top;
	while (node->next != top)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int	is_final_sorted(t_stack *stack)
{
	t_node	*node;
	t_node	*top;

	node = stack->top;
	top = stack->top;
	while (node->next != top)
	{
		if (node->data < node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

void	stack_free(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	if (stack->size == 0)
	{
		free(stack);
		return ;
	}
	node = stack->top;
	while (node->next != stack->top)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(node);
	free(stack);
}

void	restart_movement(t_movement *movement)
{
	movement->cost = 0;
	movement->direction_a = 0;
	movement->direction_b = 0;
	movement->moves_a = 0;
	movement->moves_b = 0;
}

void	restart_best_movement(t_movement *movement)
{
	movement->cost = INT_MAX;
	movement->direction_a = 0;
	movement->direction_b = 0;
	movement->moves_a = 0;
	movement->moves_b = 0;
}
