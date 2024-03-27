/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:28:20 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/27 16:15:07 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	
	a = NULL;
	b = NULL;
 	if (ac == 1 || (ac == 2 && !*av[1]))
		return (1);
	else if (ac == 2)
		av = ft_split_argv(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	//ft_printf(1, "Stack a before:\n");
	//print_stack(&a);
	//ft_printf(1, "Moves:\n");
	if (!sort_check(&a))
	{
		if (stack_len(&a) >= 2 && stack_len(&a) <= 5)
			short_sort(&a, &b);
		/* else
			long_sort(a, b); */
	}
	//ft_printf(1, "Stack a after:\n");
	//print_stack(&a);
	//ft_printf(1, "Stack b after:\n");
	//print_stack(&b);
	ft_free_stack(a);
	return (0);
}