/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:15:57 by kadrouin          #+#    #+#             */
/*   Updated: 2025/04/06 14:15:57 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			mid;
	bool			cheapest;

	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

char	**ft_split(char *str, char c);
long	ft_atol(const char *s);
void	append_node(t_stack **a_stack, int n);

t_stack	*find_last(t_stack *stack);
t_stack	*find_biggest(t_stack *stack);
int		stack_length(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);

void	init_stack_a(t_stack **a_stack, char **argv);
void	sort_three(t_stack **a_stack);
void	init_nodes(t_stack *a_stack, t_stack *b_stack, int a);
void	sort_large(t_stack **a_stack, t_stack **b_stack);
void	set_target_a(t_stack *a_stack, t_stack *b_stack);
void	set_cheapest(t_stack *a_stack);
void	cost_analysis(t_stack *a_stack, t_stack *b_stack);
void	current_index(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
bool	stack_is_sorted(t_stack *stack);

void	move_b_to_a(t_stack **a_stack, t_stack **b_stack);
void	move_a_to_b(t_stack **a_stack, t_stack **b_stack);
void	min_on_top(t_stack **a_stack);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

int		error_syntax(char *str_n);
int		error_duplicate(t_stack *a, int n);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a, char **argv);
void	free_arg(char **argv);

void	pa(t_stack **a_stack, t_stack **b_stack, bool print);
void	pb(t_stack **b_stack, t_stack **a_stack, bool print);
void	rra(t_stack **a_stack, bool print);
void	rrb(t_stack **b_stack, bool print);
void	rrr(t_stack **a_stack, t_stack **b_stack, bool print);
void	ra(t_stack **a_stack, bool print);
void	rb(t_stack **b_stack, bool print);
void	rr(t_stack **a_stack, t_stack **b_stack, bool print);
void	sa(t_stack	**a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);

#endif
