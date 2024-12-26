/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:14:51 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 13:15:06 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **stack)
{
	int	temp;

	temp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = temp;
	ft_printf("sb\n");
}

void	pb(t_list **stacksend, t_list **stackreceive)
{
	t_list	*second;

	second = (*stacksend)->next;
	(*stacksend)->next = (*stackreceive);
	(*stacksend)->prev = NULL;
	if (*stackreceive != NULL)
		(*stackreceive)->prev = (*stacksend);
	(*stackreceive) = (*stacksend);
	*stacksend = second;
	ft_printf("pb\n");
}

void	rb(t_list **stack)
{
	t_list	*last;
	t_list	*second;

	if ((*stack)->next)
	{
		last = *stack;
		second = (*stack)->next;
		while (last->next)
			last = last->next;
		last->next = *stack;
		last->next->next = NULL;
		last->next->prev = last;
		(*stack) = second;
		second->prev = NULL;
	}
	ft_printf("rb\n");
}

void	rrb(t_list **stack)
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
	ft_printf("rrb\n");
}

/* void    pa(t_list **stacka, t_list **stackb)
{
    t_list    *second;

    second = (*stackb)->next;
    (*stackb)->next = (*stacka);
	(*stackb)->prev = NULL;
	if (*stacka != NULL)
		(*stacka)->prev = (*stackb);
    (*stacka) = (*stackb);
    *stackb = second;
    printf("pa\n");
} */