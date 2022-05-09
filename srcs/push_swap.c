/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:28:09 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/16 12:28:09 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = -1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		i = 0;
	stack_a = ft_check_and_init(av, i);
	printf("Stack A: ");
	ft_printlist(stack_a);
	ft_sort_numbers(&stack_a, &stack_b);
	printf("\nStack A: ");
	ft_printlist(stack_a);
	if (stack_b)
	{
		printf("\nStack B: ");
		ft_printlist(stack_b);
	}
}
