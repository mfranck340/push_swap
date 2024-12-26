/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:55:32 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/25 23:55:40 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_stack_b(t_stack *stack, t_movement *movement)
{
	calculate_moves(stack, movement, stack->max, 1);
	do_move_b(stack, movement);
}

static void	put_all_back(t_stack *stack_a, t_stack *stack_b,
	t_movement **movements)
{
	t_node	*node_a;
	t_node	*node_b;

	while (stack_b->size > 0)
	{
		restart_movement(movements[1]);
		node_b = stack_b->top;
		if (node_b->data > stack_a->max || node_b->data < stack_a->min)
		{
			node_a = stack_a->top;
			if (node_a->data != stack_a->min)
				calculate_moves(stack_a, movements[1], stack_a->min, 0);
		}
		else
			search_position(stack_a, node_b, movements, 0);
		do_movement(stack_a, stack_b, movements[1]);
		do_pa(stack_a, stack_b);
	}
}

static void	resolve_problem(t_stack *stack_a, t_stack *stack_b,
	t_movement **movements)
{
	int	i;

	if (stack_a->size > 3)
	{
		i = 0;
		while (stack_a->size > 3 && i++ < 2)
			do_pb(stack_a, stack_b);
		while (stack_a->size > 3)
		{
			select_best_move(stack_a, stack_b, movements);
			do_movement(stack_a, stack_b, movements[0]);
			do_pb(stack_a, stack_b);
		}
		if (!is_sorted(stack_b))
			sort_stack_b(stack_b, movements[1]);
	}
	sort_little_stack(stack_a);
	put_all_back(stack_a, stack_b, movements);
	if (!is_final_sorted(stack_a))
	{
		restart_movement(movements[1]);
		calculate_moves(stack_a, movements[1], stack_a->min, 0);
		do_movement(stack_a, stack_b, movements[1]);
	}
}

static void	clean_all(t_stack *stack_a, t_stack *stack_b,
	t_movement **movements)
{
	stack_free(stack_a);
	stack_free(stack_b);
	free(movements[0]);
	free(movements[1]);
	free(movements);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_movement	**movements;

	if (argc < 2)
		return (0);
	if (!verify_input(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!init_stacks(&stack_a, &stack_b, argv, argc))
		return (0);
	movements = (t_movement **)malloc(sizeof(t_movement *) * 2);
	movements[0] = (t_movement *)malloc(sizeof(t_movement));
	movements[1] = (t_movement *)malloc(sizeof(t_movement));
	resolve_problem(stack_a, stack_b, movements);
	clean_all(stack_a, stack_b, movements);
	return (0);
}
