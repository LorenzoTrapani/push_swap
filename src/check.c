/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:40:20 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/22 19:14:05 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort_check(t_stack *a)
{
	t_stack *tmp;

	if (!a)
		return (true);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool  syntax_check(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_doubles(t_stack *a, long nbr)
{
	t_stack *tmp;

	if (!a)
		return (false);
	tmp = a;
	while (tmp)
	{
		if (tmp->nbr == nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}