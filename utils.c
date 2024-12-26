/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:53:19 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 12:53:42 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array, int wordnbr)
{
	int	i;

	i = 0;
	while (i < wordnbr)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	countelements(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

int	ft_strcmp(const char *first, const char *second)
{
	size_t	i;

	i = 0;
	while (first[i] != '\0' && second[i] != '\0'
		&& first[i] == second[i])
	{
		i++;
	}
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}

int	minimum_num(t_list **stack)
{
	int		min;
	t_list	*temp;

	temp = *stack;
	min = INT_MAX;
	while (temp != NULL)
	{
		if (min > temp->num)
			min = temp->num;
		temp = temp->next;
	}
	return (min);
}
