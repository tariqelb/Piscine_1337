/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:54:47 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/22 14:42:22 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_fill_table(char *str, char *table, int i, int j)
{
	int	index;
	int	k;

	index = 0;
	k = i - j;
	table = (void *) 0;
	table = (char *) malloc(sizeof(char) * (j + 1));
	if (table != (void *) 0)
	{
		while (k < i)
		{
			table[index] = str[k];
			k++;
			index++;
		}
		table[index] = '\0';
	}
	return (table);
}

char	**ft_alocate(char *str, char *charset, char **table, int i)
{
	int	j;
	int	k;

	k = 0;
	while (str[i] != '\0')
	{
		if (ft_charset(str[i], charset) == 0)
		{
			j = 0;
			while (str[i + j] != '\0' && ft_charset(str[i + j], charset) == 0)
				j++;
			i = i + j;
			if (ft_charset(str[i], charset) == 1 || str[i] == '\0')
			{
				table[k] = ft_fill_table(str, table[k], i, j);
				k++;
			}
		}
		else
			i++;
	}
	return (table);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	flag;
	int	words;

	words = 0;
	flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_charset(str[i], charset) == 0)
			flag = 1;
		if (ft_charset(str[i], charset) == 1 && flag == 1)
		{
			flag = 0;
			words++;
		}
		i++;
	}
	if (str[i] == '\0' && flag == 1 )
		words++;
	return (words);
}

char	**ft_split(char *str, char *charset)
{
	int		index;
	int		words;
	char	**table;

	table = (void *) 0;
	index = 0;
	words = 0;
	words = ft_count_words(str, charset);
	table = (char **) malloc(sizeof(char *) * (words + 1));
	if (table != (void *) 0)
	{
		table = ft_alocate(str, charset, table, index);
		table[words] = (void *) 0;
	}
	return (table);
}
