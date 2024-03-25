/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:34:17 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/25 20:03:43 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void short_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		ft_putstr_fd("sa\n", 1);
		swap(&a);
	}
	b = NULL;
	/* else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b); */
}
