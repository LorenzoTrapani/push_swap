/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:26:31 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/04 23:12:47 by lotrapan         ###   ########.fr       */
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
	int		position;
	t_stack	*tmp;

	tmp = *stack;
	position = 0;
	median = stack_len(stack) / 2;
	while (tmp)
	{
		if (position <= median)
			tmp->over_median = true;
		else
			tmp->over_median = false;
		tmp = tmp->next;
		position++;
	}
}

int move_price(t_stack **stack)
{
    int price;
	static int index; 
    t_stack *current;

	current = *stack;
	index = 0;
    if (current->over_median) {
        price = index;
	} else {
        price = stack_len(stack) - index;
	}
	index++;
	return (price);
}
