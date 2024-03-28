/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:47:35 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/28 19:24:44 by lotrapan         ###   ########.fr       */
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
		ft_free_error(a, NULL, false, "Malloc");
	new->value = nbr;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		new->prev = NULL;
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
			ft_free_error(a, av, flag_ac, "Syntax");
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_free_error(a, av, flag_ac, "Int size");
		if (!check_doubles(*a, (int)nbr))
			ft_free_error(a, av, flag_ac, "Doppelganger");			
		add_node(a, (int)nbr);
		i++;
	}
	if (flag_ac)
		ft_free_split(av);
}

void	print_stack(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_printf(1, "target_node: %p, value: %d, price: %d\n", tmp->target_node, tmp->value, tmp->price);
		/* ft_putnbr_fd(tmp->price, 1);
		write(1, " ", 1);
		ft_putnbr_fd(tmp->value, 1); */
		ft_putchar_fd('\n', 1);
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