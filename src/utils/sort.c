/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:18:36 by kadrouin          #+#    #+#             */
/*   Updated: 2025/04/06 17:18:36 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

void	sort_large(t_stack **a_stack, t_stack **b_stack)
{
	int	length;

	length = stack_length(*a_stack);
	if (length-- > 3 && !stack_is_sorted(*a_stack))
		pb(b_stack, a_stack, false);
	if (length-- > 3 && !stack_is_sorted(*a_stack))
		pb(b_stack, a_stack, false);
	while (length-- > 3 && !stack_is_sorted(*a_stack))
	{
		init_nodes(*a_stack, *b_stack, 1);
		move_a_to_b(a_stack, b_stack);
	}
	sort_three(a_stack);
	while (*b_stack)
	{
		init_nodes(*a_stack, *b_stack, 0);
		move_b_to_a(a_stack, b_stack);
	}
	current_index(*a_stack);
	min_on_top(a_stack);
}
