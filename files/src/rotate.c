/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:27:31 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/25 22:27:35 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top = stack->top->next;
}

void	do_ra(t_stack *stack)
{
	op_rotate(stack);
	ft_printf("ra\n");
}

void	do_rb(t_stack *stack)
{
	op_rotate(stack);
	ft_printf("rb\n");
}

void	do_rr(t_stack *stack_a, t_stack *stack_b)
{
	op_rotate(stack_a);
	op_rotate(stack_b);
	ft_printf("rr\n");
}
