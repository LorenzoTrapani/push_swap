/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:11:06 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/04 23:36:07 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int set_price(t_stack **b, t_stack *target_node)
{
	int moves_b;
	int moves_target;
	t_stack *tmp_b;

	tmp_b = *b;
	moves_b = move_price(&tmp_b);
	moves_target = move_price(&target_node);
	return (moves_b + moves_target);
}

t_stack *find_best_price(t_stack **a, t_stack **b)
{
	t_stack *tmp_b;
	t_stack *best_node;
	static int best_price;
	int price;

	tmp_b = *b;
	best_price = INT_MAX;
	best_node = NULL;
	set_position(a);
	set_position(b);
	set_target_node(a, b);
	while (tmp_b)
	{
		price = set_price(b, tmp_b->target_node);
		if (price < best_price)
		{
			best_node = tmp_b;
			best_price = tmp_b->price;
		}
		tmp_b = tmp_b->next;		
	}
	return (best_node);
}

static void manage_sort(t_stack **a, t_stack **b)
{
	t_stack *current_best;

	current_best = find_best_price(a, b);
	set_position(a);
	set_position(b);	
	if (current_best == *b)
	{
		if ((*b)->over_median)
		{
			while ((*b)->value != (*b)->target_node->value)
				rb(b);
		}
		else
		{
			while ((*b)->value != (*b)->target_node->value)
				rrb(b);
		}
		if ((*a)->over_median)
		{
			while ((*a)->value != (*a)->target_node->value)
				ra(a);
		}
		else
		{
			while ((*a)->value != (*a)->target_node->value)
				rra(a);
		}
	}
}

void	long_sort(t_stack **a, t_stack **b)
{
	while (stack_len(a) > 3)
		pb(a, b);
	short_sort(a, b);
	while (*b)
	{
		manage_sort(a, b);
		pa(a, b);
	}
}
