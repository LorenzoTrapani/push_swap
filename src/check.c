/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:40:20 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/11 20:33:26 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort_check(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (true);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	syntax_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (i != 0)
				return (false);
			else
				i++;
		}
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_doubles(t_stack *a, long nbr)
{
	t_stack	*tmp;

	if (!a)
		return (true);
	tmp = a;
	while (tmp)
	{
		if (tmp->value == nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
