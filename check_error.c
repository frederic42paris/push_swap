/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:08:45 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 13:10:11 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkstring(char **array)
{
	int		i;
	int		j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (ft_isdigit(array[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checkduplicate(t_list *stack_a)
{
	t_list	*temp;

	while (stack_a)
	{
		temp = stack_a->next;
		while (temp)
		{
			if (stack_a->num == temp->num)
				return (1);
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	checkoverflow(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		if (ft_atoi(array[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	checksorted(t_list	*stack_a)
{
	int		i;

	i = stack_a->num;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->num < i)
			return (0);
		else
		{
			i = stack_a->num;
			stack_a = stack_a->next;
		}
	}
	return (1);
}
