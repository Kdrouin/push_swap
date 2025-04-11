/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:02:40 by kadrouin          #+#    #+#             */
/*   Updated: 2025/04/06 18:02:40 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	set_target_b(t_stack *a_stack, t_stack *b_stack)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b_stack)
	{
		best_match_index = LONG_MAX;
		current_a = a_stack;
		while (current_a)
		{
			if (current_a->nbr > b_stack->nbr
				&& current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b_stack->target_node = find_min(a_stack);
		else
			b_stack->target_node = target_node;
		b_stack = b_stack->next;
	}
}

void	init_nodes(t_stack *a_stack, t_stack *b_stack, int a)
{
	if(a == 1)
	{
		current_index(a_stack);
		current_index(b_stack);
		set_target_a(a_stack, b_stack);
		cost_analysis(a_stack, b_stack);
		set_cheapest(a_stack);
	}
	else
	{
		current_index(a_stack);
		current_index(b_stack);
		set_target_b(a_stack, b_stack);
	}
}

void	init_stack_a(t_stack **a_stack, char **argv)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a_stack);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a_stack);
		if (error_duplicate(*a_stack, (int)n))
			free_errors(a_stack);
		append_node(a_stack, (int)n);
		i++;
	}
}

static int	handle_long(const char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(s[i + j])
	{
		if (s[i + j] == '0')
			j++;
		else if (s[i + j] != '0')
			i++;
	}
	return(i);
}
long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	if(handle_long(s) >= 12)
			free_errors(NULL);}
	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}
