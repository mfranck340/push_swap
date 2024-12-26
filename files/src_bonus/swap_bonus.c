/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:42:28 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 13:42:30 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

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
}

void	do_sb(t_stack *stack)
{
	op_swap(stack);
}

void	do_ss(t_stack *stack_a, t_stack *stack_b)
{
	op_swap(stack_a);
	op_swap(stack_b);
}
