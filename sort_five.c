/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:06:45 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 13:06:46 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list **stack_a)
{
	t_list	*temp;
	int		i;
	int		min;

	i = 0;
	temp = *stack_a;
	min = minimum_num(stack_a);
	while (temp->next && temp->num != min)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	move_min(t_list **stack_a)
{
	int		i;
	int		j;

	i = find_min(stack_a);
	if (i <= countelements(*stack_a) - i)
	{
		j = i;
		while (j > 0)
		{
			ra(stack_a);
			j--;
		}
	}
	else
	{
		j = countelements(*stack_a) - i;
		while (j > 0)
		{
			rra(stack_a);
			j--;
		}
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	move_min(stack_a);
	pb(stack_a, stack_b);
	move_min(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

/* void	sort_three_des(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (temp->next->num < temp->num)
		sb(stack);
	temp = *stack;
	if (temp->num < temp->next->next->num)
		rb(stack);
	temp = *stack;
	if (temp->num < temp->next->num)
		sb(stack);
} */