/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:49:58 by kadrouin          #+#    #+#             */
/*   Updated: 2025/04/06 17:49:58 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a_stack, bool print)
{
	rotate(a_stack);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack **b_stack, bool print)
{
	rotate(b_stack);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack **a_stack, t_stack **b_stack, bool print)
{
	rotate(a_stack);
	rotate(b_stack);
	if (!print)
		ft_printf("rr\n");
}
