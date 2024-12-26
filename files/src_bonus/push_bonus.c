/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:40:48 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 13:43:49 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	update_min_max(t_stack *stack)
{
	t_node	*node;
	int		i;

	node = stack->top;
	stack->min = node->data;
	stack->max = node->data;
	i = 0;
	while (i < stack->size - 1)
	{
		if (node->data < stack->min)
			stack->min = node->data;
		if (node->data > stack->max)
			stack->max = node->data;
		node = node->next;
		i++;
	}
}

static t_node	*get_top_node(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return (0);
	if (stack->size == 1)
	{
		node = stack->top;
		stack->top = 0;
		stack->size = 0;
	}
	else
	{
		node = stack->top;
		stack->top = node->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		update_min_max(stack);
		stack->size--;
	}
	return (node);
}

static void	op_push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = get_top_node(stack_b);
	if (!node)
		return ;
	if (stack_a->size == 0)
	{
		ini_top(stack_a, node);
	}
	else
	{
		node->next = stack_a->top;
		node->prev = stack_a->top->prev;
		stack_a->top->prev->next = node;
		stack_a->top->prev = node;
		stack_a->top = node;
		if (node->data < stack_a->min)
			stack_a->min = node->data;
		if (node->data > stack_a->max)
			stack_a->max = node->data;
	}
	stack_a->size++;
}

void	do_pa(t_stack *stack_a, t_stack *stack_b)
{
	op_push(stack_a, stack_b);
}

void	do_pb(t_stack *stack_a, t_stack *stack_b)
{
	op_push(stack_b, stack_a);
}
