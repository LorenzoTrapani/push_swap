/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:34:31 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/26 19:52:25 by lotrapan         ###   ########.fr       */
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

static void rotate(t_stack **stack) 
{
    t_stack *last_node;

    if (stack == NULL || *stack == NULL)
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

static void reverse_rotate(t_stack **stack)
{
	t_stack *last_node;
	t_stack *tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	tmp = last_node->prev;
	tmp->next = NULL;
	last_node->prev = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack = last_node;
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

void rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}