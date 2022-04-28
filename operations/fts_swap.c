/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:01:39 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/28 14:57:40 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Swap the first 2 elements at the top of stack.
//Do nothing if there is only one or no elements.

//SWAP FUNCTION
void	swap(t_list **stack)
{
	t_list	*swap;
	t_list	*tmp;

	tmp = *stack;
	swap =(*stack)->next;
	(*stack)->next = swap->next;
	*stack = swap;
	(*stack)->next = tmp;
}
// Swap the first 2 elements at the top of stack a.
void	sa(t_list **stack_a)
{
	if (!stack_a || !*stack_a || ft_lstsize(*stack_a) < 2)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
}

//SB: Swap the first 2 elements at the top of stack b.
void	sb(t_list **stack_b)
{
	if (!stack_b || !*stack_b || ft_lstsize(*stack_b) < 2)
		return ;
	swap(stack_b);
	write(1, "sb\n", 3);
	
}

//SS: sa and sb at the same time.
void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write (1, "ss\n", 3);
}
