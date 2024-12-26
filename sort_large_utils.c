/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:00:34 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 14:13:08 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else if (b < a)
		return (b);
	else
		return (a);
}

void	fillindex(t_list *stack_a)
{
	t_list	*temp;
	int		i;

	temp = stack_a;
	i = 0;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}

int	maximum_num(t_list **stack)
{
	int		max;
	t_list	*temp;

	temp = *stack;
	max = INT_MIN;
	while (temp != NULL)
	{
		if (max < temp->num)
			max = temp->num;
		temp = temp->next;
	}
	return (max);
}

void	push_all(t_list **stack_a, t_list **stack_b, int total_number_elem)
{
	int	i;

	i = 0;
	while (i < total_number_elem)
	{
		pa(stack_b, stack_a);
		i++;
	}
}

int	minimum_moves(t_list **stack)
{
	int		min;
	int		index;
	t_list	*temp;

	min = INT_MAX;
	index = 0;
	temp = *stack;
	while (temp != NULL)
	{
		if (min > temp->move)
		{
			min = temp->move;
			index = temp->index;
		}
		temp = temp->next;
	}
	return (index);
}
