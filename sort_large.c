/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:01:57 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 14:33:09 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a(t_list **stack_a, t_list *temp)
{
	int		j;

	j = 0;
	if (temp->ra <= temp->rra)
	{
		while (j < temp->ra)
		{
			ra(stack_a);
			j++;
		}
	}
	else
	{
		while (j < temp->rra)
		{
			rra(stack_a);
			j++;
		}
	}
}

void	move_b(t_list **stack_b, t_list *temp)
{
	int		j;

	j = 0;
	if (temp->rb <= temp->rrb)
	{
		while (j < temp->rb)
		{
			rb(stack_b);
			j++;
		}
	}
	else
	{
		while (j < temp->rrb)
		{
			rrb(stack_b);
			j++;
		}
	}
}

void	move(t_list **stack_a, t_list **stack_b, int bestnum)
{
	t_list	*temp;

	temp = *stack_a;
	while (bestnum > 0)
	{
		temp = temp->next;
		bestnum--;
	}
	move_a(stack_a, temp);
	move_b(stack_b, temp);
	pb(stack_a, stack_b);
}

void	move_min_top(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		minvalue;

	temp = *stack_a;
	fillstackindex(stack_a, stack_b);
	minvalue = minimum_num(&temp);
	while (temp->num != minvalue)
		temp = temp->next;
	temp->ra = temp->index;
	temp->rra = countelements(*stack_a) - temp->index;
	move_a(stack_a, temp);
}

void	pushswap(t_list **stack_a, t_list **stack_b, int total_number_elem)
{
	t_list	*temp;
	int		i;
	int		b_num_found;
	int		bestnum;

	pushtwice(stack_a, stack_b);
	if ((*stack_b)->num < (*stack_b)->next->num)
		sb(stack_b);
	i = 0;
	while (i < total_number_elem - 2)
	{
		fillstackindex(stack_a, stack_b);
		temp = *stack_a;
		while (temp)
		{
			b_num_found = find_position_b(stack_b, temp->num);
			calculate_least_moves(stack_a, stack_b, b_num_found, &temp);
			temp = temp->next;
		}
		bestnum = minimum_moves(stack_a);
		move(stack_a, stack_b, bestnum);
		i++;
	}
	push_all(stack_a, stack_b, total_number_elem);
	move_min_top(stack_a, stack_b);
}
