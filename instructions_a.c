/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:14:22 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 15:06:30 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack)
{
	int	temp;

	temp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = temp;
	ft_printf("sa\n");
}

void	pa(t_list **stacksend, t_list **stackreceive)
{
	t_list	*second;

	second = (*stacksend)->next;
	(*stacksend)->next = (*stackreceive);
	(*stacksend)->prev = NULL;
	if (*stackreceive != NULL)
		(*stackreceive)->prev = (*stacksend);
	(*stackreceive) = (*stacksend);
	*stacksend = second;
	ft_printf("pa\n");
}

void	ra(t_list **stack)
{
	t_list	*current;
	t_list	*second;

	if ((*stack)->next)
	{
		current = *stack;
		second = (*stack)->next;
		while (current->next)
			current = current->next;
		current->next = *stack;
		current->next->next = NULL;
		current->next->prev = current;
		(*stack) = second;
		(*stack)->prev = NULL;
	}
	ft_printf("ra\n");
}

void	rra(t_list **stack)
{
	t_list	*secondlast;
	t_list	*first;

	secondlast = *stack;
	first = *stack;
	while (secondlast->next->next)
		secondlast = secondlast->next;
	secondlast->next->next = first;
	secondlast->next->prev = NULL;
	(*stack) = secondlast->next;
	(*stack)->prev = NULL;
	secondlast->next = NULL;
	ft_printf("rra\n");
}
