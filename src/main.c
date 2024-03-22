/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:28:20 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/22 19:31:58 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	(void)av;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split_argv(av[1], ' ');
	stack_init(&a, av);
	if (sort_check(a))
		return (a);
	if (a->size >= 2 && a->size <= 5)
		short_sort(a, b);
	else
		long_sort(a, b);
	return (0);
}