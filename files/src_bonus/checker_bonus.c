#include "../include/checker_bonus.h"

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

static int	is_sort_down(t_stack *stack)
{
	t_node	*node;

	if (stack->size <= 1)
		return (1);
	node = stack->top;
	if (node->value < node->next->value)
		node = node->next;
	else
		return (0);
	while (node->next != stack->top)
	{
		if (node->value < node->next->value)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

static int	check_instruction(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3) || !ft_strncmp(line, "sa\0", 3))
		return (sa(stack_a));
	else if (!ft_strncmp(line, "sb\n", 3) || !ft_strncmp(line, "sb\0", 3))
		return (sb(stack_b));
	else if (!ft_strncmp(line, "ss\n", 3) || !ft_strncmp(line, "ss\0", 3))
		return (ss(stack_a, stack_b));
	else if (!ft_strncmp(line, "pa\n", 3) || !ft_strncmp(line, "pa\0", 3))
		return (pa(stack_a, stack_b));
	else if (!ft_strncmp(line, "pb\n", 3) || !ft_strncmp(line, "pb\0", 3))
		return (pb(stack_a, stack_b));
	else if (!ft_strncmp(line, "ra\n", 3) || !ft_strncmp(line, "ra\0", 3))
		return (ra(stack_a));
	else if (!ft_strncmp(line, "rb\n", 3) || !ft_strncmp(line, "rb\0", 3))
		return (rb(stack_b));
	else if (!ft_strncmp(line, "rr\n", 3) || !ft_strncmp(line, "rr\0", 3))
		return (rr(stack_a, stack_b));
	else if (!ft_strncmp(line, "rra\n", 4) || !ft_strncmp(line, "rra\0", 4))
		return (rra(stack_a));
	else if (!ft_strncmp(line, "rrb\n", 4) || !ft_strncmp(line, "rrb\0", 4))
		return (rrb(stack_b));
	else if (!ft_strncmp(line, "rrr\n", 4) || !ft_strncmp(line, "rrr\0", 4))
		return (rrr(stack_a, stack_b));
	return (0);
}

int	check_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_instruction(stack_a, stack_b, line))
		{
			free(line);
			clean_stack(stack_a);
			clean_stack(stack_b);
			close(0);
			free_gnl();
			return (show_error());
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_sort_down(stack_a) && stack_b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clean_stack(stack_a);
	clean_stack(stack_b);
	return (0);
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof (t_stack));
	if (!stack)
		return (0);
	stack->top = 0;
	stack->size = 0;
	stack->max_value = 0;
	stack->min_value = 0;
	return (stack);
}

void	add_elem(t_stack *stack, t_node *node, int value)
{
	node->value = value;
	node->position = stack->size;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->max_value = node->value;
		stack->min_value = node->value;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = stack->top;
		node->prev = stack->top->prev;
		stack->top->prev->next = node;
		stack->top->prev = node;
		if (node->value < stack->min_value)
			stack->min_value = node->value;
		else if (node->value > stack->max_value)
			stack->max_value = node->value;
	}
	stack->size++;
}

static t_stack	*fill_a_aux(t_stack *stack_a, char **args, int num_args)
{
	t_node	*node;
	int		i;

	i = -1;
	while (++i < num_args)
	{
		node = (t_node *)malloc(sizeof (t_node));
		if (!node || (ft_atoi(args[i]) == 0 && args[i][0] != '0')
			|| ft_atoi(args[i]) > INT_MAX || ft_atoi(args[i]) < INT_MIN
			|| in_stack(stack_a, ft_atoi(args[i])))
		{
			free(node);
			free_args(args, num_args);
			return (clean_stack(stack_a));
		}
		add_elem(stack_a, node, ft_atoi(args[i]));
	}
	free_args(args, num_args);
	return (stack_a);
}

t_stack	*fill_a(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**args;
	int		num_args;

	stack_a = new_stack();
	if (!stack_a)
		return (0);
	num_args = 0;
	args = parse_args(argc, argv, &num_args);
	if (!args)
		return (clean_stack(stack_a));
	if (num_args < 1)
	{
		free_args(args, num_args);
		return (clean_stack(stack_a));
	}
	return (fill_a_aux(stack_a, args, num_args));
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = fill_a(argc, argv);
	if (!stack_a)
		return (show_error());
	if (stack_a->size == 1)
	{
		clean_stack(stack_a);
		return (1);
	}
	stack_b = new_stack();
	if (!stack_b)
	{
		clean_stack(stack_a);
		return (show_error());
	}
	return (check_instructions(stack_a, stack_b));
}