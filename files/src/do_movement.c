/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:56:03 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/25 22:56:07 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_min_movement(t_movement *movement)
{
	if (movement->moves_a > movement->moves_b)
		return (movement->moves_b);
	return (movement->moves_a);
}

void	do_move_a(t_stack *stack_a, t_movement *movement)
{
	int	i;

	i = 0;
	while (i++ < movement->moves_a)
	{
		if (movement->direction_a == 0)
			do_ra(stack_a);
		else
			do_rra(stack_a);
	}
}

void	do_move_b(t_stack *stack_b, t_movement *movement)
{
	int	i;

	i = 0;
	while (i++ < movement->moves_b)
	{
		if (movement->direction_b == 0)
			do_rb(stack_b);
		else
			do_rrb(stack_b);
	}
}

void	do_movement(t_stack *stack_a, t_stack *stack_b, t_movement *movement)
{
	int	min_mov;
	int	i;

	if (movement->direction_a == movement->direction_b)
	{
		min_mov = get_min_movement(movement);
		i = 0;
		if (movement->direction_a == 0)
		{
			while (i++ < min_mov)
				do_rr(stack_a, stack_b);
		}
		else
		{
			while (i++ < min_mov)
				do_rrr(stack_a, stack_b);
		}
		movement->moves_a -= min_mov;
		movement->moves_b -= min_mov;
	}
	do_move_a(stack_a, movement);
	do_move_b(stack_b, movement);
}
