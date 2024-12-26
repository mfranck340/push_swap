/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:27:31 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 13:45:04 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	op_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top = stack->top->next;
}

void	do_ra(t_stack *stack)
{
	op_rotate(stack);
}

void	do_rb(t_stack *stack)
{
	op_rotate(stack);
}

void	do_rr(t_stack *stack_a, t_stack *stack_b)
{
	op_rotate(stack_a);
	op_rotate(stack_b);
}
