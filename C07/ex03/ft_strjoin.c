/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:24:14 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/26 14:48:18 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strs_length(char **strs, int size)
{
	int	index_i;
	int	index_j;
	int	len;

	len = 0;
	index_i = 0;
	while (index_i < size)
	{
		index_j = 0;
		while (strs[index_i][index_j] != '\0')
			index_j++;
		len = len + index_j;
		index_i++;
	}
	return (len);
}

char	*ft_join(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			dest[k++] = strs[i][j++];
		}
		j = 0;
		if (i != size - 1)
		{
			while (sep[j] != '\0')
				dest[k++] = sep[j++];
		}
		i++;
	}
	dest[k] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		str_len;
	char	*dest;
	int		sep_len;
	int		length;

	dest = (void *) 0;
	if (size < 1)
	{
		dest = (char *) malloc(sizeof(char) * 1);
		return (dest);
	}
	sep_len = 0;
	while (sep[sep_len] != '\0')
		sep_len++;
	str_len = ft_strs_length(strs, size);
	length = ((size - 1) * sep_len) + str_len + 1;
	dest = (char *) malloc(sizeof(char) * length);
	if (dest != (void *) 0)
		dest = ft_join(size, strs, sep, dest);
	return (dest);
}
