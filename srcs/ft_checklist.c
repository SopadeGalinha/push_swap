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

//CHECK IF THE LIST IS SORTED
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

//COUNT HOW MANY NODES ARE SORTED
int	ft_count_sorted(t_list **stack)
{
	t_list *temporary;
	int		c;

	temporary = *stack;
	c = 0;
	while (temporary->next != NULL)
	{
		if (temporary->content > temporary->next->content)
			break ;
		temporary = temporary->next;
		c++;
	}
	return (c);
}

//COUNT HOW MANY NODES ARE REVERSE SORTED
int	ft_count_reverse_sorted(t_list **stack)
{
	t_list *temporary;
	int		c;

	temporary = *stack;
	c = 0;
	while (temporary->next != NULL)
	{
		if (temporary->content < temporary->next->content)
			break ;
		temporary = temporary->next;
		c++;
	}
	return (c);
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
