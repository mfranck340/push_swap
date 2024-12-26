/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:28:54 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/25 22:28:57 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	op_reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top = stack->top->prev;
}

void	do_rra(t_stack *stack)
{
	op_reverse_rotate(stack);
	ft_printf("rra\n");
}

void	do_rrb(t_stack *stack)
{
	op_reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	do_rrr(t_stack *stack_a, t_stack *stack_b)
{
	op_reverse_rotate(stack_a);
	op_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
