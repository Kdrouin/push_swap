/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:46:53 by kadrouin          #+#    #+#             */
/*   Updated: 2025/04/06 17:46:53 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	rra(t_stack **a_stack, bool print)
{
	rev_rotate(a_stack);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b_stack, bool print)
{
	rev_rotate(b_stack);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a_stack, t_stack **b_stack, bool print)
{
	rev_rotate(a_stack);
	rev_rotate(b_stack);
	if (!print)
		ft_printf("rrr\n");
}
