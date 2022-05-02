/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:16:23 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/27 11:16:23 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

//ROTATE FUNCTION

// The first element becomes the last one
void	rotate(t_list **stack)
{
	t_list	*tail;
	t_list	*head;

	tail = *stack;
	while (tail->next)	
		tail = tail->next;
	head = *stack;
	*stack = (*stack)->next;
	tail->next = head;
	head->next = NULL;
}

// The first element of A becomes the last one
void	ra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) < 2)
		return ;
	rotate(stack_a);
	write (1, "ra\n", 3);
}

// The first element of B becomes the last one
void	rb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) < 2)
		return ;
	rotate(stack_b);
	write(1, "rb\n", 3);
}

// ra and rb at the same time.
void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write (1, "rr\n", 3);
}
