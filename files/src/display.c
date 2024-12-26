/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:15:39 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/25 22:15:41 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_content(int n_stack, t_node **node_a, t_node **node_b)
{
	if (n_stack == 0)
	{
		ft_printf("%d\t", (*node_a)->data);
		*node_a = (*node_a)->next;
	}
	else
	{
		ft_printf("%d\n", (*node_b)->data);
		*node_b = (*node_b)->next;
	}
}

void	show_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_a;
	t_node	*node_b;
	int		i;

	node_a = stack_a->top;
	node_b = stack_b->top;
	if (stack_a->size > stack_b->size)
		i = stack_a->size;
	else
		i = stack_b->size;
	while (--i >= 0)
	{
		if (i < stack_a->size)
			print_content(0, &node_a, &node_b);
		else
			ft_printf("\t");
		if (i < stack_b->size)
			print_content(1, &node_a, &node_b);
		else
			ft_printf("\n");
	}
	ft_printf("_\t_\nA\tB\n");
}

void	show_stack(t_stack *stack, char letter)
{
	t_node	*node;
	t_node	*top;

	node = stack->top;
	top = stack->top;
	while (node->next != top)
	{
		ft_printf("%d\n", node->data);
		node = node->next;
	}
	ft_printf("%d\n", node->data);
	ft_printf("_\n%c\n", letter);
}

void	display_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 0)
	{
		show_stack(stack_b, 'B');
		return ;
	}
	if (stack_b->size == 0)
	{
		show_stack(stack_a, 'A');
		return ;
	}
	show_stacks(stack_a, stack_b);
}
