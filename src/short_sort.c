/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:34:17 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/04 16:53:50 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_highest(t_stack *stack, int len)
{
	int				highest;
	t_stack		*highest_node;
	int count;

	count = 0;
	if (stack == NULL || len <= 0)
		return (NULL);
	highest = INT_MIN;
	while (stack && count < len)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
		count++;
	}
	return (highest_node);
}

t_stack	*find_lowest(t_stack *stack)
{
	int				lowest;
	t_stack		*lowest_node;

	if (stack == NULL)
		return (NULL);
	lowest = INT_MAX;
	while (stack)
	{
		if (stack->value < lowest)
		{
			lowest = stack->value;
			lowest_node = stack;
		}
		stack = stack->next;
	}
	return (lowest_node);
}

static void mini_sort(t_stack **a, t_stack **b)
{
	t_stack *lowest;

	lowest = find_lowest(*a);
	while (stack_len(a) > 3)
	{
		if (stack_last(a) == lowest)
			rra(a);
		else
			while (*a != lowest)
				ra(a);
		pb(a, b);
		lowest = find_lowest(*a);
	}
	if (!sort_check(a))
		short_sort(a, b);
	while (*b)
		pa(a, b);
}
void short_sort(t_stack **a, t_stack **b)
{
	t_stack *highest;
	
	highest = find_highest(*a, stack_len(a));
	if (stack_len(a) == 2)
		sa(a);
	else if (stack_len(a) == 3)
	{
		if (*a == highest)
			ra(a);
		else if ((*a)->next == highest)
			rra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (stack_len(a) <= 5)
		mini_sort(a, b);	
}

