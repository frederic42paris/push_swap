/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:11:50 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 13:12:29 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **p, int val)
{
	t_list	*element;
	t_list	*last;

	last = *p;
	element = malloc(sizeof(t_list));
	element->num = val;
	element->next = NULL;
	if (*p == NULL)
	{
		*p = element;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = element;
	element->prev = last;
}

int	createarray(t_list	**stack_a, char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		push(stack_a, atoi(array[i]));
		i++;
	}
	return (i);
}

/*
void	push(t_list **p, int val)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	element->num = val;
	element->next = *p;
	element->prev = NULL;
	if (*p != NULL)
		(*p)->prev = element;
	*p = element;
}
*/