/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:47:35 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/11 20:48:29 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_stack **a, long nbr)
{
	t_stack *new;
	t_stack *last_node;

	if (a == NULL)
		return ;
	new = malloc(sizeof(t_stack));
	if (!new)
		free_error(new, NULL, false);
	new->value = nbr;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		new->next = NULL;
	}
	else
	{
		last_node = *a;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
		new->prev = last_node;
	}
}

void	stack_init(t_stack **a, char **av, bool flag_ac)
{
	long nbr;
	int i;

	i = 0;
	while (av[i])
	{
		if (!(syntax_check(av[i])))			
			free_error(*a, av, flag_ac);
		nbr = atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_error(*a, av, flag_ac);
		if (!check_doubles(*a, (int)nbr))
			free_error(*a, av, flag_ac);			
		add_node(a, (int)nbr);
		i++;
	}
	if (flag_ac)
		free_split(av);
}

int stack_len(t_stack *stack)
{
	int len;
	t_stack *tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_stack *stack_last(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		if (!tmp->next)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void move_in_position(t_stack **a, t_stack **b, t_stack *current_best)
{
	while (current_best->prev != NULL && current_best->target_node->prev != NULL)
	{
		if (current_best->over_median && current_best->target_node->over_median)
			rr(a, b);
		else if (!current_best->over_median && !current_best->target_node->over_median)
			rrr(a, b);
		else
			break;
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
