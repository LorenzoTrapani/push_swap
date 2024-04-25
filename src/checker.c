/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:29:50 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/25 19:29:19 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	putmessage(t_stack *a, t_stack *b)
{
	if (!b && sort_check(a))
		ft_putstr_fd("OK\n", 1);
	else
	{
		if (b)
			free_stack(b);
		ft_putstr_fd("KO\n", 1);
	}
}

static void	error_checker(t_stack **a, t_stack **b, char *line)
{
	free_stack(*a);
	free_stack(*b);
	free(line);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	command_check(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "ra\n"))
		ra(a, false);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, false);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, false);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, false);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, false);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, false);
	else if (!ft_strcmp(line, "sa\n"))
		sa(a, false);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, false);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, false);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, false);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, false);
	else
		error_checker(a, b, line);
}

static void	execute_command(t_stack **a, t_stack **b)
{
	char	*line;

	line = ft_get_next_line(0);
	while (line && ft_strcmp(line, "\n"))
	{
		command_check(a, b, line);
		free(line);
		line = ft_get_next_line(0);
	}
	if (line)
		free(line);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else if ((ac == 2 && (!*av[1] || *av[1] == ' ')) || (ft_strnstr(av[1], "  ",
				ft_strlen(av[1]))))
		return (ft_putstr_fd("Error\n", 2), 1);
	else if (ac == 2)
		av = ft_split_argv(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	execute_command(&a, &b);
	putmessage(a, b);
	free_stack(a);
	return (0);
}
