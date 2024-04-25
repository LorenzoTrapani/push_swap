/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:51:58 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/17 14:59:50 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack *tmp;

	if (src == NULL || *src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (!*dest)
	{
		*dest = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dest;
		tmp->next->prev = tmp;
		*dest = tmp;
	}
}

void pa(t_stack **a, t_stack **b, bool check)
{
	push(b, a);
	if (check)
		ft_putstr_fd("pa\n", 1);
}

void pb(t_stack **a, t_stack **b, bool check)
{
	push(a, b);
	if (check)
		ft_putstr_fd("pb\n", 1);
}
