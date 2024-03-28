/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:26:31 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/28 19:36:23 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_target_node(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*target_node;
	long	best_match;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_b)
	{
		best_match = LONG_MAX;
		while (tmp_a)
		{
		    if (tmp_a->value > tmp_b->value && tmp_a->value < best_match)
		    {
				best_match = tmp_a->value;
				target_node = tmp_a;
		    }
		    tmp_a = tmp_a->next;
		}
		if (best_match == LONG_MAX)
			tmp_b->target_node = find_lowest(*a);
		else
			tmp_b->target_node = target_node;
		tmp_b = tmp_b->next;
	}
}

void	set_position(t_stack **stack)
{
	int		median;
	t_stack	*tmp;

	tmp = *stack;
	median = stack_len(stack) / 2;
	while (tmp)
	{
		if (tmp->value <= median)
			tmp->over_median = true;
		else
			tmp->over_median = false;
		tmp = tmp->next;
	}
}

void	set_price(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack *rotable;
	int		price;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_b)
	{
		price = 0;
		rotable = tmp_b;
		if (tmp_b->over_median)
		{
			while (rotable != stack_first(b))
			{
				rb(&rotable);
				price++;
			}
		}
		else if (!tmp_b->over_median)
		{
			while (rotable != stack_last(b))
			{
				rrb(&rotable);
				price++;
			}
		}
		tmp_b->price = price;
		tmp_b = tmp_b->next;
	}
}
