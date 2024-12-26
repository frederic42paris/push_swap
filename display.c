/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:13:32 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 14:58:01 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else if (b > a)
		return (b);
	else
		return (a);
}

int	countrows(t_list *stack_a, t_list *stack_b)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (stack_a)
	{
		a++;
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		b++;
		stack_b = stack_b->next;
	}
	return (max(a, b));
}

void	printstack(t_list **stack)
{
	int	i;

	i = 0;
	if (*stack)
	{
		ft_printf("%3d| ", (*stack)->num);
		ft_printf("%3d| ", (*stack)->index);
		ft_printf("%3d| ", (*stack)->sa);
		ft_printf("%3d| ", (*stack)->sb);
		ft_printf("%3d| ", (*stack)->ra);
		ft_printf("%3d| ", (*stack)->rra);
		ft_printf("%3d| ", (*stack)->rb);
		ft_printf("%3d| ", (*stack)->rrb);
		ft_printf("%3d| ", (*stack)->move);
		*stack = (*stack)->next;
	}
	else
	{
		while (i < 9)
		{
			ft_printf("  -| ");
			i++;
		}
	}
}

void	printcolumnname(void)
{
	ft_printf("num");
	ft_printf("| ");
	ft_printf("ind");
	ft_printf("| ");
	ft_printf(" sa");
	ft_printf("| ");
	ft_printf(" sb");
	ft_printf("| ");
	ft_printf(" ra");
	ft_printf("| ");
	ft_printf("rra");
	ft_printf("| ");
	ft_printf(" rb");
	ft_printf("| ");
	ft_printf("rrb");
	ft_printf("| ");
	ft_printf("mov");
	ft_printf("| ");
}

void	display(t_list *stack_a, t_list *stack_b)
{
	int	rows;

	rows = countrows(stack_a, stack_b);
	printcolumnname();
	ft_printf(" vs ");
	printcolumnname();
	ft_printf("\n");
	while (rows)
	{
		printstack(&stack_a);
		ft_printf(" vs ");
		printstack(&stack_b);
		ft_printf("\n");
		rows--;
	}
}
