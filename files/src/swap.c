/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:40:05 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/25 22:40:10 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_swap(t_stack *stack)
{
	t_node	*node;
	int		tmp;

	if (stack->size < 2)
		return ;
	node = stack->top;
	tmp = node->data;
	node->data = node->next->data;
	node->next->data = tmp;
}

void	do_sa(t_stack *stack)
{
	op_swap(stack);
	ft_printf("sa\n");
}

void	do_sb(t_stack *stack)
{
	op_swap(stack);
	ft_printf("sb\n");
}

void	do_ss(t_stack *stack_a, t_stack *stack_b)
{
	op_swap(stack_a);
	op_swap(stack_b);
	ft_printf("ss\n");
}
