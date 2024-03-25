/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:28:20 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/25 18:39:37 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	
	a = NULL;
	b = NULL;
 	if (ac == 1)
	{
		ft_putstr_fd("Arguments Error\n", 2);
		return (1);
	}
	else if (ac == 2)
		av = ft_split_argv(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	print_stack(a);
	/* if (sort_check(a))
		return (0); */
	/* if (a->size >= 2 && a->size <= 5)
		short_sort(a, b);
	else
		long_sort(a, b); */
	return (0);
}