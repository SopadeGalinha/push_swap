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

// The first element becomes the last one

//ROTATE FUNCTION
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

// Shift up all elements of stack a by 1.
void	ra(t_list **stack_a)
{
	if (ft_lstsize(stack_a) < 2)
		return ;
	rotate(stack_a);
	write (1, "ra\n", 3);
}

// Shift up all elements of stack b by 1.
void	rb(t_list **stack_b)
{
	if (ft_lstsize(stack_b) < 2)
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
