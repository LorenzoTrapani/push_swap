/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:26:31 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/11 19:20:38 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*target_node;
	long	best_match;

	while (b)
	{
		tmp_a = a;
		best_match = LONG_MAX;
		while (tmp_a)
		{
		    if (tmp_a->value > b->value && tmp_a->value < best_match)
		    {
				best_match = tmp_a->value;
				target_node = tmp_a;
		    }
		    tmp_a = tmp_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_lowest(&a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_position(t_stack *stack)
{
	int		median;
	int		position;
	t_stack	*tmp;

	tmp = stack;
	position = 0;
	int len = stack_len(tmp);
	median = len / 2;
	while (tmp)
	{
		tmp->position = position;
		if (position <= median)
			tmp->over_median = true;
		else
			tmp->over_median = false;
		tmp = tmp->next;
		position++;
	}
}

void set_price(t_stack *a, t_stack *b)
{
	int len_a;
	int len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
    while (b)
	{
		b->price = b->position;
		if (!b->over_median)
			b->price = len_b - b->position;
		if (b->target_node->over_median)
			b->price += b->target_node->position;
		else
			b->price += len_a - b->target_node->position;
		b = b->next;
	}
}

void	set_best(t_stack *b)
{
	long		best_match;
	t_stack		*best_match_node;

	if (b == NULL)
		return ;
	best_match = LONG_MAX;
	while (b)
	{
		if (b->price < best_match)
		{
			best_match = b->price;
			best_match_node = b;
		}
		else
			b->cheapest = false;
		b = b->next;
	}
	best_match_node->cheapest = true;
}

t_stack *set_best_node(t_stack *b)
{
	if (b == NULL)
		return (NULL);
	while (b)
	{
		if (b->cheapest)
			return (b);
		b = b->next;
	}
	return (NULL);
}
