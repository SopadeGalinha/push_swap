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

#include"push_swap.h"

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

//CHECKS IF THE ARGUMENT CONTAINS ONLY DIGITS
int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//CHECK IF IS DIGIT
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
