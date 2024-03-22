/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:47:35 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/22 19:30:40 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *a)
{
	if (!a)
		return ;
	free(a->stack);
	free(a);
}

void	stack_init(t_stack **a, char **av)
{
	long nbr;
	int i;
	int size;

	i = 0;
	while (av[i])
	{
		if (!(syntax_check(av[i])))
			ft_error('S');
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_putstr_fd("Int size Error\n", 2);
		if (check_doubles(*a, nbr))
			ft_putstr_fd("Doppelganger Error\n", 2);
		ft_list_add_back(a, ft_list_new(nbr));
		i++;
	}
	if (a == NULL)
	{
		ft_putstr_fd("No numbers Error\n", 2);
		exit(1);
	}
	size = ft_list_size(*a);
	(*a)->size = size;
}
	