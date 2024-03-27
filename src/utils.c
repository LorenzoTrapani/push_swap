/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:52:49 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/27 15:21:00 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	ft_free_error(t_stack **a, char **av, bool flag_av, char *error_name)
{
	ft_free_stack(*a);
	if (flag_av)
		ft_free_split(av);
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
