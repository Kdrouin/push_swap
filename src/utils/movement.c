/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:37:30 by kadrouin          #+#    #+#             */
/*   Updated: 2025/04/06 17:37:30 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_a_to_b(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(*a_stack);
	if (cheapest_node->mid && cheapest_node->target_node->mid)
		rotate_both(a_stack, b_stack, cheapest_node);
	else if (!(cheapest_node->mid) && !(cheapest_node->target_node->mid))
		rev_rotate_both(a_stack, b_stack, cheapest_node);
	prep_for_push(a_stack, cheapest_node, 'a');
	prep_for_push(b_stack, cheapest_node->target_node, 'b');
	pb(b_stack, a_stack, false);
}

void	move_b_to_a(t_stack **a_stack, t_stack **b_stack)
{
	prep_for_push(a_stack, (*b_stack)->target_node, 'a');
	pa(a_stack, b_stack, false);
}

void	min_on_top(t_stack **a_stack)
{
	while ((*a_stack)->nbr != find_min(*a_stack)->nbr)
	{
		if (find_min(*a_stack)->mid)
			ra(a_stack, false);
		else
			rra(a_stack, false);
	}
}
