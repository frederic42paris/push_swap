/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:06:28 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 13:06:35 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack)
{
	sa(stack);
}

void	sort_three(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (temp->next->num > temp->num)
		sa(stack);
	temp = *stack;
	if (temp->num > temp->next->next->num)
		ra(stack);
	temp = *stack;
	if (temp->num > temp->next->num)
		sa(stack);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	move_min(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
}
