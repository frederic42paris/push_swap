/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:56:31 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 14:57:23 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freestack(t_list	**stack_a)
{
	t_list	*nextnode;

	while (*stack_a)
	{
		nextnode = (*stack_a)->next;
		free(*stack_a);
		(*stack_a) = nextnode;
	}
}

void	createandfreearray(t_list	**stack_a, char **array)
{
	int		array_elements_num;

	array_elements_num = createarray(stack_a, array);
	free_array(array, array_elements_num);
}

int	checkerrorarray(int ac, char **argv, t_list	**stack_a)
{
	int		i;
	int		j;
	char	**array;

	i = 1;
	while (i < ac)
	{
		array = ft_split(argv[i], ' ');
		j = checkstring(array);
		if (j == 1)
		{
			createandfreearray(stack_a, array);
			return (1);
		}
		j = checkoverflow(array);
		if (j == 1)
		{
			createandfreearray(stack_a, array);
			return (1);
		}
		createandfreearray(stack_a, array);
		i++;
	}
	return (0);
}

void	sort(t_list	**stack_a, t_list	**stack_b)
{
	int		total_number_elem;

	total_number_elem = countelements(*stack_a);
	if (total_number_elem == 2)
		sort_two(stack_a);
	else if (total_number_elem == 3)
		sort_three(stack_a);
	else if (total_number_elem == 4)
		sort_four(stack_a, stack_b);
	else if (total_number_elem == 5)
		sort_five(stack_a, stack_b);
	else
		pushswap(stack_a, stack_b, total_number_elem);
	freestack(stack_a);
}

int	main(int ac, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		issorted;
	int		hasdup;
	int		haserrorarray;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || argv[1][0] == 0)
		return (0);
	haserrorarray = checkerrorarray(ac, argv, &stack_a);
	hasdup = checkduplicate(stack_a);
	if (haserrorarray == 1 || hasdup == 1)
	{
		freestack(&stack_a);
		ft_printf("Error\n");
		return (0);
	}
	issorted = checksorted(stack_a);
	if (issorted == 1)
	{
		freestack(&stack_a);
		return (0);
	}
	sort(&stack_a, &stack_b);
}

	/* printf("Initial: \n");
	display(stack_a, stack_b); */

	/* sort_three(&stack_a); */

	//sort_five(&stack_a, &stack_b);

	/* pb(&stack_a, &stack_b);
	pa(&stack_a, &stack_b); */

	/* rb(&stack_a);
	rrb(&stack_a); */

	/* sa(&stack_a);
	sa(&stack_a); */

	/* printf("Final: \n");
	display(stack_a, stack_b); */