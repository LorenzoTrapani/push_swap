/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:51:25 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/27 18:53:23 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	int 	tmp;
	t_stack *small;
	t_stack *big;

	if (stack == NULL || *stack == NULL)
		return ;
	big = *stack;
	small = (*stack)->next;
	tmp = big->value;
	big->value = small->value;
	small->value = tmp;	
}

void sa(t_stack **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void sb(t_stack **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}