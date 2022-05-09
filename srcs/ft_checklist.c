/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:43:11 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/27 12:43:11 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Return 0 if the list is sorted
int	ft_is_sorted(t_list *lst)
{
	t_list	*temporary;
	
	temporary = lst;
	while (temporary->next != NULL)
	{
		if (temporary->content > temporary->next->content)
			break ;
		temporary = temporary->next;
	}
	if (temporary->next == NULL)
		return (0);
	return (1);
}

//CHECK IF THE LIST IS REVERSE SORTED
int	ft_reverse_sorted(t_list *lst)
{
	t_list	*temporary;
	
	temporary = lst;
	while (temporary->next != NULL)
	{
		if (temporary->content < temporary->next->content)
			break ;
		temporary = temporary->next;
	}
	if (temporary->next == NULL)
		return (0);
	return (1);
}

//CHECK FOR DUPLICATES
int	ft_isduplicate(t_list **lst, t_list *node)
{
	t_list *temporary;

	temporary = *lst;
	if (*lst == NULL)
		return (0);
	while (temporary->next != NULL)
	{
		if (temporary->content == node->content)
			return (1);
		temporary = temporary->next;
	}
	return (0);
}

//CHECK FOR ERRORS AND INITIALIZE THE STACK A
t_list	*ft_check_and_init(char **av, int i)
{
	t_list		*stack_a;
	t_list		*node;
	long int	_atoi;

	_atoi = 0;
	node = NULL;
	while (av[++i])
	{
		_atoi = ft_atoi_l(av[i]);
		if (_atoi > 2147483647)
			exit (write(1, "Error\n", 6));
		if (!ft_is_digit(av[i]))
			exit (write(1, "Error\n", 6));
		node = ft_lstnew((long int *)_atoi);
		ft_lstadd_back(&stack_a, node);
		if (ft_isduplicate(&stack_a, node))
			exit (write(1, "Error\n", 6));
	}
	if (!ft_is_sorted(stack_a))
		exit (write(1, "Error\n", 6));
	node = stack_a;
	return (stack_a);
}
