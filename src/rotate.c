/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:51:41 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/11 20:48:50 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack **stack) 
{
    t_stack *last_node;
	int len;

	len = stack_len(*stack);
    if (stack == NULL || *stack == NULL || len == 1)
		return ;
    last_node = *stack;
    while (last_node->next)
	    last_node = last_node->next;
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void ra(t_stack **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
