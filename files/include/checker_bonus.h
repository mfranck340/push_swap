/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:27:03 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 00:27:06 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h>

# define BUFFER_SIZE 8

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	int		min;
	int		max;
}	t_stack;

typedef struct s_movement
{
	int	cost;
	int	direction_a;
	int	moves_a;
	int	direction_b;
	int	moves_b;
}	t_movement;

#endif
