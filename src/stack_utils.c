/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:47:35 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/04 22:07:01 by lotrapan         ###   ########.fr       */
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
		free_error(a, NULL, false, "Malloc");
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
			free_error(a, av, flag_ac, "Syntax");
		nbr = atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_error(a, av, flag_ac, "Int size");
		if (!check_doubles(*a, (int)nbr))
			free_error(a, av, flag_ac, "Doppelganger");			
		add_node(a, (int)nbr);
		i++;
	}
	if (flag_ac)
		free_split(av);
}

void	print_stack(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_printf(1, "value:%d, target_node:%d, price:%d\n", tmp->value, tmp->target_node, tmp->price);
		tmp = tmp->next;
	}
}

int stack_len(t_stack **stack)
{
	t_stack *tmp;
	int i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack *stack_last(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		if (!tmp->next)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_stack *stack_first(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		if (!tmp->prev)
			return (tmp);
		tmp = tmp->prev;
	}
	return (tmp);
}