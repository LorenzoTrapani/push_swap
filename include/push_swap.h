/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:33:57 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/22 19:36:43 by lotrapan         ###   ########.fr       */
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
bool	sort_check(t_stack *a);
bool	syntax_check(char *str);
bool	check_doubles(t_stack *a, long nbr);
//*COMMAND*//
//*SHORT_SORT*//
void	short_sort(t_stack *a, t_stack *b);
//*LONG_SORT*//
//*STACK_UTILS*//
void	stack_init(t_stack **a, char **av);
void	stack_free(t_stack *a);

#endif