/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:11:06 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/17 15:09:16 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	manage_sort(t_stack **a, t_stack **b)
{
	t_stack	*current_best;

	set_position(*a);
	set_position(*b);
	set_target_node(*a, *b);
	set_price(*a, *b);
	set_best(*b);
	current_best = set_best_node(*b);
	while (current_best)
	{
		if (current_best->cheapest)
			break ;
		current_best = current_best->next;
	}
	move_in_position(a, b, current_best);
}

void	long_sort(t_stack **a, t_stack **b)
{
	t_stack	*lowest;

	while (stack_len(*a) > 3)
	{
		if ((*a) == find_highest(a))
			ra(a, true);
		pb(a, b, true);
		if (stack_len(*b) > 1 && (*b) == find_lowest(b))
			rb(b, true);
	}
	if (!sort_check(*a))
		short_sort(a, b);
	while (*b)
	{
		manage_sort(a, b);
		pa(a, b, true);
	}
	lowest = find_lowest(a);
	while (*a != lowest)
	{
		if (lowest->over_median)
			ra(a, true);
		else
			rra(a, true);
	}
}
