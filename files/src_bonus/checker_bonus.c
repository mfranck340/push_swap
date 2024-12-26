/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:58:48 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 13:58:49 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	free_gnl(void)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		free(line);
		line = get_next_line(0);
	}
}

static int	do_instruction(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3) || !ft_strncmp(line, "sa\0", 3))
		do_sa(stack_a);
	else if (!ft_strncmp(line, "sb\n", 3) || !ft_strncmp(line, "sb\0", 3))
		do_sb(stack_b);
	else if (!ft_strncmp(line, "ss\n", 3) || !ft_strncmp(line, "ss\0", 3))
		do_ss(stack_a, stack_b);
	else if (!ft_strncmp(line, "pa\n", 3) || !ft_strncmp(line, "pa\0", 3))
		do_pa(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb\n", 3) || !ft_strncmp(line, "pb\0", 3))
		do_pb(stack_a, stack_b);
	else if (!ft_strncmp(line, "ra\n", 3) || !ft_strncmp(line, "ra\0", 3))
		do_ra(stack_a);
	else if (!ft_strncmp(line, "rb\n", 3) || !ft_strncmp(line, "rb\0", 3))
		do_rb(stack_b);
	else if (!ft_strncmp(line, "rr\n", 3) || !ft_strncmp(line, "rr\0", 3))
		do_rr(stack_a, stack_b);
	else if (!ft_strncmp(line, "rra\n", 4) || !ft_strncmp(line, "rra\0", 4))
		do_rra(stack_a);
	else if (!ft_strncmp(line, "rrb\n", 4) || !ft_strncmp(line, "rrb\0", 4))
		do_rrb(stack_b);
	else if (!ft_strncmp(line, "rrr\n", 4) || !ft_strncmp(line, "rrr\0", 4))
		do_rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static int	process_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!do_instruction(stack_a, stack_b, line))
		{
			free(line);
			close(0);
			free_gnl();
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

void	check_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && stack_b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!verify_input(argc, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!init_stacks(&stack_a, &stack_b, argv, argc))
		return (1);
	if (!process_instructions(stack_a, stack_b))
	{
		ft_printf("Error\n");
		stack_free(stack_a);
		stack_free(stack_b);
		return (1);
	}
	check_stacks(stack_a, stack_b);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
