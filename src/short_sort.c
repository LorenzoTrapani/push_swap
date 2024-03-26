/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:34:17 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/26 19:41:29 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_highest(t_stack *stack)
{
	int				highest;
	t_stack		*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void short_sort(t_stack **a, t_stack **b)
{
	t_stack *highest;

	if ((*a)->size == 2)
		sa(a);
	else if ((*a)->size == 3)
	{
		highest = find_highest(*a);
		if (*a == highest)
			ra(a);
		else if ((*a)->next == highest)
			rra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	*b = NULL;
	/*else if (a->size <= 5)
		sort_five(a, b); */
}
