/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:28:54 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 13:46:28 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	op_reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top = stack->top->prev;
}

void	do_rra(t_stack *stack)
{
	op_reverse_rotate(stack);
}

void	do_rrb(t_stack *stack)
{
	op_reverse_rotate(stack);
}

void	do_rrr(t_stack *stack_a, t_stack *stack_b)
{
	op_reverse_rotate(stack_a);
	op_reverse_rotate(stack_b);
}
