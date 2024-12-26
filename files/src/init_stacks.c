/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:12:53 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/25 22:13:08 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->top = 0;
	stack->size = 0;
	return (stack);
}

void	ini_top(t_stack *stack, t_node *node)
{
	stack->top = node;
	node->next = node;
	node->prev = node;
	stack->min = node->data;
	stack->max = node->data;
}

static int	stack_push(t_stack *stack, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = data;
	if (!stack->top)
		ini_top(stack, node);
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->prev->next = node;
		stack->top->prev = node;
		stack->top = node;
		if (data < stack->min)
			stack->min = data;
		if (data > stack->max)
			stack->max = data;
	}
	stack->size++;
	return (1);
}

int	init_stacks(t_stack **stack_a, t_stack **stack_b, char **input, int size)
{
	int	i;

	*stack_a = stack_init();
	*stack_b = stack_init();
	if (!*stack_a || !*stack_b)
		return (0);
	i = size - 1;
	while (i >= 1)
	{
		stack_push(*stack_a, ft_atoi(input[i]));
		i--;
	}
	return (1);
}
