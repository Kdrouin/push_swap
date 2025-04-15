/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:29:43 by kadrouin          #+#    #+#             */
/*   Updated: 2025/04/06 14:29:43 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	main_loop(t_stack **a_stack, t_stack **b_stack)
{
	while (!stack_is_sorted(*a_stack) && (*a_stack)->next != NULL)
	{
		if (stack_length(*a_stack) == 2)
			sa(a_stack, false);
		else if (stack_length(*a_stack) == 3)
			sort_three(a_stack);
		else
			sort_large(a_stack, b_stack);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	**splited;

	if (argc < 2)
		return (1);
	if (argc == 2)
		splited = ft_split(argv[1], ' ');
	else
		splited = argv;
	a_stack = NULL;
	b_stack = NULL;
	init_stack_a(&a_stack, splited);
	main_loop(&a_stack, &b_stack);
	free_stack(&a_stack);
	if (argc == 2)
		free_arg(splited);
	return (0);
}
