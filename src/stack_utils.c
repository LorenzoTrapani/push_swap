/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:47:35 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/25 19:02:08 by lotrapan         ###   ########.fr       */
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
		ft_error('M');
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
			ft_error('S');
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_putstr_fd("Int size Error\n", 2);
		if (!check_doubles(*a, (int)nbr))
			ft_putstr_fd("Doppelganger Error\n", 2);
		add_node(a, (int)nbr);
		i++;
	}
	(*a)->size = i;
	if (flag_ac)
		ft_free_split(av);
}

void	print_stack(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}
	