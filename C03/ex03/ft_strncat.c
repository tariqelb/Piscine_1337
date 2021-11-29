/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:02:25 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/10 19:35:18 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				index_i;
	unsigned int	index_j;

	index_i = 0;
	while (dest[index_i] != '\0')
		index_i++;
	index_j = 0;
	while (index_j < nb && src[index_j] != '\0')
	{
		dest[index_i] = src[index_j];
		index_i++;
		index_j++;
	}
	dest[index_i] = '\0';
	return (dest);
}
