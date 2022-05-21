/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:41:27 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/05/21 00:42:00 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//PA: Take the first element at the top of b and put it at the top of a
//PB: Take the first element at the top of a and put it at the top of b

#include "../includes/push_swap.h"

//PUSH FUNCTION
void push(t_list **stack_src, t_list **stack_dst)
{
	t_list *temporary;
	temporary = *stack_src;
	*stack_src = (*stack_src)->next;
	temporary->next = *stack_dst;
	*stack_dst = temporary;
}

//PA: Take the first element at the top of b and put it at the top of a
void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b)
		return ;
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

//PB: Take the first element at the top of a and put it at the top of b
void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		return ;
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
