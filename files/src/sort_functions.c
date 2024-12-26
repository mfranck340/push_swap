/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:18:32 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 00:18:35 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three(t_stack *stack)
{
	t_node	*node;

	if (is_sorted(stack))
		return ;
	node = stack->top;
	if (node->data < node->prev->data)
	{
		do_sa(stack);
		if (!is_sorted(stack))
			do_ra(stack);
	}
	else if (node->data > node->next->data && node->data > node->prev->data)
	{
		do_ra(stack);
		if (!is_sorted(stack))
			do_sa(stack);
	}
	else
		do_rra(stack);
}

void	sort_little_stack(t_stack *stack)
{
	if (stack->size == 2)
	{
		if (stack->top->data > stack->top->next->data)
			do_sa(stack);
	}
	else if (stack->size == 3)
		sort_three(stack);
}
