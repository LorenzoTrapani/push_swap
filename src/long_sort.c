/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:11:06 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/06 19:21:31 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int set_price(t_stack **a, t_stack **b, t_stack *node_b, t_stack *target_node)
{
	int moves_b;
	int moves_target;
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	moves_b = move_price(&tmp_b, node_b->value);
	moves_target = move_price(&tmp_a, target_node->value);
	ft_printf(1, "sono qui\n");
	return (moves_b + moves_target);
}

t_stack *find_best_price(t_stack **a, t_stack **b)
{
	t_stack *tmp_b;
	t_stack *best_node;
	int best_price;
	int price;

	tmp_b = *b;
	best_price = INT_MAX;
	best_node = NULL;
	/* set_position(a);
	set_position(b); */
	set_target_node(a, b);
	while (tmp_b)
	{
		price = set_price(a, b, tmp_b, tmp_b->target_node);
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
	while (current_best->target_node->prev != NULL && current_best->prev != NULL)
	{
		if (current_best->over_median && current_best->target_node->over_median)
			rr(a, b);
		else if (!current_best->over_median && !current_best->target_node->over_median)
			rrr(a, b);
	}
	while (current_best->prev != NULL)
	{
		if (current_best->over_median)
			rb(b);
		else
			rrb(b);
	}
	while (current_best->target_node->prev != NULL)
	{
		if (current_best->target_node->over_median)
			ra(a);
		else
			rra(a);
	}
}

void	long_sort(t_stack **a, t_stack **b)
{
	while (stack_len(a) > 3)
	{
		pb(a, b);
		if (stack_len(b) > 2)
		{
			if ((*b)->value == find_highest(b)->value)
				rb(b);
			else if ((*b)->value > (*b)->next->value)
				sb(b);
		}
	}
	short_sort(a, b);
	while (*b)
	{
		manage_sort(a, b);
		pa(a, b);
	}
	while (find_lowest(a)->prev != NULL)
	{
		if (find_lowest(a)->over_median)
			ra(a);
		else
			rra(a);
	}
}
