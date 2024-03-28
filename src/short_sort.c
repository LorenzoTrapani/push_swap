/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:34:17 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/28 19:18:18 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_highest(t_stack *stack)
{
	int				highest;
	t_stack		*highest_node;

	if (stack == NULL)
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
	set_price(a, b);
	set_target_node(a, b);
	print_stack(a);
	write(1, "\n", 1);
	print_stack(b);
	/* if (!sort_check(a))
		short_sort(a, b); */
	/* while (*b)
		pa(a, b); */
}
void short_sort(t_stack **a, t_stack **b)
{
	t_stack *highest;
	
	highest = find_highest(*a);
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

