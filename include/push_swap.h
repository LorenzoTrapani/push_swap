/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:33:57 by lotrapan          #+#    #+#             */
/*   Updated: 2024/04/04 23:12:58 by lotrapan         ###   ########.fr       */
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
	int				price;
	int 			chunk_tot;
	int				chunk_idx;
	bool			over_median;
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
//*SWAP*//
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
//*PUSH*//
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
//*ROTATE*//
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
//*REVERSE_ROTATE*//
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
//*INSERTION_SORT*//
void	insertion_sort(t_stack **stack);
//*SHORT_SORT*//
void	short_sort(t_stack **a, t_stack **b);
t_stack	*find_lowest(t_stack *stack);
t_stack	*find_highest(t_stack *stack, int len);
//*LONG_SORT*//
void	long_sort(t_stack **a, t_stack **b);
t_stack	*find_best_price(t_stack **a, t_stack **b);
//*SET*//
void	set_position(t_stack **stack);
int		move_price(t_stack **stack);
void	set_target_node(t_stack **a, t_stack **b);
//*STACK_UTILS*//
void	stack_init(t_stack **a, char **av, bool flag_ac);
void	print_stack(t_stack **stack);
void	add_node(t_stack **a, long nbr);
int		stack_len(t_stack **stack);
t_stack *stack_last(t_stack **stack);
t_stack	*stack_first(t_stack **stack);
//*FREE*//
void	free_split(char **av);
void	free_stack(t_stack *stack);
void	free_error(t_stack **a, char **av, bool flag_ac, char *error_name);

#endif