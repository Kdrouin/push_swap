/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:27:20 by kadrouin          #+#    #+#             */
/*   Updated: 2025/04/06 14:27:20 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	append_node(t_stack **a_stack, int n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!a_stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->nbr = n;
	new_node->next = NULL;
	if (!(*a_stack))
	{
		new_node->prev = NULL;
		*a_stack = new_node;
	}
	else
	{
		last_node = find_last(*a_stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	set_target_a(t_stack *a_stack, t_stack *b_stack)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match;

	while (a_stack)
	{
		best_match = LONG_MIN;
		current_b = b_stack;
		while (current_b)
		{
			if (current_b->nbr < a_stack->nbr
				&& current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a_stack->target_node = find_biggest(b_stack);
		else
			a_stack->target_node = target_node;
		a_stack = a_stack->next;
	}
}

void	cost_analysis(t_stack *a_stack, t_stack *b_stack)
{
	int		len_a;
	int		len_b;

	len_a = stack_length(a_stack);
	len_b = stack_length(b_stack);
	while (a_stack)
	{
		a_stack->push_cost = a_stack->index;
		if (!(a_stack->mid))
			a_stack->push_cost = len_a - (a_stack->index);
		if (a_stack->target_node->mid)
			a_stack->push_cost += a_stack->target_node->index;
		else
			a_stack->push_cost += len_b - (a_stack->target_node->index);
		a_stack = a_stack->next;
	}
}

void	set_cheapest(t_stack *a_stack)
{
	long	min_cost;
	t_stack	*cheapest_node;

	if (a_stack == NULL)
		return ;
	while (a_stack)
	{
		if (a_stack->push_cost < min_cost)
		{
			min_cost = a_stack->push_cost;
			cheapest_node = a_stack;
		}
		a_stack = a_stack->next;
	}
	cheapest_node->cheapest = true;
}
