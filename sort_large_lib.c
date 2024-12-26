/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_lib.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:14:44 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 14:32:54 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_b(t_list **stack_b, int number)
{
	int		min;
	int		max;
	int		findnum;
	t_list	*temp;

	min = minimum_num(stack_b);
	max = maximum_num(stack_b);
	findnum = 0;
	temp = *stack_b;
	if (number < min || number > max)
		return (max);
	else
	{
		while (temp != NULL)
		{
			if (number > temp->num && temp->num > findnum)
				findnum = temp->num;
			temp = temp->next;
		}
		return (findnum);
	}
}

void	calculate_least_moves(t_list **a, t_list **b, int b_num, t_list **cur)
{
	t_list	*temp;
	t_list	*search;

	temp = *cur;
	search = *b;
	temp->ra = temp->index;
	temp->rra = countelements(*a) - temp->index;
	while (b_num != search->num)
	{
		search = search->next;
	}
	temp->rb = search->index;
	temp->rrb = countelements(*b) - search->index;
	temp->move = min(temp->ra, temp->rra) + min(temp->rb, temp->rrb);
}

void	fillstackindex(t_list **a, t_list **b)
{
	fillindex(*a);
	fillindex(*b);
}

void	pushtwice(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
}
