/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:08:35 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/22 14:33:23 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct t_list
{
	int				num;
	int				index;
	int				sa;
	int				sb;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				move;
	struct t_list	*next;
	struct t_list	*prev;
}	t_list;

// libft
size_t	ft_strlen(const char *string);
int		ft_isdigit(int character);
long	ft_atoi(const char *string);
char	**ft_split(char const *s, char c);
int		ft_printf(const char *str, ...);

// checkerrors
int		checkstring(char **array);
int		checkduplicate(t_list *stack_a);
int		checkoverflow(char **array);
int		checksorted(t_list	*stack_a);

// utils
int		countelements(t_list *stack_a);
int		minimum_num(t_list **stack);
int		ft_strcmp(const char *first, const char *second);
void	free_array(char **array, int wordnbr);
void	move_min(t_list **stack_a);
int		min(int a, int b);
void	fillindex(t_list *stack_a);
int		maximum_num(t_list **stack);
void	push_all(t_list **stack_a, t_list **stack_b, int total_number_elem);
int		minimum_moves(t_list **stack);
int		find_position_b(t_list **stack_b, int number);
void	calculate_least_moves(t_list **a, t_list **b, int b_num, t_list **cur);
void	fillstackindex(t_list **a, t_list **b);
void	pushtwice(t_list **stack_a, t_list **stack_b);

// linked list - create and display
void	display(t_list *stack_a, t_list *stack_b);
int		createarray(t_list	**stack_a, char **array);

// instructions
void	sa(t_list **pp);
void	sb(t_list **stack);
void	pa(t_list **stacksend, t_list **stackreceive);
void	pb(t_list **stacksend, t_list **stackreceive);
void	ra(t_list **stacka);
void	rb(t_list **stack);
void	rra(t_list **stacka);
void	rrb(t_list **stack);
// sort
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	pushswap(t_list **stack_a, t_list **stack_b, int total_number_elem);

#endif