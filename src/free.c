/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:52:49 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/03 19:19:00 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **av)
{
	int	i;

	i = -1;
	if ( av == NULL || *av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_error(t_stack **a, char **av, bool flag_av, char *error_name)
{
	free_stack(*a);
	if (flag_av)
		free_split(av);
	if (ft_strcmp(error_name, "Syntax") == 0)
		ft_putstr_fd("Syntax Error\n", 2);
	else if (ft_strcmp(error_name, "Doppelganger") == 0)
		ft_putstr_fd("Doppelganger Error\n", 2);
	else if (ft_strcmp(error_name, "Int size") == 0)
		ft_putstr_fd("Int size Error\n", 2);
	else if (ft_strcmp(error_name, "Malloc") == 0)
		ft_putstr_fd("Malloc Error\n", 2);	
	exit(1);
}
