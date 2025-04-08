/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:40:39 by kadrouin          #+#    #+#             */
/*   Updated: 2025/04/06 14:40:39 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*ft_get_next_word(char *str, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i + j] != c && str[i + j])
		j++;
	word = malloc(sizeof(char) * (j + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (str[i] != c && str[i])
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		word_count;
	char	**words;

	i = 0;
	word_count = ft_wordcount(str, c);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	while (i < word_count)
	{
		words[i] = ft_get_next_word(str, c);
		if (!words[i])
		{
			while (i >= 0)
				free(words[i--]);
			free(words);
			return (NULL);
		}
		str += ft_strlen(words[i]) + 1;
		i++;
	}
	words[i] = NULL;
	return (words);
}
