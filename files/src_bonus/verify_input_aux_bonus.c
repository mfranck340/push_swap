/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_input_aux_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffierro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:39:50 by ffierro-          #+#    #+#             */
/*   Updated: 2024/12/26 15:48:52 by ffierro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	verify_limits(long nb, int sign)
{
	if (sign == 1 && nb > INT_MAX)
		return (0);
	if (sign == -1 && (-nb < INT_MIN))
		return (0);
	return (1);
}

void	get_sign_number(const char *nptr, int *i, int *sign)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int	verify_number(const char *nptr, int *verify)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	get_sign_number(nptr, &i, &sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		if (!verify_limits(nb, sign))
		{
			*verify = 0;
			return (0);
		}
		i++;
	}
	return (nb * sign);
}
