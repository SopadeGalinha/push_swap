/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:18:55 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/27 11:18:55 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//The last element becomes the first one.

//REVERSE ROTATE
void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	
	tail = *stack;
	while (tail->next)
	{
		tmp = tail;
		tail = tail->next;
	}
	tail->next = *stack;
	tmp->next = NULL;
	*stack = tail;
}

// Shift down all elements of stack a by 1
void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

// Shift down all elements of stack b by 1
void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}
// rra and rrb at the same time
void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
