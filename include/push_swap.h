/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:33:57 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/27 17:07:31 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
////////////////
///STRUCTURES///
////////////////

typedef struct s_stack
{
	int				*stack;
	int				size;
	int				value;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

///////////////
///FUNCTIONS///
///////////////

//*CHECK*//
bool	sort_check(t_stack **a);
bool	syntax_check(char *str);
bool	check_doubles(t_stack *a, long nbr);
//*COMMAND*//
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
//*SHORT_SORT*//
void	short_sort(t_stack **a, t_stack **b);
//*LONG_SORT*//
//*STACK_UTILS*//
void		stack_init(t_stack **a, char **av, bool flag_ac);
void		print_stack(t_stack **stack);
void		add_node(t_stack **a, long nbr);
int			stack_len(t_stack **stack);
t_stack 	*stack_last(t_stack **stack);
//*FREE*//
void	ft_free_split(char **av);
void	ft_free_stack(t_stack *stack);
void	ft_free_error(t_stack **a, char **av, bool flag_ac, char *error_name);

#endif