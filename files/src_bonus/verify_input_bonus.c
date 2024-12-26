/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:37:35 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 15:46:59 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	check_characters(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i])
			&& !(input[i] == '-' && ft_isdigit(input[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	check_numbers(char **arr, int *n_arr)
{
	int	i;
	int	n_aux;
	int	flag;

	i = 1;
	while (arr[i])
	{
		flag = 1;
		n_aux = verify_number(arr[i], &flag);
		if (!flag)
			return (0);
		n_arr[i - 1] = n_aux;
		i++;
	}
	return (1);
}

int	check_repeated(int *n_arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (n_arr[i] == n_arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verify_input(int argc, char **argv)
{
	int		*n_arr;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!check_characters(argv[i]))
			return (0);
		i++;
	}
	n_arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!n_arr)
		return (0);
	if (!check_numbers(argv, n_arr))
		return (free(n_arr), 0);
	if (!check_repeated(n_arr, (argc - 1)))
		return (free(n_arr), 0);
	free(n_arr);
	return (1);
}
