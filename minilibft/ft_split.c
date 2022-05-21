/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:37:44 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/27 11:37:44 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
**  Allocates (with malloc(3)) and returns an array of “fresh”
**  strings (all ending with ’\0’, including the array itself)
**  obtained by spliting "s" using the character "c" as a delimiter.
**  If the allocation fails the function returns NULL.
Example:
**  ft_split("*hello*fellow***students*", ’*’); 
Result:
**  array ["hello", "fellow", "students"].
**
** Param. #1 The string to split.
** Param. #2 The delimiter character.
*/

#include "../includes/push_swap.h"

//FT_SPLIT
static size_t	ft_strlen(const char *s);
static int	count_words(char const *s, char c);
static char	*split_word(const char *str, int start, int finish);
static char	**splitting(char **split, char const *s, char c);

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

static char	**splitting(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[j++] = split_word(s, start, i);
			start = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
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

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
