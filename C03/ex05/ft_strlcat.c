/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:36:21 by tel-bouh          #+#    #+#             */
/*   Updated: 2021/08/17 15:03:26 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	unsigned int	temp;

	i = ft_strlen(dest);
	len = ft_strlen(src);
	temp = i;
	j = 0;
	while (i + 1 < size && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < i)
		return (len + size);
	return (len + temp);
}
#include <stdio.h>
#include <string.h>

int	main ()
{
	char dest[20] = "hassan";
	char dest1[20] = "hassan";
	char dest2[20] = "hassan";
	char dest3[20] = "hassan";
	char dest4[20] = "hassan";
	char dest5[20] = "hassan";
	char dest6[20] = "hassan";
	char dest7[20] = "hassan";
	char dest8[20] = "hassan";
	char dest9[20] = "hassan";
	char dest10[20] = "hassan";
	char dest11[20] = "hassan";
	char dest12[20] = "hassan";
	char dest13[20] = "hassan";
	char dest14[20] = "hassan";
	char dest15[20] = "hassan";
	char dest16[20] = "hassan";
	char dest17[20] = "hassan";
	char dest18[20] = "hassan";
	char dest19[20] = "hassan";
	char dest20[20] = "hassan";
	char dest21[20] = "hassan";
	char dest22[20] = "hassan";
	char dest23[20] = "hassan";
	char src[10] = "moha";
	printf("%u\n", ft_strlcat(dest, src, 0));
	printf("%lu\n", strlcat(dest1, src, 0));
	printf("%s\n", dest);
	printf("%u\n", ft_strlcat(dest2, src, 1));
	printf("%lu\n", strlcat(dest3, src, 1));
	printf("%s\n", dest2);
	printf("%u\n", ft_strlcat(dest4, src, 2));
	printf("%lu\n", strlcat(dest5, src, 2));
	printf("%s\n", dest4);
	printf("%u\n", ft_strlcat(dest6, src, 3));
	printf("%lu\n", strlcat(dest7, src, 3));
	printf("%s\n", dest6);
	printf("%u\n", ft_strlcat(dest8, src, 4));
	printf("%lu\n", strlcat(dest9, src, 4));
	printf("%s\n", dest8);
	printf("%u\n", ft_strlcat(dest10, src, 5));
	printf("%lu\n", strlcat(dest11, src, 5));
	printf("%s\n", dest10);
	printf("%u\n", ft_strlcat(dest12, src, 6));
	printf("%lu\n", strlcat(dest13, src, 6));
	printf("%s\n", dest12);
	printf("%u\n", ft_strlcat(dest14, src, 7));
	printf("%lu\n", strlcat(dest15, src, 7));
	printf("%s\n", dest14);
	printf("%u\n", ft_strlcat(dest16, src, 8));
	printf("%lu\n", strlcat(dest17, src, 8));
	printf("%s\n", dest16);
	printf("%u\n", ft_strlcat(dest18, src, 9));
	printf("%lu\n", strlcat(dest19, src, 9));
	printf("%s\n", dest18);
	printf("%u\n", ft_strlcat(dest20, src, 10));
	printf("%lu\n", strlcat(dest21, src, 10));
	printf("%s\n", dest20);
	printf("%u\n", ft_strlcat(dest22, src, 11));
	printf("%lu\n", strlcat(dest23, src, 11));
	printf("%s\n", dest22);
	return (0);
}
