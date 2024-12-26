/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:49:50 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 15:49:52 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

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
