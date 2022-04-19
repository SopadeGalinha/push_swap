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

/*
** Init A with the list.
** Init B as empty.
** Check if the data is sorted.
** The first argument must be the head of the list
** Only numbers are allowed
** the program must work with only two arguments. Ex:
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
** The first argument should be at the top of the stack.

Errors:
some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.

*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
	void			*content;
	size_t			position;
	struct s_list	*next;
}				t_list;

int		ft_isdigit(int c);
int		ft_is_digit(char *str);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);


void	ft_lstadd_back(t_list **lst, t_list *new);
void	printlist(t_list *head);
t_list	*ft_lstlast(t_list *lst);
t_list *ft_lstnew(void *content);
t_list	ft_lstadd_front(t_list **head, t_list *new);
int	ft_lstsize(t_list *lst);
int	ft_isduplicate(t_list **lst, t_list *node);

int	ft_is_sorted(t_list *node);



int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*node;
	int			i;
	long int	_atoi;

	node = NULL;
	stack_a = NULL;
	stack_b = NULL;
	i = -1;
	_atoi = 0;
	if (ac < 2)
        return (0);
	//the program must work with two arguments. (line 20)
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else 
		i = 0;
	//init stack A
	while (av[++i])
	{
		/*Check if the data is bigger than MAX_INT(2147483647)*/
		//passing arguments to integers
		_atoi = ft_atoi(av[i]);
		//if isn't digit the program must return Error
		if (!ft_is_digit(av[i]))
			return (write(1, "Error", 5));
		
		node = ft_lstnew((long int *)_atoi);
		ft_lstadd_back(&stack_a, node);
		if (ft_isduplicate(&stack_a, node))
			return (write(1,"ErrorDup", 8));
	}
	//if (ft_checklist(stack_a))
	//	return (0);
	/*check if the list is sorted,
	and if there are duplicates*/
	printf("Size of the list: %d\n", ft_lstsize(stack_a));
	node = stack_a;
	printlist(stack_a);
	return (0);
}
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

int	ft_is_sorted(t_list *node)
{
	t_list	*temporary;
	
	int c = 0;
	temporary = node;
	while (temporary->next != NULL)
	{
		if (!(temporary > temporary->next))
		{
			c++;
		}
		temporary = temporary->next;
	}
	printf("The value of c is:%d\n", c);
	return (0);
}

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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	c_words;
	int	trigger;

	c_words = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			c_words++;
			trigger = 1;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (c_words);
}

static char	*split_word(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**splitting(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == strlen(s)) && start >= 0)
		{
			split[j++] = split_word(s, start, i);
			start = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	return (splitting(split, s, c));
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		if (result > 2147483647)
			return (0);
	}
	return (result * sign);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temporary;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	temporary = ft_lstlast(*lst);
	temporary->next = new;
}

void	printlist(t_list *head)
{
	t_list *temporary;
	
	temporary = head;
	while (temporary != NULL)
	{
		printf("%ld -", (long int)temporary->content);
		temporary = temporary->next;
	}
	printf("\n");
}

t_list *ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list ft_lstadd_front(t_list **head, t_list *new)
{
	new->next = *head;
	*head = new;
	return (*new);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!(lst))
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
